CFLAGS += -I../posix/config -fPIC
LDFLAGS += -L../posix/config -lconfig

PREFIX = /usr/local
OBJECTS = config.o

%.o: %.c %.h
	$(CC) -c $(CFLAGS) $< -o $@

libera-config.so: $(OBJECTS)
	$(CC) $(LDFLAGS) -shared -o libera-config.so $(OBJECTS)

install: libera-config.so
	install -c -m 755 libera-config.so $(PREFIX)/lib

clean:
	rm -f *.o
	rm -f *.a
	rm -f *.so
