cmake_minimum_required(VERSION 3.21)
project(UDP_Receiver_Sender)

find_package(nlohmann_json 3.2.0 REQUIRED)

set(CMAKE_CXX_STANDARD 14)

add_executable(UDP_Receiver_Sender main.cpp UDP_Sender.cpp UDP_Sender.h string_parser.cpp string_parser.h CAM_Message_Type.cpp CAM_Message_Type.h UDP_JSON_Sender.cpp UDP_JSON_Sender.h)

target_link_libraries(UDP_Receiver_Sender PRIVATE nlohmann_json::nlohmann_json)