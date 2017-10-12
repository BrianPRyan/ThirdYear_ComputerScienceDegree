//LAB 2 ******ALL COMMENTS ADDED BY BRIAN RYAN (K00202212) 13TH October 2016******
#include <stdio.h>
#include <stdlib.h>				//Lines 2 - 6 are the include files, these header files 
#include <string.h>				//declare the standard functions and constants of the API
#include <netdb.h>
#include "Practical.h"

int main(int argc, char *argv[]) {//declare main function and test for args below 

  if (argc != 3) // Test for correct number of arguments if arguments not valid die with user message
    DieWithUserMessage("Parameter(s)", "<Address/Name> <Port/Service>");//is called and message gets printed
	//Application setup and parameter parsing **Line 10 - 14**
  char *addrString = argv[1];   // Server address/name
  char *portString = argv[2];   // Server port/service

  // Tell the system what kind(s) of address info we want.. //Declare and initialize addrinfo structure
  struct addrinfo addrCriteria;                   // Criteria for address match 
  memset(&addrCriteria, 0, sizeof(addrCriteria)); // Zero out structure
  //Set address family.. AF_UNSPEC allows return address to come from any family
  addrCriteria.ai_family = AF_UNSPEC;             // Any address family
  addrCriteria.ai_socktype = SOCK_STREAM;         // Set the socket type.. Only stream sockets
  addrCriteria.ai_protocol = IPPROTO_TCP;         // Set the IP protocol, we want Only TCP protocol

  // Get address(es) associated with the specified name/service
  struct addrinfo *addrList; // Declare pointer for head of link list Holder for list of addresses returned
  //Modify servAddr contents to reference linked list of addresses
  //Pass the desired hostname, port, and the constraints encoded in the addrCriteria structure
  int rtnVal = getaddrinfo(addrString, portString, &addrCriteria, &addrList);
  if (rtnVal != 0)//If getaddrinfo() is successful it returns zero if not the function gai_strerror() 
				  //Returns a character string error message explaining the given error return value
    DieWithUserMessage("getaddrinfo() failed", gai_strerror(rtnVal));

  // Display returned addresses.. Iterate over the linked list of addresses, printing each to the console.
  for (struct addrinfo *addr = addrList; addr != NULL; addr = addr->ai_next) {
    PrintSocketAddress(addr->ai_addr, stdout);
    fputc('\n', stdout);
  }
  //Free addrinfo allocated in getaddrinfo() to clear up memory and prevent memory leaks
  freeaddrinfo(addrList);

  exit(0);
}
