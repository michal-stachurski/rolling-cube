
cube: main.cc state.h colors.h utils.h visited.h
	g++ main.cc -O3 -o cube

cube-debug: main.cc state.h colors.h utils.h visited.h
	g++ main.cc -ggdb3 -fsanitize=address -D_GLIBCXX_DEBUG -Wall -o cube-debug