#pragma once


#define STRINGISE_IMPL(A) # A
#define STRINGISE(A) STRINGISE_IMPL(A)

#pragma message(__FILE__ "(" STRINGISE(__LINE__) "): being included" )

#include "cond_inline.hpp"

#include <memory>

namespace lib_test_project
{
    struct Class
    {
        COND_INLINE Class();

        COND_INLINE static void static_member_function();

        COND_INLINE void* non_static_member_function();

        COND_INLINE_DATA static int static_data_member;

        int non_static_data_member;
    };
}

#define TARGET "class_member_function_definitions.cpp"
#include "inliner.hpp"
#undef TARGET