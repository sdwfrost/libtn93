cdef extern from "tn93.h":
  double tn93(const char * s1, const char * s2,  const unsigned long L, const char matchMode, const long min_overlap)

def tn93dist(s1,s2,L,matchMode,min_overlap):
  return(tn93(s1,s2,L,matchMode,min_overlap))

