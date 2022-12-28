CXX_FLAGS=-O3 -static -std=c++20

cube: main.o state.o cube.o hashing.o
	g++ main.o state.o cube.o hashing.o -o cube

%.o: src/%.cc
	g++ -c $< ${CXX_FLAGS} -o $@

clean:
	- rm cube *.o
