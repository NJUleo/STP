#include <stdio.h>
#include "debug.h"
void printHeader(header head){
    printf("\theader = %x\n", head);
    printf("\tACK = %x\n", head.ACK);
    printf("\tSYN = %x\n", head.SYN);
}
