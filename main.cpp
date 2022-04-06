#include <iostream>
#include <fstream>
#include "UDP_Sender.h"
#include "string_parser.h"
#include "CAM_Message_Type.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json ;

void parse_my_str(std::string & some_str)
{
    try {
        auto my_second_json = json::parse(some_str);
        std::cout << my_second_json.dump();
        std::cout << "\n" ;
        auto happy_val = my_second_json["happy"] ;
        std::cout << happy_val  << "\n" ;
    }
    catch(json::parse_error::exception)
    {
        std::cout << "Parse error occured" ;
        some_str = some_str + "}" ;
        parse_my_str(some_str) ;
    }
}

void divide_my_long_str(std::string long_string, int maximum_string_length)
{

}

int main() {
    std::string some_str = "{\"happy\": true, \"pi\": 3.141" ;
    parse_my_str(some_str) ;
    return 0 ;
}
