CC = g++

CFLAGS = -lSDL2 -lSDL2_image

DEPS = Game.hpp RenderWindow.hpp TextureManager.hpp Gameobject.hpp Map.hpp

OBJ = main.o Game.o RenderWindow.o TextureManager.o Gameobject.o Map.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
	
BB_RingMaster: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	
clean:
	rm -rf *o BB_RingMaster
