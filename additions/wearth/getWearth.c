#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#pragma comment(lib, "ws2_32.lib")

void get_weather_win(const char *city) {
    WSADATA wsa;
    SOCKET sockfd;
    struct sockaddr_in server;
    struct hostent *host;
    char request[512];
    char response[4096];
    
    // Инициализируем Winsock
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        printf("WSAStartup failed\n");
        return;
    }
    
    // Создаем сокет
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Socket creation failed\n");
        WSACleanup();
        return;
    }
    
    host = gethostbyname("localhost");
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    memcpy(&server.sin_addr.s_addr, host->h_addr, host->h_length);
    
    // Подключаемся
    if (connect(sockfd, (struct sockaddr*)&server, sizeof(server)) < 0) {
        printf("Connection failed\n");
        closesocket(sockfd);
        WSACleanup();
        return;
    }
    
    snprintf(request, sizeof(request),
        "GET /weather?city=%s HTTP/1.1\r\n"
        "Host: localhost:8080\r\n"
        "Connection: close\r\n"
        "\r\n", city);
    
    send(sockfd, request, strlen(request), 0);
    
    int received;
    while ((received = recv(sockfd, response, sizeof(response)-1, 0)) > 0) {
        response[received] = '\0';
        printf("%s", response);
    }
    
    closesocket(sockfd);
    WSACleanup();
}
#endif

