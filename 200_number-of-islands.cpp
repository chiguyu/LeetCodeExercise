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
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int num_zero = 0;
        /* 统计‘0’的数目 */
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '0') {
                    num_zero++;
                }
            }
        }

        /* 将所有陆地进行连接 */
        DisjSet dset(rows * cols);        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    int curPos = i * cols + j;
                    if (i < rows - 1 && grid[i + 1][j] == '1') { // down
                        dset.DoUnion(curPos, curPos + cols);
                    }
                    if (j < cols - 1 && grid[i][j + 1] == '1') { // right
                        dset.DoUnion(curPos, curPos + 1);
                    }
                }
            }
        }
        return dset.GetCount() - num_zero;
    }
};