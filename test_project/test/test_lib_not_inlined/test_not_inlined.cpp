
#define STRINGISE_IMPL(A) # A
#define STRINGISE(A) STRINGISE_IMPL(A)

#pragma message(__FILE__ "(" STRINGISE(__LINE__) "): being included" )

#define CATCH_CONFIG_MAIN

#include "catch2/catch.hpp"


TEST_CASE("")
{
    
}