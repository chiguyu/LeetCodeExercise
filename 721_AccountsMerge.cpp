#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

/* 并查集类模板实现 */
class DisjSet {
private:
    int count;  // 连通分量个数    
    vector<int> parent;  //记录每个节点的父节点，模拟一颗树    
    vector<int> rank;  //当前节点所在树包含节点总数
public:
    DisjSet(int max_size) : count(max_size), parent(std::vector<int>(max_size)), rank(std::vector<int>(max_size, 1)){
        for (int i = 0; i < max_size; ++i)
            parent[i] = i;
    }
    
    /* 将 p 和 q 连接 */
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

     /* 判断 p 和 q 是否连通 */
    bool IsConnected(int p, int q) {
        return FindRoot(p) == FindRoot(q);
    }

    /* 返回节点的根节点 */
    int FindRoot(int x) {
        while (parent[x] != x) {
            // 进行路径压缩
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    /* 返回图中有多少个连通分量 */
    int GetCount() {
        return count;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int len = accounts.size();
        DisjSet dset(len);

        /* 哈希表mp_email_id记录，string:邮箱  int:首次出现该邮箱的index
         * 遍历每个账号的所有邮箱，当邮箱重复出现时，将2个index连接 */
        unordered_map<string, int> mp_email_id; //
        for (int i = 0; i < len; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (mp_email_id.find(accounts[i][j]) != mp_email_id.end()) {
                    dset.DoUnion(mp_email_id[accounts[i][j]], i);
                } else {
                    mp_email_id[accounts[i][j]] = i;
                }
            }
        }

        /* 哈希表mp_accounts记录，int:在输入accounts中的index  string:账户名  set<string>:邮箱
         * 遍历所有出现过的邮箱，哈希表mp_accounts记录合并后的账号 */
        unordered_map<int, pair<string, set<string>>> mp_accounts;
        for (auto it = mp_email_id.begin(); it != mp_email_id.end(); it++) {
            int root = dset.FindRoot(it->second);
            if (mp_accounts.find(root) == mp_accounts.end()) {
                string name = accounts[it->second][0];
                set<string> emails;
                emails.insert(it->first);
                mp_accounts[root] = std::make_pair(name, emails);
            } else {
                mp_accounts[root].second.insert(it->first);
            }
        }

        /* 按要求格式组合出返回值 */
        vector<vector<string>> res;
        for (auto it = mp_accounts.begin(); it != mp_accounts.end(); it++) {
            vector<string> account;
            account.push_back((it->second).first);
            account.insert(account.end(), (it->second).second.begin(), (it->second).second.end());
            res.push_back(account);
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<vector<string>> test = {{"John", "johnsmith@mail.com", "john00@mail.com"},
                                   {"John", "johnnybravo@mail.com"},
                                   {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
                                   {"Mary", "mary@mail.com"}};
    vector<vector<string>> res = s.accountsMerge(test);
    for (auto acc : res) {
        for (auto str : acc) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}