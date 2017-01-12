#ifndef 	__TN93SHARED__
#define 	__TN93SHARED__

#include <math.h>

#define  RESOLVE        0
#define  AVERAGE        1
#define  SKIP           2
#define  GAPMM          3

#define N_CHAR 15UL
#define GAP    17UL

#define  TN93_MAX_DIST 1.0

#define  RESOLVE_A 0x01
#define  RESOLVE_C 0x02
#define  RESOLVE_G 0x04
#define  RESOLVE_T 0x08

extern double tn93(const char * s1, const char * s2,  const unsigned long L, const unsigned int matchMode, const unsigned long minOverlap);

#endif
