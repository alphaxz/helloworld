CC=g++
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=

EXECDIR=exec
EXEC=$(addprefix $(EXECDIR)/, helloworld)

SRCDIR=source
SRC=$(wildcard $(SRCDIR)/*.cpp)

OBJDIR=obj
OBJ=$(addprefix $(OBJDIR)/, $(notdir $(SRC:.cpp=.o)))

all: $(EXEC)

.PHONY: clean mrproper

clean:
	@rm -rf $(OBJ)

mrproper: clean
	@rm -rf $(EXEC)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@$(CC) -o $@ -c $< $(CFLAGS)

$(EXEC): $(OBJ) 
	@$(CC) -o $@ $^ $(LDFLAGS)

