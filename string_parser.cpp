//
// Created by feyzi on 24.03.2022.
//

#include "string_parser.h"
#include <iostream>

string_parser::string_parser() {
    input_string = "" ;
    output_string_string_vector = {} ;
    delimiter = "" ;
}

std::vector<std::string> string_parser::parse_input_string() {
    std::vector<std::string> temp_obj = {} ;
    if(input_string.length() == 0)
    {
        return temp_obj ;
    }
    else if(!output_string_string_vector.empty())
    {
        output_string_string_vector.clear() ;
        parse_input_string() ;
    }
    else if(delimiter.empty())
    {
        std::cout << "Delimiter empty" ;
        return temp_obj ;
    }

    std::string temp_str = "" ;
    int z = 0 ;
    for(int i = 0 ; i < input_string.length() ; i++)
    {
        if(input_string[i] != ',')
        {
            temp_str = temp_str + input_string[i] ;
        }
        else
        {
            temp_obj.push_back(temp_str);
            z = i ;
            temp_str = "";
        }
    }
    std::cout << z << " " ;
    temp_obj.push_back(input_string.substr(z+1 , input_string.length() - z));
    output_string_string_vector = temp_obj ;
    return temp_obj ;
}

string_parser::~string_parser() = default;

