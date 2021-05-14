#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& board, int row, int col) {
        if (board[row][col] == 'O') {
            board[row][col] = 'A';
            if(row - 1 >= 0)
                dfs(board, row - 1, col);
            if(row + 1 < board.size())
                dfs(board, row + 1, col);
            if(col - 1 >= 0)
                dfs(board, row, col - 1);
            if(col + 1 < board[0].size())
                dfs(board, row, col + 1);           
        }
    }

    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        if (rows <= 2 || cols <= 2)
            return;
        
        for (int col = 0; col < cols; col++) {
            if (board[0][col] == 'O') {   // 遍历第一行中的'O'
                dfs(board, 0, col);                
            }
            if (board[rows - 1][col] == 'O') { // 遍历最后一行中的'O'
                dfs(board, rows - 1, col);               
            }
        }

        for (int row = 1; row < rows - 1; row++) {
            if (board[row][0] == 'O') {  // 遍历第一列中的'O'
                dfs(board, row, 0);                
            }
            if (board[row][cols - 1] == 'O') { // 遍历最后一列中的'O'
                dfs(board, row, cols - 1);               
            }
        }

        for (int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {
                if (board[row][col] == 'O') {
                    board[row][col] = 'X';
                } else if (board[row][col] == 'A') {
                    board[row][col] = 'O';
                }
            }
        }
    }
};