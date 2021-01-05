//#pragma message("including " __FILE__)

#if (defined(__INTELLISENSE__))
//Always process in intellisense context
#define DONT_PROCESS 0 

#else

#if (defined(LIB_SHITTY_LANG_INLINE) && defined(LIB_SHITTY_LANG_INCLUDING))

//#pragma message("We're inlining, and we're currently inlining into a different TU")

#define DONT_PROCESS 0

#elif (!defined(LIB_SHITTY_LANG_INLINE))

//#pragma message("we're not inlining, chances are we're compiling the file directly as its own TU")

#define DONT_PROCESS 0

#else

#define DONT_PROCESS 1

#pragma message ("Note: not compiling the inlinee at this time")

//#pragma message("We're inlining, but we're not currently inlining - chances are we're compiling the file directly, which means we skip")

#endif

#endif