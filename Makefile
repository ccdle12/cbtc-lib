CXX = g++
CXXFLAGS = -Wall -std=c++11 -g
LDFLAGS = -g
RM = rm -rf

cbtc: FieldElement.o Point.o fieldelement_tests.o
	$(LDFLAGS) FieldElement.o Point.o fieldelement_tests.o -o cbtc

# Classes
FieldElement.o: ./FieldElement/FieldElement.cpp
	$(CXX) $(CXXFLAGS) -c ./FieldElement/FieldElement.cpp

Point.o: ./Point/Point.cpp
	$(CXX) $(CXXFLAGS) -c ./Point/Point.cpp

# Tests
fieldelement_tests.o: ./FieldElement/fieldelement_tests.cpp
	$(CXX) $(CXXFLAGS) -c ./FieldElement/fieldelement_tests.cpp

test:
	$(CXX) -o fieldelement_tests -lboost_unit_test_framework ./FieldElement/fieldelement_tests.cpp && ./fieldelement_tests --log_level=test_suite	
	$(CXX) -o point_tests -lboost_unit_test_framework ./Point/point_tests.cpp && ./point_tests --log_level=test_suite§	
clean: 
	$(RM) *o cbtc
	$(RM) *_tests
