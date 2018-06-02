CXX = g++
CXXFLAGS = -Wall -std=c++11
LDFLAGS = -g
RM = rm -rf

cbtc: FieldElement.o Point.o fieldelement_tests.o
	$(LDFLAGS) FieldElement.o Point.o fieldelement_tests.o -o cbtc

# Classes
FieldElement.o: ./FieldElement/FieldElement.cpp
	$(CXX) $(CXXFLAGS) -c ./FieldElement/FieldElement.cpp

Point.o: ./Point/Point.cpp
	$(CXX) $(CXXFLAGS) -c ./Point/Point.cpp

clean: 
	$(RM) *o cbtc
	$(RM) *_tests
