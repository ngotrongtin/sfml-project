all: compile link

compile:
	g++ -c game.cpp -I"D:\System_setup\sfml\SFML-2.6.1\include"
	g++ -c main.cpp -I"D:\System_setup\sfml\SFML-2.6.1\include"

link:
	g++ main.o game.o -o game -L"D:\System_setup\sfml\SFML-2.6.1\lib" -lsfml-graphics -lsfml-window -lsfml-system
clean:
	del main.exe main.o game.o


test_all: test_compile test_link

test_compile:
	g++ -c wave.cpp -I"D:\System_setup\sfml\SFML-2.6.1\include"

test_link:
	g++ wave.o -o wave -L"D:\System_setup\sfml\SFML-2.6.1\lib" -lsfml-graphics -lsfml-window -lsfml-system
test_clean:
	del wave.exe wave.o 

