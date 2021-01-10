#pragma once


#define STRINGISE_IMPL(A) # A
#define STRINGISE(A) STRINGISE_IMPL(A)

#pragma message(__FILE__ "(" STRINGISE(__LINE__) "): being included" )

namespace lib_inlined{

    namespace inlined_a{

        void* getAddressOfStaticMemberFunction();

        void* getAddressOfNonStaticMemberFunction();

        void* getAddressOfStaticDataMember();

        void* getAddressOfFreeFunction();
    }
}