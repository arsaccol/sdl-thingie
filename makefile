all:
	g++ main.cpp -o program `sdl2-config --cflags --libs`

clean:
	rm -f ./program
