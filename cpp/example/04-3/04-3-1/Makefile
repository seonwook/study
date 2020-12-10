CC = g++

all: Q1_Circle_class.cpp Q1_Circle_class.h Q1_CircleMain_class.cpp
	$(CC) -c Q1_Circle_class.cpp
	$(CC) -c Q1_CircleMain_class.cpp
	$(CC) -o Q1_CircleMain_class Q1_Circle_class.o Q1_CircleMain_class.o

clean:
	rm -rf ./*.o 
	rm -rf Q1_CircleMain_class

test:
	@echo "Circle_class example"
