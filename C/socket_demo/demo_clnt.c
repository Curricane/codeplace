#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdio.h>

int main()
{
    // 创建套接字
    int skt_clnt = socket(AF_INET, SOCK_STREAM, 0);
    // 服务器的ip、端口
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(1234);
    
    // 连接服务器
    connect(skt_clnt, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    // 读取服务器传回的数据
    char buffer[40];
    read(skt_clnt, buffer, sizeof(buffer) - 1);

    printf("Message from server: %s\n", buffer);

    // 关闭套接字
    close(skt_clnt);
}