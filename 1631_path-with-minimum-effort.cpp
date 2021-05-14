#include <vector>
#include <queue>

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
    struct cmp
    {
        bool operator()(const pair<pair<int,int>,int> & left, const pair<pair<int,int>,int> & right) {
            return left.second > right.second;
        }
    };
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        /* 按行优先为每个点编号，按向右、向下的方向计算出高度差，并压入最小优先队列 */
        int rows = heights.size();
        int cols = heights[0].size();
        priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>, cmp> pq;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int curPos = i * cols + j;
                if (i < rows - 1) { // 方向：下
                    pq.push(make_pair(make_pair(curPos, curPos + cols), abs(heights[i][j] - heights[i + 1][j])));
                }
                if (j < cols - 1) { //方向：右
                    pq.push(make_pair(make_pair(curPos, curPos + 1), abs(heights[i][j] - heights[i][j + 1])));
                }
            }
        }

        /* 利用并查集数据结构，依高度差从小到大顺序，连接对应两个点，直到起点和终点形成通路 */
        int max_size = rows * cols;
        DisjSet dset(max_size);
        int res = 0;
        while (!dset.IsConnected(0, max_size - 1) && !pq.empty()) {
            res = pq.top().second;
            dset.DoUnion(pq.top().first.first, pq.top().first.second);
            pq.pop();
        }

        return res;
    }
};