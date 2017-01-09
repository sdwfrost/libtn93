# libtn93

This is a C library to compute the Tamura-Nei (1993) genetic distance between genetic sequences. It is essentially a refactoring of [tn93](http://github.com/veg/tn93) by @spond and @stevenweaver intended to make it easier to wrap with Python etc., and to include in pipelines. Differences include:

- Compiles under C rather than C++
- A shared library, rather than an executable
- Avoids use of globals
- Simplified interface, only exposing a single function


