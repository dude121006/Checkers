all:
	g++ *.cpp -Isrc/include -Iinclude -o bin/main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system
	 cls
	./bin/main 