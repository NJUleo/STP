#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include "segment.h"
#include "pld.h"

static char* fileName;
static char* recvIp;
static int recvPort;
static double pDrop;
static int seedDrop;
static int maxDelay;
static double pDelay;
static int seedDelay;
static int MSS;
static int MWSRate;
static int initalTimeOut;
void cnm(header head);
int main(int argc, char* argv[]){
	if(argc != 12){
		printf("error: argc = %d", argc);
	}
	fileName = argv[1];
	recvIp = argv[2];
	recvPort = atoi(argv[3]);
	pDrop = atof(argv[4]);
	seedDrop = atoi(argv[5]);
	maxDelay = atoi(argv[6]);
	pDelay = atof(argv[7]);
	seedDelay = atoi(argv[8]);
	MSS = atoi(argv[9]);
	MWSRate = atoi(argv[10]);
	initalTimeOut = atoi(argv[11]);
	printf("fileName = %s, recvIp = %s, recvPort = %d, pDrop = %f\n", fileName, recvIp, recvPort, pDrop);
	return 0;
	header head;
	head.ACK = 1;
	cnm(head);
	//printf("%x\n", head);
	return 0;

}

void cnm(header head){
	int sockfd;
	struct sockaddr_in server;

	if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1){
		printf("socket error\n");
		return;
	}

	server.sin_family = AF_INET;
	server.sin_port = htons(1324);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");

	if(connect(sockfd, (struct sockaddr *) &server, sizeof(server)) == -1){
		printf("connect error\n");
		return;
	}

	send(sockfd, &head, sizeof(head), 0);
	printf("send head = %x", head);
	return;
}