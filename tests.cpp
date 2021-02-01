#define CATCH_CONFIG_MAIN
#include "catch.hpp"

int calculate(std::string inputString)
{
    if (!inputString.size())
        return 0;

    return 1;
}

TEST_CASE("Caclulate tests")
{
    REQUIRE( calculate("") == 0 );
}