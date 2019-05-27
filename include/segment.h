#ifndef __SEGMENT_H__
#define __SEGMENT_H__
typedef unsigned int uint32_t;

typedef struct{
	uint32_t srcPort :16;
	uint32_t destPort :16;
	uint32_t seqNum;
	uint32_t ackNum;
	uint32_t dataOffset :4;
	uint32_t reserved :3;
	uint32_t NS :1;
	uint32_t CWR :1;
	uint32_t ECE :1;
	uint32_t URG :1;
	uint32_t ACK :1;
	uint32_t PSH :1;
	uint32_t RST :1;
	uint32_t SYN :1;
	uint32_t FIN :1;
	uint32_t windowSize :16;
	uint32_t checkSum :16;
	uint32_t urgentPointer :16;
} header;

typedef struct{
	header head;
	char data[1000];
} segment;
#endif