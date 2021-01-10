

#define STRINGISE_IMPL(A) # A
#define STRINGISE(A) STRINGISE_IMPL(A)

#pragma message(__FILE__ "(" STRINGISE(__LINE__) "): being included" )

#include "inlined_b.hpp"

#include "class_definition.hpp"
#include "free_function_declaration.hpp"

void* lib_inlined::inlined_b::getAddressOfStaticMemberFunction()
{
    return std::addressof(lib_test_project::Class::static_member_function);
}

void* lib_inlined::inlined_b::getAddressOfNonStaticMemberFunction()
{
    lib_test_project::Class c;
    return c.non_static_member_function();
}

void* lib_inlined::inlined_b::getAddressOfFreeFunction()
{
    return lib_test_project::free_function();
}