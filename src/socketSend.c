#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include "segment.h"
#include "debug.h"
static int sockfd = -1;
static struct sockaddr_in receiverAddr;
void socketSendInit(char* recvIP, int recvPort){

	if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1){
		printf("socket error\n");
		return;
	}

	receiverAddr.sin_family = AF_INET;
	receiverAddr.sin_port = htons(recvPort);
	receiverAddr.sin_addr.s_addr = inet_addr(recvIP);
}
int sendSegment(segment seg){
    if(sockfd == -1){
        printf("can't send before socket init");
        exit(EXIT_FAILURE);
    }
    sendto(sockfd, (void *)&seg, sizeof(seg), 0, (void *)&receiverAddr, sizeof(receiverAddr));
	printHeader(seg.head);
    return 0;
}
