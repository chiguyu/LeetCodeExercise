#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    void Dfs(vector<vector<int>>& rooms, int room, set<int>& visited) {
        visited.insert(room);
        for (auto &key : rooms[room]) {
            if (visited.find(key) == visited.end()) {
                Dfs(rooms, key, visited);
            }            
        }
    }

    // dfs遍历方法
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set<int> visited;
        Dfs(rooms, 0, visited);
        return visited.size() == rooms.size();
    }
};