CC 					= g++

# Directories
INCLUDE_DIR			= include
SRC_DIR				= src
LIB_DIR				= lib
OBJ_DIR				= ../Executable/Chapter-5/obj

# Compiler flags
CPPFLAGS			= -Wall -std=c++11 -I$(INCLUDE_DIR) -Ofast
# Linker flags
LDFLAGS				= 

# Source file
CPP_FILES			= $(wildcard $(SRC_DIR)/*.cpp)

# Fundamental
CONDITION 		= ../Executable/Chapter-5/ConditionStatements
CONDITION_OBJ	= $(addprefix $(OBJ_DIR)/, ConditionStatements.o)

ITERATIVE 		= ../Executable/Chapter-5/IterativeStatements
ITERATIVE_OBJ	= $(addprefix $(OBJ_DIR)/, IterativeStatements.o)

JUMP			= ../Executable/Chapter-5/JumpStatements
JUMP_OBJ		= $(addprefix $(OBJ_DIR)/, JumpStatements.o)

EXCEPTION		= ../Executable/Chapter-5/ExceptionHandle
EXCEPTION_OBJ	= $(addprefix $(OBJ_DIR)/, ExceptionHandle.o)

# Compile
# $@: The filename representing the target.
# $%: The filename element of an archive member specification.
# $<: The filename of the first prerequisite.
# $?: The names of all prerequisites that are newer than the target, separated by spaces.
# $^: The filenames of all the prerequisites, separated by spaces. This list has duplicate filenames removed since for most uses, such as compiling, copying, etc., duplicates are not wanted.
# $+: Similar to $^, this is the names of all the prerequisites separated by spaces, except that $+ includes duplicates. This variable was created for specific situations such as arguments to linkers where duplicate values have meaning.
# $*: The stem of the target filename. A stem is typically a filename without its suffix. Its use outside of pattern rules is discouraged.
all: $(CONDITION) $(ITERATIVE) $(JUMP) $(EXCEPTION)

$(EXCEPTION): $(EXCEPTION_OBJ)
	$(CC) $(LDFLAGS) -o $@ $<

$(JUMP): $(JUMP_OBJ)
	$(CC) $(LDFLAGS) -o $@ $<

$(ITERATIVE): $(ITERATIVE_OBJ)
	$(CC) $(LDFLAGS) -o $@ $<

$(CONDITION): $(CONDITION_OBJ)
	$(CC) $(LDFLAGS) -o $@ $<

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CPPFLAGS) -c -o $@ $<

.PHONY: clean
clean:
# Clean up executables
	rm $(CONDITION) \
	   $(ITERATIVE) \
	   $(JUMP) \
	   $(EXCEPTION)
# Clean up object files
	rm $(CONDITION_OBJ) \
	   $(ITERATIVE_OBJ) \
	   $(JUMP_OBJ) \
	   $(EXCEPTION_OBJ)
