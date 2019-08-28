LDFLAGS = -rdynamic -L.
LDLIBS  = -Wl,--whole-archive -ldltest -Wl,--no-whole-archive -ldl

dltest: dltest.o libdltest.a
	gcc $(LDFLAGS) -o dltest dltest.o $(LDLIBS)

libdltest.a: libdltest.o
	ar rcs $@ libdltest.o

.PHONY: clean
clean:
	rm -f dltest dltest.o libdltest.o libdltest.a
