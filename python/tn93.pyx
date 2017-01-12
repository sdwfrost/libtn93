# Define constants

RESOLVE = 0
AVERAGE = 1
SKIP = 2
GAPMM = 3

cdef extern from "../src/tn93.h":
  double _tn93 "tn93" (const char * s1, const char * s2,  const unsigned long L, const char matchMode, const long min_overlap)

def tn93(s1,s2,L,matchMode,min_overlap):
  s1b=bytearray(s1,"ASCII")
  s2b=bytearray(s2,"ASCII")
  return(_tn93(s1b,s2b,L,matchMode,min_overlap))

