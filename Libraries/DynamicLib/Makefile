CC = g++
CFLAGS = -Wall -fPIC

all: libsort.so

libsort.so: *.cpp
	$(CC) $(CFLAGS) -c *.cpp
	$(CC) -shared -o libsort.so *.o
	rm *.o

clean:
	rm -f libsort.so
