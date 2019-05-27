#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "segment.h"
int main(int argc, char* argv[]){
    int sockfd;
    struct sockaddr_in server;
    header* head;
    char buf[500];

    if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1){
		printf("socket error\n");
		return 0;
	}

    server.sin_family = AF_INET;
	server.sin_port = htons(1324);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");

    int ret = bind(sockfd, (struct sockaddr *) &server, sizeof(server));
    if(ret < 0){
        printf("bind error\n");
        return 0;
    }

    recv(sockfd, buf, sizeof(header), 0);
    head = (header*)buf;
    printf("receive head.ack = %x, head = %x\n", head->ACK, *head);

    return 0;
    
}