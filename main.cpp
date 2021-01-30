#include <iostream>
#include <string>
#include "include/catch.hpp"

int foo(std::string inputString)
{
    if (inputString.size() == 0)
        return 0;

    return 1;
}

int main()
{
    return 1;
}