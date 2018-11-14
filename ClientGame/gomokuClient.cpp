

#include "gomokuClient.hpp"

void GomokuClient::sendCoords(int& x, int& y){
	//convert ints to network ints (int serialization)
	x= htonl(x);
	y= htonl(y);
	//send coordinates x and y
	int bytesSentx= send(ServerSock, (const void*)&x, sizeof(int), 0);
	int bytesSenty= send(ServerSock, (const void*)&y, sizeof(int), 0);	
//	while(bytesSent < boardSize){
//		boardPointer += bytesSent;
//		boardSize -= bytesSent;
//		bytesSent= send(ServerSock, (const void*)&x, xSize, 0);
//	}
}

void GomokuClient::receiveCoords(int& x, int& y){
	//receive coordinates
	int bytesRecvx= recv(ServerSock, (void*)&x, sizeof(int), 0);
	int bytesRecvy= recv(ServerSock, (void*)&y, sizeof(int), 0);
	//convert ints back to host format
	x= ntohl(x);
	y= ntohl(y);
//	while(bytesRecv < boardSize){
//		boardPointer += bytesRecv;
//		boardSize -= bytesRecv;
//		bytesRecv= recv(ServerSock, (void*)boardPointer, boardSize, 0);
//	}
}
