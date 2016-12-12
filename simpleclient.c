#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <memory.h>

int main(int argc, char *argv[])
{
    int sockfd;
    int len;
    struct sockaddr_in address;
    int result;
    ///char ch = 'A';
    ///char ch[1024] = "GET index.html\n\n";
    char ch[1024] = "GET / HTTP/1.1\n\n";

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons(4001);
    len = sizeof(address);
    result = connect(sockfd, (struct sockaddr *)&address, len);

    if (result == -1)
    {
        perror("oops: client1");
        exit(1);
    }
    ///write(sockfd, &ch, 1);
    write(sockfd, ch, sizeof(ch));

    memset(ch, 0, 1024);
    ///read(sockfd, &ch, 1);
    read(sockfd, ch, 1024);
    printf("char from server = \n{\n%s}\n", ch);
    close(sockfd);
    exit(0);
}
