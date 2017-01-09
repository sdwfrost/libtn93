include ../Make.inc

SRCS =  tn93.c

OBJS = $(SRCS:%.c=%.o)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS-add) $(CFLAGS) $(fPIC) -DNDEBUG -c $< -o $@

release debug: libtn93.$(SHLIB_EXT)

libtn93.$(SHLIB_EXT): $(OBJS)
	rm -rf $@
	$(CC) $(LDFLAGS) $(LDFLAGS-add) -shared -o $@ $^

clean:
	rm -f *.o *.$(SHLIB_EXT)
