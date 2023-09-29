all:
	g++ main.cpp -o program `sdl2-config --cflags --libs`

run:
	./program

clean:
	rm -f ./program
