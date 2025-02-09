CC = gcc
CFLAGS = -Wall -Iinclude
LDFLAGS = -Llib -lraylib -lopengl32 -lgdi32 -lwinmm

SRC = src/test1.c
TARGET = exe/SimpleApp.exe

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) -o $@

clean:
	del /q exe\*.exe
