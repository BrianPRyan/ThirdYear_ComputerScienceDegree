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
#include <time.h>


int main()
{
	//Variables 
	char message[1024] ;
	char request[256];
	char type[256];
	char uname[256];
	char endpi[256];
	char * string;
	socklen_t addr_size;
	int server_sock, x=0, r=0, d=0, dot_dash=0, i=0;
	int client_sock, arg, strl;
	int received, rand_a, errorCode=0;
	char randomDigits[20]="";
	char randomDigitsOne[20]="";

	//Socket Open
	server_sock = socket(AF_INET, SOCK_STREAM, 0);

	//Construct local address structure
	struct sockaddr_storage server_storage;
	addr_size = sizeof(server_storage);//Setting size of storage for struct(address)
	struct sockaddr_in server;//Local address; internet socket address structure
	server.sin_family = AF_INET;//Setting the internet address family
	server.sin_port = htons(48031);//Binding to port 48031 
	server.sin_addr.s_addr = INADDR_ANY;//Any incoming interface

	//Socket Bind with port number
	bind(server_sock, (struct sockaddr*) &server, sizeof(server));

	//Socket listen on binded port, waits for connection.
	listen(server_sock, 5);

	//Socket Wait for client confirmation ( handshake)
	client_sock = accept(server_sock, (struct sockaddr *) &server_storage, &addr_size);

	//Wait for message from client. 
	received = recv(client_sock, &message, sizeof(message), 0); 
	printf("\nRcvd Message1 from Client : %s", message);

	//Message format checks.
	d = sizeof(message);
	string = strtok (message," ");
	strcpy(request, string);
	arg = 2;
	strl=0;
	while (string != NULL)
	{
		string = strtok (NULL, " ");
		if ( arg == 2)
		{
			strcpy(type, string);
			//Check if message is of different type than type0.
			if (strcmp("type0", type ))
			{
				errorCode = 1;
				arg = 9;
				break;
			}
		}
		if ( arg == 3)
		{
			//Check if username is longer than 64 chars.
			strcpy(uname, string);
			if ( strlen(uname) > 64 )
			{
				arg = 9;
				errorCode = 2;
				break;
			}
		}
		if ( arg == 4)
		{
			strcpy(endpi, string);
			strl = strlen(endpi) - 2;
			endpi[strl] = '\0';

			//Check if end point identifier is not in format.
			for(i=0; endpi[i]!='\0'; i++)
			{
				if(endpi[i]=='.' || endpi[i]=='-' )
					dot_dash++;
			}
                        if ( 4 != dot_dash)
			{
				arg = 9;
				errorCode = 3;
				break;
			}

		}
		arg++;
	}

        //Check if there was any error.
	if ( arg !=6 )
	{
		sprintf(message,"Message from client is not in proper format. errorCode:%d.", errorCode);
		//Send Error to client.
		send(client_sock, message, sizeof(message), 0);
		printf("\nSent Error : %s", message);
	}
	else
	{
		//Create message :greeting line
		sprintf(message,"hello %s, welcome to the netsvr",endpi);
	
		//Send The greeting line
		send(client_sock, message, sizeof(message), 0);
		printf("\nSent Message2 greeting to client : %s\n", message);

		//Create Random string of digits and send to client
		srand(time(NULL));
		rand_a = rand() % 20;

		//Loop "rand_a" times: to generate random digits 
		for (x = 0 ; x<=rand_a ; x++)
			sprintf( randomDigits + strlen(randomDigits), "%d", (rand() % 9));

		//Send Random Number to Client.
		send(client_sock, randomDigits, x+1, 0);
		printf("\nSend Message3 Random number to client : %s\n", randomDigits);

		//Recv number of bytes sent by the server.
		received = recv(client_sock, &message, sizeof(message), 0); 
		printf("\nRcvd Message4 count of digits from server : %s\n", message);

		//Loop "rand_a" times: to generate random digits 
		for (x = 0 ; x<=rand_a ; x++)
			sprintf( randomDigitsOne + strlen(randomDigitsOne), "%d", (rand() % 9));

		//Prepare final message
		sprintf(message,"OK ");
	
		//Send OK and cookie to Client.	
		send(client_sock, message, sizeof(message), 0);
		send(client_sock, randomDigitsOne, x+1, 0);
		printf("\nSend final message & cookie to client: %s", message);
		printf("%s\n", randomDigitsOne);

	}

	//Close sockets
	close(server_sock);
	close(client_sock);

	return 0;
}
