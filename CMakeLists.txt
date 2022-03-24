cmake_minimum_required(VERSION 3.21)
project(UDP_Receiver_Sender)

set(CMAKE_CXX_STANDARD 14)

add_executable(UDP_Receiver_Sender main.cpp UDP_Sender.cpp UDP_Sender.h string_parser.cpp string_parser.h CAM_Message_Type.cpp CAM_Message_Type.h UDP_JSON_Sender.cpp UDP_JSON_Sender.h)
