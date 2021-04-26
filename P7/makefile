
CXX = g++						# The C++ compiler command
CXXFLAGS = -g -O0 -Wall -std=c++14	# The C++ compiler options (preserve debug symbols and No optimization)
LDFLAGS =						# The linker options (if any)

# The all target builds all of the programs handled by the makefile.
all: dfa_simulation 

# The palindrome_prod target builds the palindrome_prod executable.
dfa_simulation: dfa_simulation.o
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
	rm -f dfa_simulation *.o
	rm -rf *~ basura b i
	rm -rf a.out
	find . -name '*~' -exec rm {} \;