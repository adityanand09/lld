#include "dsu.h"

DSU::DSU(int n) : m_parent(n), m_size(n, 1) {
    for (int i = 0; i < n; ++i) {
        m_parent[i] = i;
    }
}

int DSU::findParent(int node) {
    if (m_parent[node] != node) {
        m_parent[node] = findParent(m_parent[node]);
    }
    return m_parent[node];
}

void DSU::unite(int node1, int node2) {
    int root1 = findParent(node1);
    int root2 = findParent(node2);

    if (root1 != root2) {
        if (m_size[root1] < m_size[root2]) {
            std::swap(root1, root2);
        }
        m_parent[root2] = root1;
        m_size[root1] += m_size[root2];
        m_size[root2] = 0;
    }
}

bool DSU::connected(int node1, int node2) {
    return findParent(node1) == findParent(node2);
}