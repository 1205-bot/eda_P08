# Compilador 
CC = gcc

# Banderas de compilacion 
CFLAGS = -Wall -Wextra -Iinclude

# Archivos a compiar
SRC = src/*.c main.compiar.c

# Nombre del ejecutable
TARGET = Lista_ligada

# Regla principal para compilar
all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Regla para ejecutar
run: all
	./$(TARGET)

# Regla para borrar los archivos generados al compilador
clean:
	rm -f $(TARGET)