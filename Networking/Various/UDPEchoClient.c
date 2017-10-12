#include <stdio.h>		//LAB 3 ******ALL COMMENTS ADDED BY BRIAN RYAN (K00202212) 27TH NOVEMBER 2016******
#include <stdlib.h>
#include <string.h>		//Lines 1 - 7 are the include files, these header files 
#include <unistd.h>		//declare the standard functions and constants of the API
#include <sys/socket.h>	//we utilise our own include file here practical.h, which has
#include <netdb.h>		//prototypes for functions
#include "Practical.h"

int main(int argc, char *argv[]) {	//declare main function and test for args below 
									//terminate program if args are not valid
  if (argc < 3 || argc > 4) // Test for correct number of arguments
    DieWithUserMessage("Parameter(s)",//if arguments not valid die with user message is called and message gets printed
        "<Server Address/Name> <Echo Word> [<Server Port/Service>]");

  char *server = argv[1];     // First arg: server address/name
  char *echoString = argv[2]; // Second arg: word to echo

  size_t echoStringLen = strlen(echoString);//restrict the size of echo message
  if (echoStringLen > MAXSTRINGLENGTH) // Check input length
    DieWithUserMessage(echoString, "string too long");//die with user message is called and message gets printed

  // Third arg (optional): server port/service
  char *servPort = (argc == 4) ? argv[3] : "echo";

  // Tell the system what kind(s) of address info we want
  struct addrinfo addrCriteria;                   // Criteria for address match
  memset(&addrCriteria, 0, sizeof(addrCriteria)); // Zero out structure
  addrCriteria.ai_family = AF_UNSPEC;             // Any address family
  // For the following fields, a zero value means "don't care"
  addrCriteria.ai_socktype = SOCK_DGRAM;          // Only datagram sockets
  addrCriteria.ai_protocol = IPPROTO_UDP;         // Only UDP protocol

  // Get address(es)
  struct addrinfo *servAddr; // List of server addresses
  int rtnVal = getaddrinfo(server, servPort, &addrCriteria, &servAddr);
  if (rtnVal != 0)//error checking te return value is correct, it must come ack as postive 1
    DieWithUserMessage("getaddrinfo() failed", gai_strerror(rtnVal));//if it fails error message is sent

  // Create a datagram/UDP socket
  int sock = socket(servAddr->ai_family, servAddr->ai_socktype,
      servAddr->ai_protocol); // Socket descriptor for client, no need to connect() as this is UDP
  if (sock < 0)
    DieWithSystemMessage("socket() failed");//if socket fails it returns a -1 therefore message gets printed

  // Send the string to the server
  ssize_t numBytes = sendto(sock, echoString, echoStringLen, 0,
      servAddr->ai_addr, servAddr->ai_addrlen);//Sendto() returns the num of bytes sent if successful and -1 otherwise
  if (numBytes < 0)//error chceking the num of bytes sent
    DieWithSystemMessage("sendto() failed");
  else if (numBytes != echoStringLen)//if num of bytes do not equal the set length
    DieWithUserMessage("sendto() error", "sent unexpected number of bytes");//error message is sent

  // Receive a response

  struct sockaddr_storage fromAddr; // Source address of server
  // Set length of from address structure (in-out parameter)
  socklen_t fromAddrLen = sizeof(fromAddr);
  char buffer[MAXSTRINGLENGTH + 1]; // I/O buffer, 1 byte bigger to allow null byte to terminate string
  numBytes = recvfrom(sock, buffer, MAXSTRINGLENGTH, 0,
      (struct sockaddr *) &fromAddr, &fromAddrLen);
  if (numBytes < 0)//If we reach here and enter this IF statement the app at the other end closed
    DieWithSystemMessage("recvfrom() failed");
  else if (numBytes != echoStringLen)
    DieWithUserMessage("recvfrom() error", "received unexpected number of bytes");

  // Verify reception from expected source
  if (!SockAddrsEqual(servAddr->ai_addr, (struct sockaddr *) &fromAddr))//error handling, check message source
    DieWithUserMessage("recvfrom()", "received a packet from unknown source");

  freeaddrinfo(servAddr);//Using function from getaddressinfo()
  //print the received string
  buffer[echoStringLen] = '\0';     // Null-terminate received data
  printf("Received: %s\n", buffer); // Print the echoed string
  //wrap up close socket
  close(sock);
  exit(0);
}
