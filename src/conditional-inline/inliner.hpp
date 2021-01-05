


#ifdef LIB_SHITTY_LANG_INLINE
#ifdef LIB_SHITTY_LANG_INCLUDING
#error nested "including" sections
#endif
#define LIB_SHITTY_LANG_INCLUDING
#include TARGET
#undef LIB_SHITTY_LANG_INCLUDING
#endif