#include <iostream>
#include <list>
#include <iterator>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        unordered_map<int, std::pair<int,int>>::iterator it = mp.find(key);
        if(it != mp.end()) {
            l.splice(l.begin(), l, std::find(l.begin(), l.end(), it->second));
            return it->second.second;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        unordered_map<int, std::pair<int,int>>::iterator it = mp.find(key);
        if(it != mp.end()) {
            l.erase(std::find(l.begin(), l.end(), it->second));
            it->second.second = value;
            l.push_front(it->second);
        } else {
            std::pair<int,int> temp = std::make_pair(key, value);
            mp[key] = temp;
            l.push_front(temp);
            if(l.size() > cap) {
                mp.erase(l.rbegin()->first);
                l.pop_back();               
            }
        }
    }

private:
    unordered_map<int, std::pair<int,int>> mp;
    std::list<std::pair<int,int>> l;
    int cap;
};