include ../Make.inc

CFLAGS-add += -I../src -DNDEBUG
LDFLAGS-add += -lm

all: test

test.o: test.c
	$(CC) $(CPPFLAGS) $(CFLAGS-add) $(CFLAGS) $(fPIC) -c $< -o $@

tn93.o: ../src/tn93.c
	$(CC) $(CPPFLAGS) $(CFLAGS-add) $(CFLAGS) $(fPIC) -c $< -o $@

test: test.o tn93.o
	$(CC) $(LDFLAGS)  -o $@ $^ $(LDFLAGS-add)

clean:
	rm -f *.o test
