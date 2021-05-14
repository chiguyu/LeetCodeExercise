#include <vector>

using namespace std;

class DisjSet {
private:
    int count;  // 连通分量个数    
    vector<int> parent;  // 存储一棵树    
    vector<int> rank;  //记录树的“重量”
public:
    DisjSet(int max_size) : count(max_size), parent(std::vector<int>(max_size)), rank(std::vector<int>(max_size, 1)){
        for (int i = 0; i < max_size; ++i)
            parent[i] = i;
    }
    
    void DoUnion(int p, int q) {
        int rootP = FindRoot(p);
        int rootQ = FindRoot(q);
        if (rootP == rootQ)
            return;
        
        // 小树接到大树下面，较平衡
        if (rank[rootP] > rank[rootQ]) {
            parent[rootQ] = rootP;
            rank[rootP] += rank[rootQ];
        } else {
            parent[rootP] = rootQ;
            rank[rootQ] += rank[rootP];
        }
        count--;
    }

    bool IsConnected(int p, int q) {
        return FindRoot(p) == FindRoot(q);
    }

    int FindRoot(int x) {
        while (parent[x] != x) {
            // 进行路径压缩
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    int GetCount() {
        return count;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res;
        int length = edges.size();
        DisjSet dset(length + 1);
        for (auto edge : edges) {
            if (dset.IsConnected(edge[0], edge[1])) {
                res = edge;
                break;
            }
            dset.DoUnion(edge[0], edge[1]);
        }
        return res;
    }
};