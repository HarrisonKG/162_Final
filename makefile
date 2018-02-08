######################################################################
# Program name: Final
# Author: Kristen Harrison
# Date: 16 August 2017
# Description: CS162, Final. This makefile can be run with three commands:
# 1. "make" makes the program Final   2. "make clean" cleans the directory   
# 3. "make memcheck" runs valgrind to test for memory leaks
######################################################################

# target: dependencies
# [tab] recipe


CXX = g++
CXXFLAGS = -std=c++0x -g -Wall
VALFLAGS = --tool=memcheck --leak-check=full --track-origins=yes --show-leak-kinds=all

OBJS = main.o Game.o Market.o Field.o Hut.o Mountain.o Tavern.o Space.o validateInput.o Player.o
HEADERS = Game.hpp Market.hpp Field.hpp Hut.hpp Mountain.hpp Tavern.hpp Space.hpp validateInput.hpp



Final: $(OBJS) 
	$(CXX) $(OBJS) -o Final

main.o: main.cpp Game.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Game.o: $(HEADERS) Game.cpp
	$(CXX) $(CXXFLAGS) -c Game.cpp

Player.o: Player.hpp Player.cpp validateInput.hpp Space.hpp Market.hpp
	$(CXX) $(CXXFLAGS) -c Player.cpp

Space.o: Space.hpp Space.cpp 
	$(CXX) $(CXXFLAGS) -c Space.cpp

Market.o: Market.hpp Market.cpp Space.hpp
	$(CXX) $(CXXFLAGS) -c Market.cpp

Field.o: Field.hpp Field.cpp Space.hpp
	$(CXX) $(CXXFLAGS) -c Field.cpp

Hut.o: Hut.hpp Hut.cpp Space.hpp
	$(CXX) $(CXXFLAGS) -c Hut.cpp

Tavern.o: Tavern.hpp Tavern.cpp Space.hpp
	$(CXX) $(CXXFLAGS) -c Tavern.cpp

Mountain.o: Mountain.hpp Mountain.cpp Space.hpp
	$(CXX) $(CXXFLAGS) -c Mountain.cpp

validateInput.o: validateInput.hpp validateInput.cpp
	$(CXX) $(CXXFLAGS) -c validateInput.cpp

clean:
	rm *.o Final

memcheck: Final
	valgrind $(VALFLAGS) ./Final
