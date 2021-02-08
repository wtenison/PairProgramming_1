#define CATCH_CONFIG_MAIN

#include <iostream>
#include <string>
#include <vector>
#include "catch.hpp"

int calculate(std::string inputString)
{
    std::vector<std::string> tokens;
    std::string delimiter(",");

    int sum = 0;

    // Check for empty string --------------------------------------------------
    if (!inputString.size())
        return 0;

    printf("NOTE: on %s\n", inputString.c_str());

    // Check for custom delimiter --------------------------------------------------
    if (inputString.substr(0,2).compare("//") == 0)
    {
        int i = 2;
        delimiter = "";

        while (inputString[i] != '\n')
            delimiter.push_back(inputString[i++]);

        inputString = inputString.substr(i + 1, inputString.length() - 1);
        printf("NOTE: Subtstring %s\n", inputString.c_str());
    }

    // Replace delimiter with '\n' ------------------------------------------------------------
    size_t indexOf_delimiter = inputString.find(delimiter);
    while (indexOf_delimiter != std::string::npos && indexOf_delimiter != inputString.size())
    {
        inputString.replace(indexOf_delimiter, delimiter.length(), "\n");
        printf("NOTE: Replaced at %d\n", indexOf_delimiter);
        indexOf_delimiter = inputString.find(delimiter);
    }

    std::stringstream s_string(inputString);
    //printf("OUT: %s\n", inputString.c_str());
    // Break up the input string into tokens --------------------------------------------------
    while(s_string.good())
    {
        std::string saved("");
        std::getline(s_string, saved);
        tokens.push_back(saved);
    }
    
    // Add up the positive numbers --------------------------------------------------
    for(std::string i : tokens)
    {
        //printf("ADDING: %d to %d\n", atoi(i.c_str()), sum);

        int x = atoi(i.c_str());

        if (x > 1000)
            continue;
        else if (x > -1)
            sum += x;
        else
            throw printf("ERROR: Negative value found.\n");
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
    REQUIRE_THROWS( calculate("56,-8") == -1);
    REQUIRE( calculate("1001\n9,10") == 19);
    REQUIRE( calculate("//#\n10#408\n10002#67") == 485);
    REQUIRE( calculate("//###\n10###408\n10002###67") == 485);
}