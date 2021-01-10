#pragma once

#define STRINGISE_IMPL(A) # A
#define STRINGISE(A) STRINGISE_IMPL(A)

#pragma message(__FILE__ "(" STRINGISE(__LINE__) "): being included" )

#if defined(CONDITIONAL_INLINE_ON)
#define COND_INLINE __forceinline
#define COND_INLINE_DATA inline
#else
#define COND_INLINE
#define COND_INLINE_DATA
#endif
