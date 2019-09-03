
CXX = g++
CXXFLAGS = -Wall -g -std=c++0x

zoo: main.o Zoo.o Animal.o Tiger.o Penguin.o Turtle.o gameFunctions.o
	$(CXX) $(CXXFLAGS) main.o Zoo.o Animal.o Tiger.o Penguin.o Turtle.o gameFunctions.o -o zoo

main.o: main.cpp Zoo.hpp gameFunctions.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Zoo.o: Zoo.hpp

Animal.o: Animal.hpp

Tiger.o: Tiger.hpp

Penguin.o: Penguin.hpp

Turtle.o: Turtle.hpp

gameFunctions.o: gameFunctions.hpp

clean:
	rm *.o zoo
