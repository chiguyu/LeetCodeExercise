#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    // 初始化图节点、连接关系
    void initGraphic(vector<string>& wordList, unordered_map<string, set<string>>& mp) {
        for (auto &x : wordList) {
            for (int i = 0; i < x.size(); i++) {
                string temp = x;
                temp.replace(i, 1, "_");
                mp[temp].insert(x);
            }
        }
    }

    // BFS 思路
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (std::find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }
        
        unordered_map<string, set<string>> mp;
        initGraphic(wordList, mp);

        queue<pair<string, int>> que;  // 迭代队列
        que.push(std::make_pair(beginWord, 1));
        unordered_map<string, int> visited; // 记录字典中各个单词是否被访问
        // BFS处理队列中各个节点
        while (!que.empty()) {
            auto &ft = que.front();
            visited.insert(ft); // 更新访问状态
            // 将下一层的单词加入到队列中
            for (int i = 0; i < ft.first.size(); i++) {
                string temp = ft.first;
                temp.replace(i, 1, "_");
                for (auto &x : mp[temp]) {                    
                    if (visited.find(x) == visited.end()) {
                        if (x == endWord) {
                            // 找到endWord，完成接龙
                            return ft.second + 1;
                        } else { // 未访问过，且非endWord加到队列中
                            que.push(make_pair(x, ft.second + 1));
                        }
                    }                    
                }
            } 

            que.pop();           
        }

        return 0;
    }

    void BfsNextLevel(unordered_map<string, set<string>>& mp, queue<pair<string, int>>& que, unordered_map<string, int>& visited) {
        auto &ft = que.front();
        visited.insert(ft); // 更新访问状态
        // 将下一层的单词加入到队列中
        for (int i = 0; i < ft.first.size(); i++) {
            string temp = ft.first;
            temp.replace(i, 1, "_");
            for (auto &x : mp[temp]) {
                // 未访问过，加到队列中
                if (visited.find(x) == visited.end()) {
                    que.push(make_pair(x, ft.second + 1));
                }                    
            }
        }
        que.pop();   
    }

    // 双向广度优先搜索
    int ladderLength1(string beginWord, string endWord, vector<string>& wordList) {
        if (std::find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }

        unordered_map<string, set<string>> mp;
        initGraphic(wordList, mp);

        queue<pair<string, int>> queBeg;  // 迭代队列
        queBeg.push(std::make_pair(beginWord, 1));
        unordered_map<string, int> visitedBeg; // 记录字典中各个单词是否被访问

        queue<pair<string, int>> queEnd;  // 迭代队列
        queEnd.push(std::make_pair(endWord, 1));
        unordered_map<string, int> visitedEnd; // 记录字典中各个单词是否被访问

        // 处理队列中各个节点
        while (!queBeg.empty() || !queEnd.empty()) {
            if (!queBeg.empty()) {
                BfsNextLevel(mp, queBeg, visitedBeg);
                for (auto &x : visitedBeg) {
                    if (visitedEnd.find(x.first) != visitedEnd.end()) {
                        return x.second + visitedEnd[x.first] - 1;
                    }
                }
            }

            if (!queEnd.empty()) {
                BfsNextLevel(mp, queEnd, visitedEnd);
                for (auto &x : visitedEnd) {
                    if (visitedBeg.find(x.first) != visitedBeg.end()) {
                        return x.second + visitedBeg[x.first] - 1;
                    }
                }
            }
        }

        return 0;
    }
};

int main() {
    Solution s;
    string beg = "kiss";
    string end = "tusk";
    vector<string> test = {"miss","dusk","kiss","musk","tusk","diss","disk","sang","ties","muss"};
    cout << s.ladderLength1(beg, end, test);
    return 0;
}