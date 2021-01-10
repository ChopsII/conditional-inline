
#define STRINGISE_IMPL(A) # A
#define STRINGISE(A) STRINGISE_IMPL(A)

#pragma message(__FILE__ "(" STRINGISE(__LINE__) "): being included" )

#define CATCH_CONFIG_MAIN

#include "inlined_a.hpp"
#include "inlined_b.hpp"

#include "catch2/catch.hpp"

#include "class_definition.hpp"

#include "free_function_declaration.hpp"

TEST_CASE("static member function")
{
    auto inlined_a_location = lib_inlined::inlined_a::getAddressOfStaticMemberFunction();
    auto inlined_b_location = lib_inlined::inlined_b::getAddressOfStaticMemberFunction();

    REQUIRE_FALSE(inlined_a_location == inlined_b_location);

}


TEST_CASE("non-static member function")
{
    auto inlined_a_location = lib_inlined::inlined_a::getAddressOfNonStaticMemberFunction();
    auto inlined_b_location = lib_inlined::inlined_b::getAddressOfNonStaticMemberFunction();

    REQUIRE_FALSE(inlined_a_location == inlined_b_location);

}

TEST_CASE("free function")
{
    auto inlined_a_location = lib_inlined::inlined_a::getAddressOfFreeFunction();
    auto inlined_b_location = lib_inlined::inlined_b::getAddressOfFreeFunction();

    REQUIRE_FALSE(inlined_a_location == inlined_b_location);

}
