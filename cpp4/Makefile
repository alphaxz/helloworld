CC=g++
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=

LIBDIR=lib
LIBNAME=helloworld
LIB=$(addprefix $(LIBDIR)/, libhelloworld.so)

INCDIR=include
INCFLAGS=$(foreach d, $(INCDIR), -I$d)

SRCDIR=source
SRC=$(wildcard $(SRCDIR)/*.cpp)

OBJDIR=obj
OBJ=$(addprefix $(OBJDIR)/, $(notdir $(SRC:.cpp=.o)))

TESTDIR=test
TESTSRC=$(wildcard $(TESTDIR)/*.cpp)
TESTOBJ=$(TESTSRC:.cpp=.o)
TESTEXEC=$(addprefix $(TESTDIR)/, testexec)

all: $(LIB)

.PHONY: clean mrproper doc

clean:
	@rm -rf $(OBJ) $(TESTOBJ)

mrproper: clean
	@rm -rf $(LIB) $(TESTEXEC)

doc:
	@doxygen Doxyfile

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@$(CC) -o $@ -c $< $(CFLAGS) $(INCFLAGS)

$(LIB): $(OBJ) 
	@$(CC) -fPIC -shared -o $(LIB) $^

$(TESTDIR)/%.o: $(TESTDIR)/%.cpp
	@$(CC) -o $@ -c $< $(CFLAGS) $(INCFLAGS)

$(TESTEXEC): $(TESTOBJ) $(LIB)
	@$(CC) -o $@ $^ -L$(LIBDIR) -lcppunit -l$(LIBNAME)

test: $(TESTEXEC)
	@LD_LIBRARY_PATH=LD_LIBRARY_PATH:./$(LIBDIR) ./$(TESTEXEC)
	
