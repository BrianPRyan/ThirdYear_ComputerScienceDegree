//LAB 1 ******ALL COMMENTS ADDED BY BRIAN RYAN (K00202212) 22ND SEPTEMBER 2016******
#include <stdio.h>
#include <stdlib.h>			//Lines 2 - 9 are the include files, these header files 
#include <string.h>			//declare the standard functions and constants of the API
#include <sys/types.h>		//we utilise our own include file here practical.h, which has
#include <sys/socket.h>		//prototypes for functions
#include <netinet/in.h>
#include <arpa/inet.h>
#include "Practical.h"
//Allow max 5 connections and then refuse any more. This is an int value which is used later
static const int MAXPENDING = 5; //Maximum outstanding connection requests
//run on command line = "echoSvr <port>";argc = 2 command and parameter 
int main(int argc, char *argv[]) {//argv[0] = echoSvr and argv[1] = <port>

  if (argc != 2) //Test for correct number of arguments
    DieWithUserMessage("Parameter(s)", "<Server Port>");
	//convert port number from string to numeric value using atoi()
  in_port_t servPort = atoi(argv[1]); // First arg:  local port ascii to integer

  //Create socket for incoming connections
  int servSock; // Socket descriptor for server
  if ((servSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)//stream socket just like the client
    DieWithSystemMessage("socket() failed");//If it fails message is printed

  //Construct local address structure
  struct sockaddr_in servAddr;// Local address; internet socket address structure
  memset(&servAddr, 0, sizeof(servAddr));//memset zero out any parts not explicitly set in the structure
  servAddr.sin_family = AF_INET;//setting the IPv4 address family, Internet address and port number
  //we let the system pick any address by specifying the wildcard address inaddr_any
  //before setting the address and port we convert both to network byte order using htonl()
  servAddr.sin_addr.s_addr = htonl(INADDR_ANY);//Any incoming interface; host to network long[integer]
  servAddr.sin_port = htons(servPort);//Local port; host to network short[integer]

  //Bind to the local address & cast servaddr as generic sockaddress struct
  //client specifies server address & server specifies its own address to bind(), this they must agree upon
  //to connect to each other
  if (bind(servSock, (struct sockaddr*) &servAddr, sizeof(servAddr)) < 0)
    DieWithSystemMessage("bind() failed");//If it fails to bind this message is printed

  //Mark the socket so it will listen for incoming connections
  //listen tells the TCP implementation to allow incoming connections
  if (listen(servSock, MAXPENDING) < 0)//our int value from earlier gets used if less than zero listen fails
    DieWithSystemMessage("listen() failed");//If it fails to listen this message is printed

  for (;;) {//Run forever but only until MAXPENDING has not been reached above this line
    struct sockaddr_in clntAddr;//Client address contains the address and port number of connecting client
    //Set length of client address structure (in-out parameter)
    socklen_t clntAddrLen = sizeof(clntAddr); 
												
	//Wait for a client to connect
    int clntSock = accept(servSock, (struct sockaddr *) &clntAddr, &clntAddrLen);//Accept() 
	//function extracts the first connection on the queue which is in pending connections 
	//then it creates new socket with same socket type, protocol, address family as the specified socket
    if (clntSock < 0)
      DieWithSystemMessage("accept() failed");//If it fails a message is printed

    //clntSock is connected to a client!
	//report connected client details
    char clntName[INET_ADDRSTRLEN]; //String to contain client address
    if (inet_ntop(AF_INET, &clntAddr.sin_addr.s_addr, clntName,//inet_ntop() is the inverse of inet_pton()
        sizeof(clntName)) != NULL)//takes binary representation of client address and convert to dotted quad
      printf("Handling client %s/%d\n", clntName, ntohs(clntAddr.sin_port));//print client deatails
    else
      puts("Unable to get client address");//error message printed if cant resolve the client address

    HandleTCPClient(clntSock);//This takes care of the application protocol Factored out the function that
	//deals with the echo part of our server, this function receives data on the given socket and gives 
	//data back on the sane socket - code is found in TCPServerUtility.c
  }
  //NOT REACHED
}
