#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include "segment.h"
#include "pld.h"
#include "debug.h"
#include "socketSend.h"

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

void initArgv(int argc, char* argv[]);
void cnm(header synHeader);
void connectionEstablish();

int main(int argc, char* argv[]){
	initArgv(argc, argv);
	socketSendInit(recvIp, recvPort);



	connectionEstablish();

	// FILE *fp;
	// int ch;
	// if((fp = fopen(fileName, "r")) == NULL){
	// 	printf("Can't open file %s\n", fileName);
	// 	exit(EXIT_FAILURE);
	// }
	// while((ch = getc(fp)) != EOF){
	// 	putc(ch, stdout);
	// }

	// fclose(fp);

	return 0;

}

void connectionEstablish(){
	header synHeader;
	synHeader.SYN = 1;
	synHeader.ACK = 0;
	segment synSeg;
	synSeg.head = synHeader;
	//synSeg.data = NULL;
	sendSegment(synSeg);
}

void initArgv(int argc, char* argv[]){
	//init the variables
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
}


void cnm(header synHeader){
	int sockfd;
	struct sockaddr_in receiverAddr;

	if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1){
		printf("socket error\n");
		return;
	}

	receiverAddr.sin_family = AF_INET;
	receiverAddr.sin_port = htons(1324);
	receiverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	// if(connect(sockfd, (struct sockaddr *) &receiverAddr, sizeof(receiverAddr)) == -1){
	// 	printf("connect error\n");
	// 	return;
	// }

	// send(sockfd, &synHeader, sizeof(synHeader), 0);
	sendto(sockfd, "hahahaha", 8, 0, (void *)&receiverAddr, sizeof(receiverAddr));
	printf("send synHeader = %x", synHeader);
	close(sockfd);
	return;
}