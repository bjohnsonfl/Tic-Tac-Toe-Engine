CXX = g++
CXXFLAGS = -Wall -g -std=c++11
#-std=gnu++14

objects = main.o bitboard.o movegen.o position.o search.o types.o

ticTacToe: $(objects)
	$(CXX) $(CXXFLAGS) -o ticTacToe $(objects)
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp
bitboard.o: bitboard.cpp
	$(CXX) $(CXXFLAGS) -c bitboard.cpp
movegen.o: movegen.cpp
	$(CXX) $(CXXFLAGS) -c movegen.cpp
position.o: position.cpp
	$(CXX) $(CXXFLAGS) -c position.cpp
search.o: search.cpp
	$(CXX) $(CXXFLAGS) -c search.cpp
types.o: types.cpp types.hpp
	$(CXX) $(CXXFLAGS) -c types.cpp
clean :
	rm ticTacToe $(objects)
