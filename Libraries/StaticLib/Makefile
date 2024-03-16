all: compile archive cleanup

compile: *.cpp
	g++ -c *.cpp

archive: *.o
	ar rs libsort.a *.o

cleanup: *.o
	rm *.o
