#!/bin/bash
./compile.sh
g++ -o fieldelement_tests -lboost_unit_test_framework fieldelement_tests.cpp && ./fieldelement_tests

