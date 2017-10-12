//LAB 1 ******ALL COMMENTS ADDED BY BRIAN RYAN (K00202212) 15TH SEPTEMBER 2016******
#include <stdio.h>
#include <stdlib.h>
#include <string.h>				//Lines 2 - 10 are the include files, these header files 
#include <unistd.h>				//declare the standard functions and constants of the API
#include <sys/types.h>			//we utilise our own include file here practical.h, which has
#include <sys/socket.h>			//prototypes for functions
#include <netinet/in.h>
#include <arpa/inet.h>
#include "Practical.h"

int main(int argc, char *argv[]) { //declare main function and test for args below 
									//terminate program if args are not valid
  if (argc < 3 || argc > 4) //Test for correct number of arguments Line 14 - 16, if arguments not valid 
    DieWithUserMessage("Parameter(s)",	//die with user message is called and message gets printed
        "<Server Address> <Echo Word> [<Server Port>]");

  char *servIP = argv[1]; //Line 18 - 22 parameter passing, First arg: server IP address (dotted quad)
  char *echoString = argv[2]; //Second arg: string to echo, message we want the server to echo back to us

  //Third arg (optional): server port (numeric) 7 is well-known echo port which is only used
  in_port_t servPort = (argc == 4) ? atoi(argv[3]) : 7;//if no port is defined. atoi() is function that
													   //converts a string to an int
  //Line 24 - 27 Create a reliable stream socket using TCP
  int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//socket()takes 3 parameters, the address family IPv4 
  if (sock < 0)		//type of socket STREAM and the protocol to be used TCP
    DieWithSystemMessage("socket() failed");//if socket fails it returns a -1 therefore message gets printed  

  //Line 29 - 44 Construct the server address structure
  struct sockaddr_in servAddr;//sock-addr_in structure is defined to be a “container” for serv address & port
  memset(&servAddr, 0, sizeof(servAddr)); //memset zero out any parts not explicitly set in the structure
  servAddr.sin_family = AF_INET;  //setting the IPv4 address family, Internet address and port number
  //inet_pton converts string representation of servers internet address from dotted quad into 32 bit binary
  int rtnVal = inet_pton(AF_INET, servIP, &servAddr.sin_addr.s_addr);
  if (rtnVal == 0)//if pton function fails error messages below get printed
    DieWithUserMessage("inet_pton() failed", "invalid address string");
  else if (rtnVal < 0)
    DieWithSystemMessage("inet_pton() failed");
  servAddr.sin_port = htons(servPort);//hton(host to network short)ensures binary value is formatted
										//as required by the API
  //connect() function establishes a connection between the given socket and the one
  //identified by the address and port in the sockaddr_in structure
  if (connect(sock, (struct sockaddr *) &servAddr, sizeof(servAddr)) < 0)//cast pointer of sockaddr_in to
    DieWithSystemMessage("connect() failed");//generic type sockaddr because sockets API is generic and 
											//size of address data struct must be supplied
											
  /*47-53.Send data*/size_t echoStringLen = strlen(echoString);//find length of string and save to use later
  //A pointer to the echo string is passed to the send()call, address of first byte & how many bytes to send
  ssize_t numBytes = send(sock, echoString, echoStringLen, 0);//all we need to know. Send() returns the num
  if (numBytes < 0)//of bytes sent if successful and -1 otherwise
    DieWithSystemMessage("send() failed");//this error checking will probably never get called here
  else if (numBytes != echoStringLen)//in some context in other programs it may so good practice to 
    DieWithUserMessage("send()", "sent unexpected number of bytes");//use the error checking
	
	//Line 58 - 70 Receiving data
  // Receive the same string back from the server... TCP is a byte stream protocol so we must repeatedley
  //receive bytes until we have received as many as we sent
  unsigned int totalBytesRcvd = 0; //Count of total bytes received
  fputs("Received: ", stdout);     //Setup to print the echoed string
  while (totalBytesRcvd < echoStringLen) {
    char buffer[BUFSIZE]; // I/O buffer... Receive up to the buffer size (minus 1 to leave space for
    numBytes = recv(sock, buffer, BUFSIZE - 1, 0);//a null terminator) bytes from the sender
    if (numBytes < 0)//If we reach here and enter this IF statement the app at the other end closed the
      DieWithSystemMessage("recv() failed");//TCP connection
    else if (numBytes == 0)
      DieWithUserMessage("recv()", "connection closed prematurely");
    totalBytesRcvd += numBytes; //Keep tally of total bytes received
    buffer[numBytes] = '\0';//Terminate the string with null character at end of each chunk of data so that
    fputs(buffer, stdout);//it can be treated like a string by fputs() where we print the echo buffer
  }

  fputc('\n', stdout); //When all bytes are received we exit loop and print a newline
  //terminate connection using the close() function and exit program
  close(sock);
  exit(0);
}
