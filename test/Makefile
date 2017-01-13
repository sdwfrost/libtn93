include ../Make.inc

CFLAGS-add += -I../src -DNDEBUG
LDFLAGS-add += -lm

all: test test2

test.o: test.c
	$(CC) $(CPPFLAGS) $(CFLAGS-add) $(CFLAGS) $(fPIC) -c $< -o $@

test2.o: test2.c
	$(CC) $(CPPFLAGS) $(CFLAGS-add) $(CFLAGS) $(fPIC) -c $< -o $@

tn93.o: ../src/tn93.c
	$(CC) $(CPPFLAGS) $(CFLAGS-add) $(CFLAGS) $(fPIC) -c $< -o $@

test: test.o tn93.o
	$(CC) $(LDFLAGS)  -o $@ $^ $(LDFLAGS-add)

test2: test2.o tn93.o
	$(CC) $(LDFLAGS)  -o $@ $^ $(LDFLAGS-add)

clean:
	rm -f *.o test test2
