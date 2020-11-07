CC = g++

all: Q2_SaveString.cpp Q2_SavestringMain.cpp
	$(CC) -c Q2_SaveString.cpp
	$(CC) -c Q2_SaveStringMain.cpp
	$(CC) -o Q2_SaveStringMain Q2_SaveString.o Q2_SaveStringMain.o

clean:
	rm -rf Q2_SaveString.o Q2_SaveStringMain.o Q2_SaveStringMain

test:
	@echo "Save String example"
