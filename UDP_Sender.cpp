//
// Created by feyzi on 24.03.2022.
//

#include "UDP_Sender.h"
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<netdb.h>
#include<stdarg.h>
#include<string.h>
#include<string>
#include<iostream>
#include "CAM_Message_Type.h"

#define MAXLINE 1024

struct reference_position
{
    float latitude ;
    float longitude ;
    float elevation ;
    float accuracy ;
};

UDP_Sender::UDP_Sender()
{
    receiver_port = 5000 ;
    receiver_port_str = std::to_string(receiver_port).c_str();
    receiver_ip_address = "192.168.1.17" ;
}

void UDP_Sender::start_sending()
{
    int sockfd;
    char buffer[MAXLINE];

    struct sockaddr_in  servaddr;

    // Creating socket file descriptor
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(receiver_port);
    servaddr.sin_addr.s_addr = inet_addr(receiver_ip_address);

    int protocol_version = 2 ;
    int message_id = 2 ;
    int station_id = 1 ;
    int generation_deltatime = 0 ;
    int station_type = 5 ;
    float latitude = 41.016351819999997 ;
    float longitude = 28.944218469999999 ;
    float altitude_value = 60.400390625 ;
    int heading_value = 0 ;
    int heading_confidence = 0 ;
    int speed_value = 6479 ;
    int vehicle_length_value = 48 ;
    int vehicle_width = 18 ;
    int longitudinal_acceleration = 27 ;

    for(int i = 0 ; i < 10000000 ; i++)
    {

        message = std::to_string(protocol_version) + "," + std::to_string(message_id) + "," + std::to_string(station_id) + "," +
                std::to_string(generation_deltatime) + "," + std::to_string(station_type) + "," + std::to_string(latitude) + "," +
                std::to_string(longitude) + "," + std::to_string(altitude_value) + "," + std::to_string(heading_value) + ","
                + std::to_string(heading_confidence) + "," + std::to_string(speed_value) + "," + std::to_string(vehicle_length_value) +
                std::to_string(vehicle_width) + std::to_string(longitudinal_acceleration);

        for(int k = 0 ; k < MAXLINE - message.length() ; k++)
        {
            message = message + "+" ;
        }

        std::cout << sizeof(message) << " " ;

        const char *hello = message.c_str();
        sendto(sockfd, (const char *)hello, strlen(hello),
               MSG_CONFIRM, (const struct sockaddr *) &servaddr,
               sizeof(servaddr));
        std::cout << "sent " << message << std::endl ;

        sleep(1);
    }

    close(sockfd);
}