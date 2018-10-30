default: build

build:
	g++ -o MST.out MST.cpp UnionFind.cpp

run: build
	./MST.out 8 test_graph.txt

debug:
	g++ -g -o MSTDebug.out MST.cpp UnionFind.cpp
	gdb MSTDebug.out

clean:
	rm -f MST