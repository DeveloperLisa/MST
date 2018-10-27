
class UnionFind{

public:
int *parents;
int *size;

public: UnionFind(int v);

int find(int x);

void join(int y, int z);

bool connected(int y, int z);

};
