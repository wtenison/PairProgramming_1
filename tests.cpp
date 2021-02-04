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

TEST_CASE("Caclulate tests")
{
    REQUIRE( calculate("") == 0 );
}