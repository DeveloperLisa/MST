#include<vector>

class UnionFind{

std::vector<int> parents;
std::vector<int> size;

public: UnionFind(int v);

int find(int x);

void join(const int & y, const int & z);

bool connected(const int & y, const int & z);

};
