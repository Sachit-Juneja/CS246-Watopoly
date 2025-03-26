# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++20 -Wall -O -g -MMD -Werror=vla

# Executable
EXEC = watopoly

# Source and object files
SOURCES = $(wildcard *.cc)
OBJECTS = ${SOURCES:.cc=.o}
DEPENDS = ${OBJECTS:.o=.d}

# Default target
$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXEC)

# Compile rule
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Auto-include dependency files
-include ${DEPENDS}

# Clean rule
.PHONY: clean
clean:
	rm -f $(OBJECTS) $(DEPENDS) $(EXEC)
