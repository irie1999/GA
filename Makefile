OBJS = main.o generation_change.o agent.o fdtd/cal_fdtd.o \
	fdtd/allocate_memory.o  fdtd/initialize_surface_impedance.o  fdtd/update_E.o \
	fdtd/current_source.o  fdtd/update_H.o fdtd/output.o  fdtd/update_H_PML.o \
	fdtd/initialize_conductivity.o  fdtd/update_D.o fdtd/initialize_pml.o \
	fdtd/update_D_PML.o fdtd/suffix.o fdtd/input.o 

main: $(OBJS)
	g++ -o $@  $(OBJS)


%.o: %.cpp fdtd/%.cpp GA.h agent.h 
	g++ -c $< -Wall -O3 -I.




