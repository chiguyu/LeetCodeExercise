#include <iostream>
#include <list>
#include <iterator>
#include <map>
#include <algorithm>

using namespace std;

/*
1.使用双向链表保存数据，node格式为pair<key,value>
2.使用map保存key及在双向链表中对应的迭代器
3.利用map可以logn时间复杂度内获取到迭代器，进一步获取到value; 同时可以使用list容器的slice函数常数时间内做node的移动
*/
class LRUCache {
private:
    int cap;
    list<pair<int,int>> lst;
    map<int, list<pair<int,int>>::iterator> mp;

public:
    LRUCache(int capacity) : cap(capacity){
    }

    int get(int key) {
        int res = -1;
        auto it = mp.find(key);
        if (it != mp.end()) {
            res = it->second->second;
            lst.splice(lst.begin(), lst, it->second);
        }
        return res;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        if (it != mp.end()) {
            it->second->second = value;
            lst.splice(lst.begin(), lst, it->second);
        } else {
            lst.push_front(std::make_pair(key, value));
            mp[key] = lst.begin();
            if (lst.size() > cap) {
                mp.erase(lst.rbegin()->first);
                lst.pop_back();
            }
        }
    }
};