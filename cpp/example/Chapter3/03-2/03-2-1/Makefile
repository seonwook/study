CC = g++

all: Q1_CalculatorMain.cpp Q1_Calculator.cpp Q1_Calculator.h
	$(CC) -c Q1_Calculator.cpp
	$(CC) -c Q1_CalculatorMain.cpp
	$(CC) -o Q1_CalculatorMain Q1_Calculator.o Q1_CalculatorMain.o

clean:
	rm -rf Q1_CalculatorMain.o 
	rm -rf Q1_Calculator.o
	rm -rf Q1_CalculatorMain

test:
	@echo "Calculator example"
