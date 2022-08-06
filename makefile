exec: main.o Diver.o Meet.o Executive.o
	g++ -std=c++11 -g -Wall main.o Diver.o Meet.o Executive.o -o exec

main.o: main.cpp Diver.h Meet.h Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Diver.o: Diver.h Diver.cpp
	g++ -std=c++11 -g -Wall -c Diver.cpp

Meet.o: Meet.h Meet.cpp
	g++ -std=c++11 -g -Wall -c Meet.cpp

Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

clean:
	rm *.o exec
