#define CATCH_CONFIG_MAIN

#include <iostream>
#include <string>
#include <vector>
#include "catch.hpp"

int calculate(std::string inputString)
{
    std::vector<std::string> tokens;
    std::stringstream s_string(inputString);

    int sum = 0;

    // Check for empty string
    if (!inputString.size())
        return 0;

    // Break up the input string into variables
    while(s_string.good())
    {
        std::string saved("");
        std::getline(s_string, saved, ',');
        tokens.push_back(saved);
    }    
    
    // Add up the positive numbers
    for(std::string i : tokens)
    {
        if (atoi(i.c_str()) > -1)
            sum += atoi(i.c_str());
        else
        {
            sum = -1;
            throw printf("ERROR : Negative value found\n");
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