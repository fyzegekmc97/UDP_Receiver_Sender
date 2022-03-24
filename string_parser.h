//
// Created by feyzi on 24.03.2022.
//

#ifndef UDP_RECEIVER_SENDER_STRING_PARSER_H
#define UDP_RECEIVER_SENDER_STRING_PARSER_H
#include <string>
#include <vector>

class string_parser {
public:
    std::string input_string ;
    std::vector<std::string> output_string_string_vector ;
    std::vector<std::string> parse_input_string() ;
    std::string delimiter ;
    string_parser();
    ~string_parser();
};


#endif //UDP_RECEIVER_SENDER_STRING_PARSER_H
