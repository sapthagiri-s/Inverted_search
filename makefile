OBJ=$(patsubst %.c,%.o,$(wildcard *.c)) # Generate a list of object files from all C source files in the directory
inverted_serach : $(OBJ)               # Define the target 'inverted_serach' and its dependencies (object files)
	gcc -o $@ $^                       # Compile and link the object files into the executable 'inverted_serach'
clean :                                # Define the 'clean' target to remove generated files
	rm *.o inverted_serach            # Remove all object files and the 'inverted_serach' executable
