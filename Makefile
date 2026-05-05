# Variables: nombres y rutas
CC = gcc
CFLAGS = -Wall -Iinclude
LDFLAGS = -Llib -lraylib -lopengl32 -lgdi32 -lwinmm
SRC = src/main.c
OBJ = bin/juego.exe

# Regla principal: qué pasa cuando escribís 'make'
all:
	$(CC) $(SRC) -o $(OBJ) $(CFLAGS) $(LDFLAGS)

# Regla para limpiar la carpeta bin
clean:
	rm -f bin/*.exe