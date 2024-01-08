all: compile link

compile:
	g++ -c main.cpp -I"D:\System_setup\sfml\SFML-2.6.1\include"

link:
	g++ main.o -o main -L"D:\System_setup\sfml\SFML-2.6.1\lib" -lsfml-graphics -lsfml-window -lsfml-system
clean:
	del main.exe main.o




test_all: test_compile test_link

test_compile:
	g++ -c test.cpp -I"D:\System_setup\sfml\SFML-2.6.1\include"

test_link:
	g++ test.o -o test -L"D:\System_setup\sfml\SFML-2.6.1\lib" -lsfml-graphics -lsfml-window -lsfml-system
test_clean:
	del test.exe test.o