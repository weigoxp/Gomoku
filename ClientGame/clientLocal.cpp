
extern "C"{
	#include <sys/types.h>
	#include <sys/socket.h>
	#include <netdb.h>
	#include <unistd.h>
}

#include <cstring>//for memset()
#include <iostream>
#include <string>
#include "gomokuClient.hpp"//to create and manipulate GomokuClient object
#include "clientLocal.hpp"//header file for this global function

void clientLocal(bool myTurn, int& x, int& y)
{
	/*set constant port and address*/
	const char port[]= "8097";
	//const char host[]= "ix-saucy.cs.uoregon.edu";
	
	addrinfo AI_hints;
	memset(&AI_hints, 0, sizeof(AI_hints));
	//initialize necessary parameters of AI
	AI_hints.ai_flags= AI_PASSIVE;
	AI_hints.ai_family= AF_UNSPEC;
	AI_hints.ai_socktype= SOCK_STREAM; 
	
	addrinfo* AI;//will hold address information
	
	//get possible addresses with specified parameters
	if(getaddrinfo((const char*)0, port, &AI_hints, &AI)!=0){
		std::cerr << "Error in finding addresses.\n";
	}

	int SockDescr;//socket file descriptor to be initialized
	for(addrinfo* currAddr= AI; currAddr!= (addrinfo*)0 ;currAddr= AI->ai_next){
		SockDescr= socket(currAddr->ai_family, currAddr->ai_socktype, currAddr->ai_protocol);
		if(SockDescr!=-1){//break if no error occurred
			break;
		}
	}
	
	if(connect(SockDescr, AI->ai_addr, AI->ai_addrlen)==-1){
		std::cerr << "Connection from client failed.\n";
	}
	freeaddrinfo(AI);

	//let server know if you are sending or receiving data
	int myTurn1=htonl((int)myTurn);
	send(SockDescr, (const void*)&myTurn1, sizeof(int), 0);
	GomokuClient gomoku(SockDescr);
	if(myTurn){//send matrix to other client via server
		gomoku.sendCoords(x, y);
	} else {//receive matrix from other client via server
		gomoku.receiveCoords(x, y);
	}
		
	if(close(SockDescr)==-1){
		std::cerr << "Error in closing socket with file descriptor " << SockDescr << " .\n";
	}
}
