//
// Created by feyzi on 24.03.2022.
//

#ifndef UDP_RECEIVER_SENDER_UDP_SENDER_H
#define UDP_RECEIVER_SENDER_UDP_SENDER_H
#include <string>

class UDP_Sender
{
public:
    UDP_Sender();
    //void create_port();
    void start_sending();
    std::string message ;
    //void stop_sending();
    //void print_sent();
private:
    const char *receiver_ip_address ;
    std::string my_ip_address ;
    int receiver_port ;
    const char * receiver_port_str ;
    int my_port ;
    char * sent_buf ;
};


#endif //UDP_RECEIVER_SENDER_UDP_SENDER_H
