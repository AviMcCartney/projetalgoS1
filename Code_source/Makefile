BIN= application
OBJECTS = main.o fonctions_operations.o
CC = gcc

all: $(OBJECTS)
	 $(CC) $(OBJECTS) -o $(BIN)

main.o : main.c prototype.h
	 $(CC) -c main.c

vitesse.o : prototype.h fonctions_operations.c
	 $(CC) -c fonctions_operations.c

clean:
	 rm -f $(OBJECTS) $(BIN)