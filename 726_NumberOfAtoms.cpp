#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        string res;
        map<string,int> resMap;  // 用于记录原子数目
        int r = dfs(formula, 0, resMap);
        // 输出
        for (auto & x : resMap) {
            res.append(x.first);
            if (x.second > 1) {
                res.append(to_string(x.second));
            }
        }
        return res;
    }
    
    // dfs算法进行统计
    int dfs(const string& formula,int beg,map<string,int>& resMap){
        int index = beg;
        while(index < formula.size()){
            //第一个是否是大写字母
            if(formula[index] == '('){
                map<string,int> sub;
                index = dfs(formula, ++index, sub) + 1;

                // 获取倍数，可能是多个数字
                int multi = 0;
                while (index < formula.size() && isdigit(formula[index])){
                    multi = multi * 10 + formula[index] - '0';
                    index++;
                }
                multi = multi == 0 ? 1 : multi;

                // 累加括号内的计数
                for(auto & x : sub){
                    resMap[x.first] += x.second * multi;
                }
            } else if(formula[index]==')'){
                break;
            } else{
                // 处理原子名
                string key;
                key.append(1, formula[index]);
                if (islower(formula[++index])) {
                    key.append(1, formula[index++]);
                }

                // 处理原子数目，可能是多个数字
                int value = 0;
                while (index < formula.size() && isdigit(formula[index])){
                    value = value * 10 + formula[index] - '0';;
                    index++;
                }
                value = value == 0 ? 1 : value;

                // 将原子数目记录到resMap中
                resMap[key] = resMap[key] + value;
            }
        }
        return index;
    }
};

int main() {
    Solution s;
    cout << s.countOfAtoms("Be32");
    return 0;
}