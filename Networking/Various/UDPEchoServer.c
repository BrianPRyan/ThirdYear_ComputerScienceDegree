#include <stdlib.h>			//LAB 3 ******ALL COMMENTS ADDED BY BRIAN RYAN (K00202212) 27TH NOVEMBER 2016******
#include <string.h>
#include <sys/types.h>			//Lines 1 - 6 are the include files, these header files 
#include <sys/socket.h>			//declare the standard functions and constants of the API
#include <netdb.h>				//we utilise our own include file here practical.h, which has
#include "Practical.h"			//prototypes for functions
//run on command line = "echoSvr <port>";argc = 2 command and parameter 
int main(int argc, char *argv[]) {//argv[0] = echoSvr and argv[1] = <port>

  if (argc != 2) // Test for correct number of arguments
    DieWithUserMessage("Parameter(s)", "<Server Port/Service>");//parameters that need to be passed in

  char *service = argv[1]; // First arg:  local port/service

  // Construct the server address structure
  struct addrinfo addrCriteria;                   // Criteria for address
  memset(&addrCriteria, 0, sizeof(addrCriteria)); // Zero out structure
  addrCriteria.ai_family = AF_UNSPEC;             // Any address family
  addrCriteria.ai_flags = AI_PASSIVE;             // Accept on any address/port
  addrCriteria.ai_socktype = SOCK_DGRAM;          // Only datagram socket
  addrCriteria.ai_protocol = IPPROTO_UDP;         // Only UDP socket

  struct addrinfo *servAddr; // List of server addresses
  int rtnVal = getaddrinfo(NULL, service, &addrCriteria, &servAddr);
  if (rtnVal != 0)
    DieWithUserMessage("getaddrinfo() failed", gai_strerror(rtnVal));

  // Create socket for incoming connections NOTE:(different from TCP) no need to listen() because there is no connection setup
  int sock = socket(servAddr->ai_family, servAddr->ai_socktype,//socket is ready to receive messages as soon
      servAddr->ai_protocol);//as it has an address
  if (sock < 0//error checkig on socket creation
    DieWithSystemMessage("socket() failed");

  // Bind to the local address
  if (bind(sock, servAddr->ai_addr, servAddr->ai_addrlen) < 0)
    DieWithSystemMessage("bind() failed");

  // Free address list allocated by getaddrinfo()
  freeaddrinfo(servAddr);
	//run forever iteratively handling incoming echo requests
  for (;;) { // Run forever
    struct sockaddr_storage clntAddr; // Client address
    // Set Length of client address structure (in-out parameter)
    socklen_t clntAddrLen = sizeof(clntAddr);

    // Block until receive message from a client
    char buffer[MAXSTRINGLENGTH]; // I/O buffer
    // Size of received message
    ssize_t numBytesRcvd = recvfrom(sock, buffer, MAXSTRINGLENGTH, 0,//calling recvfrom() immediateley we do not need a new
        (struct sockaddr *) &clntAddr, &clntAddrLen);//socket for each client.. different to TCP
    if (numBytesRcvd < 0)//error checking echo request
      DieWithSystemMessage("recvfrom() failed");
	//code to print out th eIP address and port number of the client we are receiving from
    fputs("Handling client ", stdout);//recvfrom() puts address of client into clntAddr
    PrintSocketAddress((struct sockaddr *) &clntAddr, stdout);
    fputc('\n', stdout);

    // Send received datagram back to the client
    ssize_t numBytesSent = sendto(sock, buffer, numBytesRcvd, 0,//sednto() transmits the data in buffer back to the address specified by 
        (struct sockaddr *) &clntAddr, sizeof(clntAddr));//clntAddr. We only need a single send and recv unlike TCP
    if (numBytesSent < 0)//error checking on sendTo()
      DieWithSystemMessage("sendto() failed)");//diewithmessage gets printed if numbytes less than zero
    else if (numBytesSent != numBytesRcvd)//diewithmessage gets printed if numbytes not equal to btes received
      DieWithUserMessage("sendto()", "sent unexpected number of bytes");
  }
  // NOT REACHED
}
