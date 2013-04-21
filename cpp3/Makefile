CC=g++
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=

EXECDIR=exec
EXEC=$(addprefix $(EXECDIR)/, helloworld)

INCDIR=include
INCFLAGS=$(foreach d, $(INCDIR), -I$d)

SRCDIR=source
SRC=$(wildcard $(SRCDIR)/*.cpp)

OBJDIR=obj
OBJ=$(addprefix $(OBJDIR)/, $(notdir $(SRC:.cpp=.o)))

all: $(EXEC)

.PHONY: clean mrproper doc

clean:
	@rm -rf $(OBJ)

mrproper: clean
	@rm -rf $(EXEC)

doc:
	@doxygen Doxyfile

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@$(CC) -o $@ -c $< $(CFLAGS) $(INCFLAGS)

$(EXEC): $(OBJ) 
	@$(CC) -o $@ $^ $(LDFLAGS)

