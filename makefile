CC = cc
CFLAGS = `pkg-config --cflags raylib`
LDFLAGS = `pkg-config --libs raylib`
SRC = src/main.c src/globals.c src/physics.c src/game.c src/playing.c src/game_over.c src/victory.c src/player.c src/wall.c src/walls.c
TARGET = walls

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

debug: CFLAGS += -g -fsanitize=address
debug: $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all debug clean
