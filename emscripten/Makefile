CC = emcc
CFLAGS = -O3
JSFLAGS =
SRCS =  ../src/tn93.c

all: libtn93.js libtn93wasm.js

libtn93.js: ${SRCS}
	$(CC) $(CFLAGS) $(JSFLAGS) -s EXPORT_NAME="'libtn93'" -s MODULARIZE=1 -s SINGLE_FILE=1 -s ASSERTIONS=1 -s "EXPORTED_FUNCTIONS=['_tn93']" -s "EXTRA_EXPORTED_RUNTIME_METHODS=['cwrap']" -DNDEBUG -o $@ $<

libtn93wasm.js: ${SRCS}
	$(CC) $(CFLAGS) $(JSFLAGS) -s EXPORT_NAME="'libtn93wasm'" -s MODULARIZE=1 -s WASM=1 -s SINGLE_FILE=1 -s ASSERTIONS=1 -s "EXPORTED_FUNCTIONS=['_tn93']" -s "EXTRA_EXPORTED_RUNTIME_METHODS=['cwrap','addOnPostRun']" -DNDEBUG -o $@ $<

clean:
	rm -f libtn93.js libtn93wasm.js
