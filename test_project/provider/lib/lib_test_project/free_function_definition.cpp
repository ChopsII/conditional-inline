

#define STRINGISE_IMPL(A) # A
#define STRINGISE(A) STRINGISE_IMPL(A)

#pragma message(__FILE__ "(" STRINGISE(__LINE__) "): being included" )

#define TARGET "free_function_definition.cpp"

#include "inlinee_begin.hpp"

#if !DONT_PROCESS

#include "free_function_declaration.hpp"

#include <memory>

COND_INLINE
void* lib_test_project::free_function()
{
    static int blah;
    return std::addressof(blah);
}

#endif
#undef DONT_PROCESS