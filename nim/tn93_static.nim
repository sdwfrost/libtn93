{.deadCodeElim: on.}
{.compile: "../src/tn93.c".}

import math
var dummy = round(1.234)

const
  RESOLVE* = 0
  AVERAGE* = 1
  SKIP* = 2
  GAPMM* = 3

proc tn93(s1: cstring; s2: cstring; L: culong; matchMode: cuint; minOverlap: culong): cdouble {.importc.}

proc tn93*(s1: string; s2: string; L: uint64; matchMode: uint; minOverlap: uint64): float64 =
  result=tn93(s1.cstring, s2.cstring, L.culong, matchMode.cuint, minOverlap.culong).float64
