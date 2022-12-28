# CXX_FLAGS=-O3 -static -std=c++20

cube: main.o state.o cube.o hashing.o utils.o
	g++ main.o state.o cube.o hashing.o utils.o -o cube

main.o: main.cc
	g++ main.cc -c ${CXX_FLAGS} -o main.o

state.o: src/state.cc state.h utils.h
	g++ src/state.cc -c ${CXX_FLAGS} -o state.o

cube.o: src/cube.cc cube.h utils.h
	g++ src/cube.cc -c ${CXX_FLAGS} -o cube.o

hashing.o: src/hashing.cc
	g++ src/hashing.cc -c ${CXX_FLAGS} -o hashing.o

utils.o: src/utils.cc utils.h
	g++ src/utils.cc -c ${CXX_FLAGS} -o utils.o

clean:
	- rm *.o
