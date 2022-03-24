#include <iostream>
#include "UDP_Sender.h"
#include "string_parser.h"
#include "CAM_Message_Type.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    string_parser parser ;
    parser.input_string = "55,1,2,2,2,3" ;
    parser.delimiter = "," ;
    parser.parse_input_string() ;
    Altitude altitude ;
    for(int i = 0 ; i < parser.output_string_string_vector.size() ; i++)
    {
        std::cout << parser.output_string_string_vector[i] << " " ;
    }
    std::cout << "\n" ;
    UDP_Sender sender ;
    sender.start_sending() ;
    return 0;
}
