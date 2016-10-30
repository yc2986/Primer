CC 					= g++

# Directories
INCLUDE_DIR			= include
SRC_DIR				= src
LIB_DIR				= lib
OBJ_DIR				= ../Executable/Chapter-6/obj

# Compiler flags
CPPFLAGS			= -Wall -std=c++11 -I$(INCLUDE_DIR) -Ofast
# Linker flags
LDFLAGS				= 

# Source file
CPP_FILES			= $(wildcard $(SRC_DIR)/*.cpp)

# Argument
ARGUMENT 		= ../Executable/Chapter-6/FunctionArgument
ARGUMENT_OBJ	= $(addprefix $(OBJ_DIR)/, FunctionArgument.o)

# Return
RETURN 			= ../Executable/Chapter-6/FunctionReturn
RETURN_OBJ 		= $(addprefix $(OBJ_DIR)/, FunctionReturn.o)

# Overload
OVERLOAD 		= ../Executable/Chapter-6/FunctionOverload
OVERLOAD_OBJ	= $(addprefix $(OBJ_DIR)/, FunctionOverload.o)

# Special
SPECIAL_DEBUG 		= ../Executable/Chapter-6/SpecialFunction_Debug
SPECIAL_DEBUG_OBJ	= $(addprefix $(OBJ_DIR)/, SpecialFunction.o)

SPECIAL_RELEASE		= ../Executable/Chapter-6/SpecialFunction_Release

# Pointer
POINTER 		= ../Executable/Chapter-6/FunctionPointer
POINTER_OBJ		= $(addprefix $(OBJ_DIR)/, FunctionPointer.o)

# Compile
# $@: The filename representing the target.
# $%: The filename element of an archive member specification.
# $<: The filename of the first prerequisite.
# $?: The names of all prerequisites that are newer than the target, separated by spaces.
# $^: The filenames of all the prerequisites, separated by spaces. This list has duplicate filenames removed since for most uses, such as compiling, copying, etc., duplicates are not wanted.
# $+: Similar to $^, this is the names of all the prerequisites separated by spaces, except that $+ includes duplicates. This variable was created for specific situations such as arguments to linkers where duplicate values have meaning.
# $*: The stem of the target filename. A stem is typically a filename without its suffix. Its use outside of pattern rules is discouraged.
all: $(ARGUMENT) $(RETURN) $(OVERLOAD) $(SPECIAL_DEBUG) $(SPECIAL_RELEASE) $(POINTER)

$(POINTER): $(POINTER_OBJ)
	$(CC) $(LDFLAGS) -o $@ $<

$(SPECIAL_RELEASE): $(SRC_DIR)/SpecialFunction.cpp
	$(CC) $(CPPFLAGS) -DNDEBUG -o $@ $<

$(SPECIAL_DEBUG): $(SPECIAL_DEBUG_OBJ)
	$(CC) $(LDFLAGS) -o $@ $<

$(OVERLOAD): $(OVERLOAD_OBJ)
	$(CC) $(LDFLAGS) -o $@ $<

$(RETURN): $(RETURN_OBJ)
	$(CC) $(LDFLAGS) -o $@ $<

$(ARGUMENT): $(ARGUMENT_OBJ)
	$(CC) $(LDFLAGS) -o $@ $<

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CPPFLAGS) -c -o $@ $<

.PHONY: clean
clean:
# Clean up executables
	rm $(ARGUMENT) \
	   $(RETURN) \
	   $(OVERLOAD) \
	   $(SPECIAL_DEBUG) \
	   $(SPECIAL_RELEASE) \
	   $(POINTER)
# Clean up object files 
	rm $(ARGUMENT_OBJ) \
	   $(RETURN_OBJ) \
	   $(OVERLOAD_OBJ) \
	   $(SPECIAL_DEBUG_OBJ) \
	   $(POINTER_OBJ)
