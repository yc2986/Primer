CC                  = g++

# Directories
INCLUDE_DIR         = include
SRC_DIR             = src
LIB_DIR             = lib
OBJ_DIR             = ../Executable/Chapter-7/obj

# Compiler flags
CPPFLAGS            = -Wall -std=c++11 -I$(INCLUDE_DIR) -Ofast
# Linker flags
LDFLAGS             = 

# Class library
CLASS_LIB           = ../Executable/Chapter-7/lib/class.a

# Sales_data
SALES_DATA_OBJ      = $(addprefix $(OBJ_DIR)/, Sales_data.o)

# Screen
SCREEN_OBJ          = $(addprefix $(OBJ_DIR)/, Screen.o)

# Sales_data main function
SALES_DATA_MAIN     = ../Executable/Chapter-7/Sales_data_main
SALES_DATA_MAIN_OBJ = $(addprefix $(OBJ_DIR)/, Sales_data_main.o)

# Screen main function
SCREEN_MAIN         = ../Executable/Chapter-7/Screen_main
SCREEN_MAIN_OBJ     = $(addprefix $(OBJ_DIR)/, Screen_main.o)

# Compile
# $@: The filename representing the target.
# $%: The filename element of an archive member specification.
# $<: The filename of the first prerequisite.
# $?: The names of all prerequisites that are newer than the target, separated by spaces.
# $^: The filenames of all the prerequisites, separated by spaces. This list has duplicate filenames removed since for most uses, such as compiling, copying, etc., duplicates are not wanted.
# $+: Similar to $^, this is the names of all the prerequisites separated by spaces, except that $+ includes duplicates. This variable was created for specific situations such as arguments to linkers where duplicate values have meaning.
# $*: The stem of the target filename. A stem is typically a filename without its suffix. Its use outside of pattern rules is discouraged.
all: $(SALES_DATA_MAIN) \
     $(SCREEN_MAIN)

$(SCREEN_MAIN): $(SCREEN_MAIN_OBJ) $(CLASS_LIB)
	$(CC) $(LDFLAGS) -o $@ $^

$(SALES_DATA_MAIN): $(SALES_DATA_MAIN_OBJ) $(CLASS_LIB)
	$(CC) $(LDFLAGS) -o $@ $^

$(CLASS_LIB): $(SALES_DATA_OBJ) $(SCREEN_OBJ)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CPPFLAGS) -c -o $@ $<

.PHONY: clean
clean:
# Clean up executables
	rm $(CLASS_LIB) \
	   $(SALES_DATA_MAIN) \
	   $(SCREEN_MAIN)
# Clean up object files 
	rm $(SALES_DATA_OBJ) \
	   $(SCREEN_OBJ) \
	   $(SALES_DATA_MAIN_OBJ)
	   $(SCREEN_MAIN_OBJ)
