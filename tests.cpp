#define CATCH_CONFIG_MAIN
#include <vector>
#include <iostream>
#include "catch.hpp"

int calculate(std::string inputString)
{
    std::vector<std::string> tokens;
    std::stringstream string(inputString);
    int sum = 0;

    // Check for empty string
    if (!inputString.size())
        return 0;

    // Break up the input string into variables
    while(inputString != "")
    {
        std::string saved;
        getline(string, saved, ",");
        tokens.append(saved);
    }    
    
    for(auto i : tokens)
    {
        sum += atoi(i)
    }

    return sum;
}

TEST_CASE( "Factorials are computed", "[factorial]" ) 
{
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );
}