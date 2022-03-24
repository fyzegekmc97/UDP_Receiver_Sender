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

    int n, len;
    int max_run_length = 1000 ;
    int message_id = 1 ;
    int protocol_version = 1 ;
    int station_id = 15 ;
    int generation_delta_time = 15 ;
    int station_type = 2 ;
    float heading = 155.0 ;
    float speed = 100.0 ;
    float drive_direction = 100.5 ;
    float vehicle_length = 55.5 ;
    float vehicle_width = 45.5 ;
    float longitudinal_accelaration = 56.6 ;
    float curvature = 50.0 ;
    float yaw_rate = 56.1 ;
    int vehicle_role = 1 ;
    bool exterior_lights = true ;

    for(int i = 0 ; i < max_run_length ; i++)
    {
        message_id++ ;
        speed-- ;
        longitudinal_accelaration-- ;
        message = std::to_string(message_id) + "," + std::to_string(protocol_version) + "," + std::to_string(station_id) + ","
                + std::to_string(generation_delta_time) + "," + std::to_string(station_type) + "," + std::to_string(heading) +
                "," + std::to_string(speed) + "," + std::to_string(drive_direction) + "," + std::to_string(vehicle_length) + ","
                + std::to_string(vehicle_width) + "," + std::to_string(longitudinal_accelaration) + "," + std::to_string(curvature) + ","
                + std::to_string(yaw_rate) + "" + "," + "" + "," + "" + "," + "" + "," + "" + "," + "" + "," + ""  + std::to_string(vehicle_role) +
                "," + std::to_string(exterior_lights);
        std::cout << message.length() << " " ;

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