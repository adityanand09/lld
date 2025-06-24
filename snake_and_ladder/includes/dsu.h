#include <vector>

class DSU {
    private:
        std::vector<int> m_parent;
        std::vector<int> m_size;
    public:
        DSU(int n);
        int findParent(int node);
        void unite(int node1, int node2);
        bool connected(int node1, int node2);
};