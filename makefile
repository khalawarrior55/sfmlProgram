test: main.o
	g++ main.o -o test -lsfml-graphics -lsfml-window -lsfml-system -lsfml-system -lsfml-audio
main.o: main.cpp
	g++ -c main.cpp
clean:
	 rm *.o test
