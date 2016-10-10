test: main.o sprites.o
	g++ main.o sprites.o -o test.exe -lsfml-graphics -lsfml-window -lsfml-system -lsfml-system -lsfml-audio
main.o: main.cpp
	g++ -c main.cpp
sprites.o: sprites.cpp
	g++ -c sprites.cpp
clean:
	 rm *.o *.exe
