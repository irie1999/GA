OBJS = main.o generation_change.o agent.o

main: $(OBJS)
	g++ -o $@  $(OBJS)

%.o: %.cpp GA.h
	g++ -c $< -Wall -O3 -I.
