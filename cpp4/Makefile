CC=g++
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=

EXECDIR=exec
EXEC=$(addprefix $(EXECDIR)/, helloworld)

INCDIR=include test
INCFLAGS=$(foreach d, $(INCDIR), -I$d)

SRCDIR=source
SRC=$(wildcard $(SRCDIR)/*.cpp)

OBJDIR=obj
OBJ=$(addprefix $(OBJDIR)/, $(notdir $(SRC:.cpp=.o)))

TESTDIR=test
TESTSRC=$(wildcard $(TESTDIR)/*.cpp)
TESTOBJ=$(TESTSRC:.cpp=.o)
TESTEXEC=$(addprefix $(TESTDIR)/, testexec)

all: $(EXEC)

.PHONY: clean mrproper doc

clean:
	@rm -rf $(OBJ) $(TESTOBJ)

mrproper: clean
	@rm -rf $(EXEC) $(TESTEXEC)

doc:
	@doxygen Doxyfile

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@$(CC) -o $@ -c $< $(CFLAGS) $(INCFLAGS)

$(EXEC): $(OBJ) 

$(TESTDIR)/%.o: $(TESTDIR)/%.cpp
	@$(CC) -o $@ -c $< $(CFLAGS) $(INCFLAGS)

$(TESTEXEC): $(TESTOBJ) $(OBJ) 
	@$(CC) -o $@ $^ -lcppunit

test: $(TESTEXEC)
