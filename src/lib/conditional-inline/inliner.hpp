

#define STRINGISE_IMPL(A) # A
#define STRINGISE(A) STRINGISE_IMPL(A)

#pragma message(__FILE__ "(" STRINGISE(__LINE__) "): being included" )

#ifdef CONDITIONAL_INLINE_ON
#ifdef CONDITIONAL_INLINE_INCLUDING
#error nested "including" sections
#endif
#define CONDITIONAL_INLINE_INCLUDING
#include TARGET
#undef CONDITIONAL_INLINE_INCLUDING
#endif