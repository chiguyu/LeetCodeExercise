#include <vector>
#include <unordered_map>

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
    vector<int> findRedundantConnection(const vector<vector<int>>& edges, const vector<int> & skip) {
        vector<int> res;
        int length = edges.size();
        DisjSet dset(length + 1);
        for (auto edge : edges) {
            if (edge[0] == skip[0] && edge[1] == skip[1]) {
                continue;
            }
            if (dset.IsConnected(edge[0], edge[1])) {
                res = edge;
                break;
            }
            dset.DoUnion(edge[0], edge[1]);
        }
        return res;
    }

    bool hasCircle(const vector<vector<int>>& edges, const vector<int> & skip) {
        vector<int> res = findRedundantConnection(edges, skip);
        return res.size() != 0;
    }

    vector<int> findRedundantDirectedConnection(const vector<vector<int>>& edges) {
        vector<int> res;
        int max_size = edges.size();
        unordered_map<int, vector<int>> mp;  //KEY为当前节点编号，Value为父节点数组
        int double_parent_id = -1;
        /* 遍历所有的边，找到入度为2的点并储存在hash中，若入度为2的点不存在则存在环 */
        for (int i = 0; i < max_size; i++) {
            mp[edges[i][1]].push_back(edges[i][0]);
            if (mp[edges[i][1]].size() == 2) {
                double_parent_id = edges[i][1];
                break;                
            }            
        }

        vector<int> skip;
        if (double_parent_id == -1) { // 入度为2的点不存在,按无向图处理
            skip = {double_parent_id, double_parent_id};
            res = findRedundantConnection(edges, skip);
        } else { // 入度为2的点对应的2条边，必有一条是冗余边
            skip = {mp[double_parent_id].back(), double_parent_id};
            if (!hasCircle(edges, skip)) {
                return skip;
            } else {
                return {mp[double_parent_id].front(), double_parent_id};
            }
        }

        return res;
    }
};