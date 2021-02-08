#define CATCH_CONFIG_MAIN

#include <iostream>
#include <string>
#include <vector>
#include "catch.hpp"

int calculate(std::string inputString)
{
    std::vector<std::string> tokens;

    int sum = 0;

    // Check for empty string
    if (!inputString.size())
        return 0;

    printf("NOTE: on %s\n", inputString.c_str());

    size_t indexOf_newline = inputString.find('\n');
    while (indexOf_newline != std::string::npos && indexOf_newline != inputString.size())
    {
        inputString.at(indexOf_newline) = ',';
        printf("NOTE: Replaced at %d\n", indexOf_newline);
        indexOf_newline = inputString.find('\n');
    }

    std::stringstream s_string(inputString);
    printf("OUT: %s\n", inputString.c_str());
    // Break up the input string into tokens
    while(s_string.good())
    {
        std::string saved("");
        std::getline(s_string, saved, ',');
        tokens.push_back(saved);
    }
    
    // Add up the positive numbers
    for(std::string i : tokens)
    {
        printf("ADDING: %d to %d\n", atoi(i.c_str()), sum);
        if (atoi(i.c_str()) > -1)
            sum += atoi(i.c_str());
        else
        {
            sum = -1;
        }
    }

    return sum;
}

TEST_CASE( "Factorials are computed", "[factorial]" ) 
{
    REQUIRE( calculate("") == 0 );
    REQUIRE( calculate("232") == 232 );
    REQUIRE( calculate("4,79") == (83) );
    REQUIRE( calculate("14\n908") == 922);
    REQUIRE( calculate("3,86\n91") == 180);
    REQUIRE( calculate("56,-8") == -1);
}