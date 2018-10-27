//author: Lisa Hartmann Jensen
#include "UnionFind.h"

UnionFind::UnionFind(int v){
    parents [v];
    size[v];

    for(int i = 0; i < v; i++){
        parents[i] = i;
        size[i] = 1;
    }
}

//what is the root of the tree x is in
int UnionFind::find(int x){
    if (x != parents[x]){
        parents[x] = find(parents[x]);
    }
    return parents[x];
}

//join two elements if they do not have the same root
void UnionFind::join(int y, int z){
    int rootP = find(y);
    int rootQ = find(z);
    
    if (connected(rootP, rootQ)) return;

    // make smaller root point to larger one
    if (size[rootP] < size[rootQ]) {
    parents[rootP] = rootQ;
    size[rootQ] += size[rootP];
    } else {
    parents[rootQ] = rootP;
    size[rootP] += size[rootQ];
    }
}
    

//are these two connected
bool UnionFind::connected(int y, int z){
    return find(y) == find(z);
}