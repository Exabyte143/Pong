all: compile link delete

compile:
	g++ -Isrc/include -c main.cpp

link:
	g++ main.o -o pong -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

delete:
	del main.o