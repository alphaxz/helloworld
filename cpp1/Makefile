CC=g++
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=helloworld
SRC= $(wildcard *.cpp) 
OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)

%.o: %.cpp
	@$(CC) -o $@ -c $< $(CFLAGS)

helloworld: $(OBJ) 
	@$(CC) -o $@ $^ $(LDFLAGS)

