#define CATCH_CONFIG_MAIN
#include "catch.hpp"

unsigned int Factorial (unsigned int number)
{
    return number <= 1 ? number : Factorial(number - 1) * number;
}

TEST_CASE("Factorial tests", "[Factorial]")
{
    REQUIRE( Factorial(1) == 1 );
}