CC                  = g++

# Directories
INCLUDE_DIR         = include
SRC_DIR             = src
LIB_DIR             = lib
OBJ_DIR             = ../Executable/Chapter-1/obj

# Compiler flags
CPPFLAGS            = -Wall -std=c++11 -I$(INCLUDE_DIR) -Ofast
# Linker flags
LDFLAGS             = 

# Hello World
HELLOWORLD          = ../Executable/Chapter-1/HelloWorld
HELLOWORD_OBJ       = $(addprefix $(OBJ_DIR)/, HelloWorld.o)

# Basic I/O
BASIC_IO            = ../Executable/Chapter-1/BasicIO
BASIC_IO_OBJ        = $(addprefix $(OBJ_DIR)/, BasicIO.o)

# Flow Control
FLOW_CONTROL        = ../Executable/Chapter-1/FlowControl
FLOW_CONTROL_OBJ    = $(addprefix $(OBJ_DIR)/, FlowControl.o)

# Sales Item Class
SALES_ITEM_LIB      = ../Executable/Chapter-1/lib/SalesItem.a
SALES_ITEM_OBJ      = $(addprefix $(OBJ_DIR)/, SalesItem.o)

# Sales Item Test App
BOOK_STORE          = ../Executable/Chapter-1/BookStore
BOOK_STORE_OBJ      = $(addprefix $(OBJ_DIR)/, BookStore.o)

# Compile
# $@: The filename representing the target.
# $%: The filename element of an archive member specification.
# $<: The filename of the first prerequisite.
# $?: The names of all prerequisites that are newer than the target, separated by spaces.
# $^: The filenames of all the prerequisites, separated by spaces. This list has duplicate filenames removed since for most uses, such as compiling, copying, etc., duplicates are not wanted.
# $+: Similar to $^, this is the names of all the prerequisites separated by spaces, except that $+ includes duplicates. This variable was created for specific situations such as arguments to linkers where duplicate values have meaning.
# $*: The stem of the target filename. A stem is typically a filename without its suffix. Its use outside of pattern rules is discouraged.
all: $(HELLOWORLD) \
     $(BASIC_IO) \
     $(FLOW_CONTROL) \
     $(SALES_ITEM_LIB) \
     $(BOOK_STORE)

$(BOOK_STORE): $(BOOK_STORE_OBJ) $(SALES_ITEM_LIB)
	$(CC) $(LDFLAGS) -o $@ $^

$(SALES_ITEM_LIB): $(SALES_ITEM_OBJ)
	ar rcs $@ $^

$(FLOW_CONTROL): $(FLOW_CONTROL_OBJ)
	$(CC) $(LDFLAGS) -o $@ $<

$(BASIC_IO): $(BASIC_IO_OBJ)
	$(CC) $(LDFLAGS) -o $@ $<

$(HELLOWORLD): $(HELLOWORD_OBJ)
	$(CC) $(LDFLAGS) -o $@ $<

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CPPFLAGS) -c -o $@ $<

.PHONY: clean
clean:
# Clean up executables
	rm $(HELLOWORLD) \
       $(BASIC_IO) \
       $(FLOW_CONTROL) \
       $(SALES_ITEM_LIB) \
       $(BOOK_STORE)
# Clean up object files
	rm $(HELLOWORD_OBJ) \
       $(BASIC_IO_OBJ) \
       $(FLOW_CONTROL_OBJ) \
       $(SALES_ITEM_OBJ) \
       $(BOOK_STORE_OBJ)