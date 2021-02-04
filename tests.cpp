#define CATCH_CONFIG_MAIN
#include <vector>
#include "catch.hpp"

int calculate(std::string inputString)
{
    std::vector<std::string> tokens;

    // Check for empty string
    if (!inputString.size())
        return 0;

    // Break up the input string into variables
    while(inputString)    
    
    return 1;
}

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );
}