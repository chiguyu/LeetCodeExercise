#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct pos
{
    int pos_x;  // 记录行
    int pos_y;  // 记录列
    int time;   // 记录腐烂时间，即BFS层数
};

class Solution {
private:
    queue<pos> que;
    int cnt_fresh = 0;
    int rott_time = 0;

public:
    void rott(vector<vector<int>>& grid, pos cur) {
        grid[cur.pos_x][cur.pos_y] = 2;
        cnt_fresh--;
        rott_time = cur.time; //记录腐烂时间
        que.push(cur);        
    }

    int orangesRotting(vector<vector<int>>& grid) {        
        int rows = grid.size();
        int cols = grid[0].size();       
        /* 遍历初始化最开始腐烂橘子位置，腐烂时间初始化为0；统计新鲜橘子个数 */
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    struct pos rott = {i, j, 0};
                    que.push(rott);
                }
                if (grid[i][j] == 1) {
                    cnt_fresh++;
                }
            }
        }

        /* BFS处理上下左右四个方向的新鲜橘子，并记录腐烂时间 */
        while (!que.empty() && cnt_fresh > 0) {
            struct pos cur = que.front();
            if (cur.pos_x - 1 >= 0 && grid[cur.pos_x - 1][cur.pos_y] == 1) {
                struct pos up = {cur.pos_x - 1, cur.pos_y, cur.time + 1};
                rott(grid, up);
            }
            if (cur.pos_y - 1 >= 0 && grid[cur.pos_x][cur.pos_y - 1] == 1) {
                struct pos left = {cur.pos_x, cur.pos_y - 1, cur.time + 1};
                rott(grid, left);
            }            
            if (cur.pos_x + 1 < rows && grid[cur.pos_x + 1][cur.pos_y] == 1) {
                struct pos down = {cur.pos_x + 1, cur.pos_y, cur.time + 1};
                rott(grid, down);
            }
            if (cur.pos_y + 1 < cols && grid[cur.pos_x][cur.pos_y + 1] == 1) {
                struct pos right = {cur.pos_x, cur.pos_y + 1, cur.time + 1};
                rott(grid, right);
            }
            que.pop();
        }

        /* 若不再存在新鲜橘子则返回res，否则返回-1 */
        if (cnt_fresh == 0) {
            return rott_time;
        } else {
            return -1;
        }        
    }
};