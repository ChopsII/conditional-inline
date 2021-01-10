

#define STRINGISE_IMPL(A) # A
#define STRINGISE(A) STRINGISE_IMPL(A)

#pragma message(__FILE__ "(" STRINGISE(__LINE__) "): being included" )

#ifndef TARGET
#define TARGET "class_member_function_definitions.cpp"
#endif

#include "inlinee_begin.hpp"

#if !DONT_PROCESS

#include "class_definition.hpp"

#include <memory>

lib_test_project::Class::Class()
    : non_static_data_member{}
{}

void lib_test_project::Class::static_member_function()
{
}

void* lib_test_project::Class::non_static_member_function()
{
    int blah;
    return std::addressof(blah);
}

COND_INLINE_DATA int lib_test_project::Class::static_data_member{};

#endif

#undef DONT_PROCESS