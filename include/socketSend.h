#ifndef __SOCKETSEND_H__
#define __SOCKETSEND_H__
void socketSendInit(char* recvIP, int recvPort);
int sendSegment(segment seg);
#endif