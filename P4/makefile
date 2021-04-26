# AUTHOR: Juan García Santos
# DATE: 24/10/2020
# EMAIL: alu0101325583@ull.edu.es
# VERSION: 1.0
# SUBJECT: CyA
# PRACTICE Nº: 4
# Use: make
#      make clean
# To build the project 


CXX = g++						# The C++ compiler command
CXXFLAGS = -g -O0 -Wall -std=c++14	# The C++ compiler options (preserve debug symbols and No optimization)
LDFLAGS =						# The linker options (if any)

# The all target builds all of the programs handled by the makefile.
all: main 

# The palindrome_prod target builds the palindrome_prod executable.
main: main.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Indicate that the all and clean targets do not
# correspond to actual files.
.PHONY: all clean

# The following rule is effectively built into make and
# therefore need not be explicitly specified:
# hello_world.o: hello_world.cc
#
	$(CXX) $(CXXFLAGS) -c $<

# The clean target removes all of the executable files
# and object files produced by the build process
clean :
	rm -f main *.o
	rm -f output *.txt
	rm -rf *~ basura b i
	rm -rf a.out
	find . -name '*~' -exec rm {} \;