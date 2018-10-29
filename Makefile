default: build

build:
	g++ -c MST.cpp
	g++ -c UnionFind.cpp
	g++ -o MST.out MST.o UnionFind.o
	#g++ -o MST.out MST.cpp UnionFind.cpp

run: build
	./MST.out 8 test_graph.txt

debug:
	#g++ -g MST.cpp
	#g++ -g UnionFind.cpp
	#g++ -o MSTdebug.out MST.o UnionFind.o
	g++ -o MSTDebug.out MST.cpp UnionFind.cpp
	gdb MSTDebug.out
	

clean:
	rm -f MST