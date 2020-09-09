all: Ex4.cpp Btree.h Btree.cpp
	g++ Ex4.cpp Btree.cpp -o ex4
all-GDB: Ex4.cpp
	g++ -g Ex4.cpp Btree.cpp -o ex4
