


#define STRINGISE_IMPL(A) # A
#define STRINGISE(A) STRINGISE_IMPL(A)

#pragma message(__FILE__ "(" STRINGISE(__LINE__) "): being included" )

#if (defined(__INTELLISENSE__))
//Always process in intellisense context
#define DONT_PROCESS 0 

#else

#ifdef TARGET
#pragma message("TARGET: " TARGET)

#if (defined(CONDITIONAL_INLINE_ON) && defined(CONDITIONAL_INLINE_INCLUDING)) && ! __has_include(TARGET) 

#pragma message("Conditional inlining is on, and we're currently inlining into a different TU")

#define DONT_PROCESS 0

#elif (!defined(CONDITIONAL_INLINE_ON))

#pragma message("Conditional inlining is not on, chances are we're compiling the file directly as its own TU (or conditional-inline is being used incorrectly)")

#define DONT_PROCESS 0

#else

#define DONT_PROCESS 1

#pragma message ("Note: not compiling the inlinee at this time")

#pragma message("Conditional inlining is on, but we're not currently inlining - chances are either we're compiling the file directly, which means we skip the target or we've already included the target")

#endif


#else 

#define DONT_PROCESS 0

#endif

#endif
