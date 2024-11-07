CC = gcc
CFLAGS = -Wall -g
OBJ = main.o nvram.o

# The final executable
TARGET = nvram_app

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

main.o: main.c nvram.h
	$(CC) $(CFLAGS) -c main.c

nvram.o: nvram.c nvram.h
	$(CC) $(CFLAGS) -c nvram.c

clean:
	rm -f $(OBJ) $(TARGET)

