//author: Lisa Hartmann Jensen

#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>

#include "UnionFind.h"

struct Edge
{
    int from;
    int to;
    long weight;

    //constructor of an edge
    Edge(int from, int to, long weight): from(from), to(to), weight(weight)
    {}

    //comparator of edges
    bool operator<(const Edge& e) const{
        return weight < e.weight;
    }
};


//read in the file format: vertex1 vertex2 edgeWeight 
void fill_vector(std::vector<Edge>& edges, char *filename, int v){
    long start;
    long end;
    long weight;

    std::ifstream source = std::ifstream(filename);
    std::string line;

    while(std::getline(source, line)){
        std::istringstream in = std::istringstream(line);

        in >> start;
        in >> end;
        in >> weight;
        
        if(start > v){
            v = start;
        }
        
        if (end > v) {
            v = end;
        }

        Edge e(start, end, weight);
        edges.push_back(e);
         
    }
}

int main(int argc, char** args){

    int n = std::atoi(args[1]);
    char* filename = args[2];
    int v = 0;

    std::vector<Edge> edges;
    edges.reserve(n);
    fill_vector(edges, filename, v);

    //sort edges by weight from least to greatest
    std::sort(edges.begin(), edges.end());

    UnionFind uf(v);
    long MSTsum = 0;
    
    for(int i = 0; i < edges.size(); i++){
        Edge e = edges[i];
        //it not connected
        if(uf.connected(e.from, e.to)) continue;
        //call Union
        uf.join(e.from, e.to);
        //add weight to MST sum
        MSTsum = MSTsum + e.weight;
    }
    //return sum of the weights
    std::cout << MSTsum;
    return MSTsum;
}