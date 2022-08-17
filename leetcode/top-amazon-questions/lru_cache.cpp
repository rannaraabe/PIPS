/*
Difficulty: Medium;

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
Implement the LRUCache class:

- LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
- int get(int key) Return the value of the key if the key exists, otherwise return -1.
- void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
- The functions get and put must each run in O(1) average time complexity.

Constraints:
1 <= capacity <= 3000
0 <= key <= 10^4
0 <= value <= 10^5
At most 2 * 10^5 calls will be made to get and put
*/

#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    int cap = 0;
    list<pair<int, int>> cache;
    map<int, list<pair<int, int>>::iterator> m; // key, it
    
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(m.find(key) != m.end()){
            int value = m[key]->second;
            put(key, value);
            return value;            
        }
        return -1;
    }
    
    void put(int key, int value) {        
        if(m.find(key) != m.end()){
            cache.erase(m[key]);
        } else {
            if(cache.size() == cap){
                m.erase(cache.back().first);
                cache.pop_back();
            }
        }
        
        cache.push_front({key, value});
        m[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */