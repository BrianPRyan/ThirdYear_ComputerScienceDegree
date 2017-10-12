//Types & Socket Functions/API
#include <sys/types.h>
#include <sys/socket.h>

//Network Library
#include <netinet/in.h>
#include <arpa/inet.h>

//Standard Libaries
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


//Digit Count function
int digitCount(char* string)
{
	int count=0;
	for(;string[count] != '\0';count++)
		if (!isdigit(string[count]))//using isDigit to count
			++count;
	return count;
}

int main()
{
	//Variables
	int ascii_count=0;
	char logo[] = "netsrv ";
	char user[] = "BpRyan ";
	char type[] = "type0 ";
	char str[100];

	//Buffer Space, addresses and size of structure 
	char message[96];
	char rmessage[1024];

	//Construct local address structure
	int size_m = sizeof(message);
	memset(message, '\0', size_m+1);
	struct sockaddr_in server, foo;
	int size = sizeof(struct sockaddr);
	int net_sock;

	//Create Socket
	net_sock = socket(AF_INET, SOCK_STREAM, 0);
	if(net_sock == -1)
		printf("Socket : Error\n");

	//Server address information
	server.sin_family = AF_INET;
	server.sin_port = htons(48031);//Converts to correct network type format
	server.sin_addr.s_addr = INADDR_ANY;

	//Socket connect to server
	if(connect(net_sock, (struct sockaddr*) &server, sizeof(server)) == -1)
		printf("Connection : Failed\n");

        //Get my machine name.
	int sockname = getsockname(net_sock, (struct sockaddr *) &foo, &size);

	//Message preparation.
	sprintf(message, "netsvr type0 BpRyan %s-%d\r\n", inet_ntoa(foo.sin_addr), ntohs(foo.sin_port));

	/*TESTING FOR ERROR CHECKING ON FORMAT.
	sprintf(message, "netsvr type0 BpRyan 123456789987654321159753258456 %s-%d\r\n", inet_ntoa(foo.sin_addr), ntohs(foo.sin_port));*/

	//Send Message1
	send(net_sock, &message, sizeof(message), 0);
	printf("\nSent Message1 to Server : %s", message);

	//Received 1st response back from server
	memset(rmessage, '\0', sizeof(rmessage));
	recv(net_sock, rmessage, sizeof(rmessage), 0);

        //Check if this is error message. 
        if (strncmp(rmessage,"hello ",6))
        {
		printf("\nRcvd: Error : Message was not in proper format\n");
		close(net_sock);
		return 0;
	}

	printf("\nRcvd Message2 from Server: %s\n", rmessage);

	//Recieved 2nd response back from server
	memset(rmessage, '\0', sizeof(rmessage));
	recv(net_sock, rmessage, sizeof(rmessage), 0);
	printf("\nRcvd random number message3 from Server: %s\n", rmessage);
	ascii_count += digitCount(rmessage);

	//send message to server with number of bytes
	memset(rmessage, '\0', sizeof(rmessage));
	sprintf(rmessage,"%d",ascii_count);
	send(net_sock, &rmessage, sizeof(rmessage), 0);
	printf("\nSent Message4 count of digits to server: %s\n", rmessage);

	//call shutdown before the server sends final message and cookie
	int shutdown ();

	//Receive final message 'OK' from server
	memset(rmessage, '\0', sizeof(rmessage));
	recv(net_sock, rmessage, sizeof(rmessage), 0);
	printf("\nRcvd OK and Cookie from server: %s", rmessage);

	//Receive cookie from server
	memset(rmessage, '\0', sizeof(rmessage));
	recv(net_sock, rmessage, sizeof(rmessage), 0);
	printf("%s\n", rmessage);

	return 0;
}
