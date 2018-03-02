CC = emcc
CFLAGS = -O3
JSFLAGS = --pre-js prefix.js --post-js postfix.js

SRCS =  ../src/tn93.c

libtn93.js: ${SRCS}
	$(CC) $(CFLAGS) -s "EXPORTED_FUNCTIONS=['_tn93']" -DNDEBUG -o $@ $<

clean:
	rm -f libtn93.js
