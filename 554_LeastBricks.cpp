#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int heighth=wall.size();
        unordered_map<int,int> mp;
        for(int i=0;i<heighth;i++) {
            int sum=0;
            int width=wall[i].size();
            for(int j=0;j<width-1;j++){
                sum+=wall[i][j];
                mp[sum]++;
            }
        }
        int edges=0;
        unordered_map<int,int>::iterator it;
        for(it=mp.begin();it!=mp.end();it++){
            edges=max(edges,it->second);
        }  
        return heighth-edges;  
    }
};

int main() {
    Solution s;
    vector<vector<int>> test;
    test.push_back(vector<int> {1,2,2,1});
    test.push_back(vector<int> {3,1,2});
    test.push_back(vector<int> {1,3,2});
    test.push_back(vector<int> {2,4});
    test.push_back(vector<int> {3,1,2});
    test.push_back(vector<int> {1,3,1,1});
    int ret = s.leastBricks(test);
    cout << "ret : " << ret << endl;
    return 0;
}