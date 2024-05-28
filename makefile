# Define the Fortran and C compilers
FC = gfortran
CC = gcc

# Define compiler flags
FFLAGS = -c -fPIC -g
CFLAGS = -c -g

# Define the executable name
TARGET = calculator

# List of object files
OBJECTS = main.o calculator.o

# Default target to build the calculator
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) -lncurses -lgfortran

# Rule to compile the Fortran source file
calculator.o: calculator.f90
	$(FC) $(FFLAGS) calculator.f90

# Rule to compile the C source file
main.o: main.c
	$(CC) $(CFLAGS) main.c

# Clean up object files and executable
clean:
	rm -f $(OBJECTS) $(TARGET) calculator.mod
