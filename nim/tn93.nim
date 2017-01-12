{.deadCodeElim: on.}

import math
var dummy = round(1.234)

when defined(windows):
 const
   tn93lib* = "tn93.dll"
elif defined(macosx):
 const
   tn93lib* = "libtn93.dylib"
else:
 const
   tn93lib* = "libtn93.so"

const
  RESOLVE* = 0
  AVERAGE* = 1
  SKIP* = 2
  GAPMM* = 3

proc tn93(s1: cstring; s2: cstring; L: culong; matchMode: cuint; minOverlap: culong): cdouble {.cdecl, importc: "tn93", dynlib: tn93lib.}

proc tn93*(s1: string; s2: string; L: uint64; matchMode: uint; minOverlap: uint64): float64 =
  result=tn93(s1.cstring, s2.cstring, L.culong, matchMode.cuint, minOverlap.culong).float64

