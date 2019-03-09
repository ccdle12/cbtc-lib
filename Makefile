CXX = g++
CXXFLAGS = -Wall -std=c++11
LDFLAGS = -g
RM = rm -rf

build: FieldElement.o Point.o S256Point.o
	$(LDFLAGS) FieldElement.o Point.o S256Point.o

# Classes.
FieldElement.o: ./FieldElement/FieldElement.cpp
	$(CXX) $(CXXFLAGS) -c ./FieldElement/FieldElement.cpp

Point.o: ./Point/Point.cpp
	$(CXX) $(CXXFLAGS) -c ./Point/Point.cpp

S256Point.o: ./S256Point/S256Point.cpp
	$(CXX) $(CXXFLAGS) -c ./S256Point/S256Point.cpp

# Tests.
check:
	@./scripts/test_cbtc all

clean: 
	$(RM) *o cbtc
	$(RM) *_tests
