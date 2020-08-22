

#ifndef __NET_H
#define __NET_H


#include<stdio.h> //printf
#include<string.h> //memset
#include<stdlib.h> //for exit(0);
#include<sys/socket.h>
#include<errno.h> //For errno - the error number
#include<netdb.h>	//hostent
#include<arpa/inet.h>

#include "defs.h"

// ip为传出参数
BOOL hostname_to_ip(const char *hostname, char *ip);

#endif
