#pragma once


#define STRINGISE_IMPL(A) # A
#define STRINGISE(A) STRINGISE_IMPL(A)

#pragma message(__FILE__ "(" STRINGISE(__LINE__) "): being included" )

#include "cond_inline.hpp"

namespace lib_test_project
{
    void* free_function();
}

#define TARGET "free_function_definition.cpp"
#include "inliner.hpp"
#undef TARGET
