default: build

build:
	g++ -c MST.cpp
	g++ -c UnionFind.cpp
	g++ -o MST.out MST.o UnionFind.o

run: build
	./MST.out 8 test_graph.txt

debug:
	g++ -g MST.cpp
	g++ -g UnionFind.cpp
	g++ -o MSTdebug.out MST.o UnionFind.o
	gdb MSTdebug.out

clean:
	rm -f MST