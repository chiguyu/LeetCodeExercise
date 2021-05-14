#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> res;
        if (n == 1) {
            res = {0};
            return res;
        }
        if (n == 2) {
            res = {0, 1};
            return res;
        }

        vector<set<int>> graphic(n); //建立连接关系，graphic[i]为与节点i相连接的点
        for (auto edge : edges) {
            graphic[edge[0]].insert(edge[1]);
            graphic[edge[1]].insert(edge[0]);
        }

        queue<pair<int,int>> que;  //bfs使用队列实现，第1个数字是节点编号，第2个数字是所处层次，最外层为第一层
        for (int index = 0; index < graphic.size(); index++) {  //将最外层节点入队
            if (graphic[index].size() == 1) {
                que.push(make_pair(index,1));
            }
        }

        int left = n;  //剩余未处理的节点数
        while (que.size() != left || (que.size() == left && que.front().second != que.back().second)) { //依次处理每一层，直到只剩下最后一层
            int leave = que.front().first;
            int curLayer = que.front().second;
            que.pop();
            left--;
            auto upper = graphic[leave].begin();
            graphic[*upper].erase(leave);            
            if (graphic[*upper].size() == 1) {
                que.push(make_pair(*upper, curLayer + 1));
            }
            graphic[leave].clear();                  
        }

        while (!que.empty()) { //剩下的最后一层节点即为最终结果
            res.push_back(que.front().first);
            que.pop();
        }
         
        return res;
    }
};

int main() {
    Solution s;
    int n = 6;
    vector<vector<int>> test = {{3,0}, {3,1}, {3,2}, {3,4}, {5,4}};
    vector<int> result = s.findMinHeightTrees(n, test);
    for(auto i : result) {
        cout << i << endl;
    }
 
    return 0;
}