#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "defs.h"
#include "util.h"
#include "net.h"

int main(int argc, char** argv) {
    int sockfd;
    struct sockaddr_in  servaddr;
    int port = -1;
    char *host = NULL;

    if (argc != 3) {
        printf("usage: %s ip port\n", argv[0]);
        return 0;
    }
    host = my_str_trim(argv[1]);
    port = atoi(argv[2]);

    char ip[64];
    char *addr = host;
    if (!hostname_to_ip(host, ip)) {
        printf("get ip of %s failed. use %s\n", host, host);
    } else {
        addr = ip;
    }

    // 创建 socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("create socket error: %s(errno: %d)\n", strerror(errno), errno);
        return 0;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if (inet_pton(AF_INET, addr, &servaddr.sin_addr) <= 0) {
        printf("inet_pton error for %s\n",argv[1]);
        return 0;
    }

    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        printf("connect to: %s:%d error\n", addr, port);
        return 0;
    }
    close(sockfd);
    return 0;
}
