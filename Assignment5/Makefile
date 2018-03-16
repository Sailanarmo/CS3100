OBJS = main.cpp compPi.hpp compPi.cpp

CC = g++
DEBUG_FLAGS = -O0 -g3 -fsanitize=address
RELEASE_FLAGS = -pthread -Ofast -g0 
FLAGS = -std=c++14 -Wall -Wextra

release: $(OBJS)
		$(CC) $(RELEASE_FLAGS) $(FLAGS) $(OBJS) -o ComputePi

debug: $(OBJS) 
		$(CC) $(DEBUG_FLAGS) $(FLAGS) $(OBJS) -o debug && cgdb ./debug
