CC 					= g++

# Directories
INCLUDE_DIR			= include
SRC_DIR				= src
LIB_DIR				= lib
OBJ_DIR				= ../Executable/Chapter-4/obj

# Compiler flags
CPPFLAGS			= -Wall -std=c++11 -I$(INCLUDE_DIR) -Ofast
# Linker flags
LDFLAGS				= 

# Source file
CPP_FILES			= $(wildcard $(SRC_DIR)/*.cpp)

# Fundamental
FUNDAMENTAL 		= ../Executable/Chapter-4/Fundamental
FUNDAMENTAL_OBJ		= $(addprefix $(OBJ_DIR)/, Fundamental.o)

OPERATORS 			= ../Executable/Chapter-4/Operators
OPERATORS_OBJ		= $(addprefix $(OBJ_DIR)/, Operators.o)

# Compile
# $@: The filename representing the target.
# $%: The filename element of an archive member specification.
# $<: The filename of the first prerequisite.
# $?: The names of all prerequisites that are newer than the target, separated by spaces.
# $^: The filenames of all the prerequisites, separated by spaces. This list has duplicate filenames removed since for most uses, such as compiling, copying, etc., duplicates are not wanted.
# $+: Similar to $^, this is the names of all the prerequisites separated by spaces, except that $+ includes duplicates. This variable was created for specific situations such as arguments to linkers where duplicate values have meaning.
# $*: The stem of the target filename. A stem is typically a filename without its suffix. Its use outside of pattern rules is discouraged.
all: $(FUNDAMENTAL) $(OPERATORS)

$(OPERATORS): $(OPERATORS_OBJ)
	$(CC) $(LDFLAGS) -o $@ $<

$(FUNDAMENTAL): $(FUNDAMENTAL_OBJ)
	$(CC) $(LDFLAGS) -o $@ $<

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CPPFLAGS) -c -o $@ $<

.PHONY: clean
clean:
# Clean up executables
	rm $(FUNDAMENTAL) \
	   $(OPERATORS)
# Clean up object files
	rm $(FUNDAMENTAL_OBJ) \
	   $(OPERATORS_OBJ)
