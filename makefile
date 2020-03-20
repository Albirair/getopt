build/libgetopt.so: build/getopt.o
	cc --shared -o build/libgetopt.so build/getopt.o
build/getopt.o: src/getopt.c
	cc -c -fpic -o build/getopt.o src/getopt.c
src/getopt.c: src/getopt.h
.PHONY: test
test: build/test
build/test: src/test.cpp build/libgetopt.so
	g++ -o build/test src/test.cpp build/libgetopt.so
