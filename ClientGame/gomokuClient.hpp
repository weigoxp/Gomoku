

#ifndef GOMOKU_CLIENT_HPP
#define GOMOKU_CLIENT_HPP

extern "C"{
	#include <sys/socket.h>
	#include <sys/types.h>
	#include <unistd.h>
	#include <netinet/in.h>
	#include <arpa/inet.h>
}

#include <cstring>
#include <iostream>

class GomokuClient{
public:
	GomokuClient(int i_ServerSock) : ServerSock(i_ServerSock) {}
	
	~GomokuClient() {}
		
	void sendCoords(int& x, int& y);//send location of newly placed piece
	
	void receiveCoords(int& x, int& y);//receive location of newly placed piece

private:
	
	int ServerSock;//socket file descriptor for server
};
#endif
