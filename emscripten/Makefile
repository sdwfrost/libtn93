CC = emcc
CFLAGS = -O3
JSFLAGS =

SRCS =  ../src/tn93.c

libtn93.js: ${SRCS}
	$(CC) $(CFLAGS) $(JSFLAGS) -s ASSERTIONS=1 -s "EXPORTED_FUNCTIONS=['_tn93']" -s "EXTRA_EXPORTED_RUNTIME_METHODS=['ccall', 'cwrap']" -DNDEBUG -o $@ $<

clean:
	rm -f libtn93.js libtn93.js.mem
