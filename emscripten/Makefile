CC = emcc
CFLAGS = -O3
JSFLAGS =

SRCS =  ../src/tn93.c ./main.c

libtn93wasm.js: ${SRCS}
	$(CC) $(CFLAGS) $(JSFLAGS) -s WASM=1 -s SINGLE_FILE=1 -s ASSERTIONS=1 -s "EXPORTED_FUNCTIONS=['_tn93']" -s "EXTRA_EXPORTED_RUNTIME_METHODS=['ccall', 'cwrap']" -DNDEBUG -o $@ $<

clean:
	rm -f libtn93.js libtn93wasm.js
