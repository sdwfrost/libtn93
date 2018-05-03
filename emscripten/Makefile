CC = emcc
CFLAGS = -O3
JSFLAGS = --memory-init-file 0

SRCS =  ../src/tn93.c

libtn93.js: ${SRCS}
	$(CC) $(CFLAGS) $(JSFLAGS) -s ASSERTIONS=1 -s "EXPORTED_FUNCTIONS=['_tn93']" -s "EXTRA_EXPORTED_RUNTIME_METHODS=['ccall', 'cwrap']" -DNDEBUG -o $@ $<

clean:
	rm -f libtn93.js libtn93wasm.js
