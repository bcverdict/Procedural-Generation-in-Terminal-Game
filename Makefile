Game: main.o Path.o Dialog.o Highlight.o Designs.o 
	g++ -std=c++11 -g -Wall main.o Path.o Dialog.o Highlight.o Designs.o -o Game -lncurses -pthread
main.o: main.cpp 
	g++ -std=c++11 -g -Wall -c main.cpp
Path.o: Path.cpp Path.h Dialog.h Highlight.h
	g++ -std=c++11 -g -Wall -c Path.cpp
Dialog.o: Dialog.cpp Dialog.h  
	g++ -std=c++11 -g -Wall -c Dialog.cpp
Highlight.o: Highlight.cpp Highlight.h
	g++ -std=c++11 -g -Wall -c Highlight.cpp
Designs.o: Designs.cpp Designs.h Node.hpp Node.h
	g++ -std=c++11 -g -Wall -c Designs.cpp
clean:
	rm *.o Game
