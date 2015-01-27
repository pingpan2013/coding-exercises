/*
 * =====================================================================================
 *
 *       Filename:  LRU_cache.cc
 *
 *    Description:  LRU Cache design
 *
 *        Created:  01/26/2015 23:27:51
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <unordered_map>
#include <list>
#include <iostream>

using namespace std;

class LRUCache{
public:
    LRUCache(int capacity) {
        cacheCapacity = capacity;
    }
    
    int get(int key) {
        auto itr = cacheMap.find(key);
        if(itr == cacheMap.end())    return -1;
        
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        cacheMap[key] = cacheList.begin();
        
        return *cacheMap[key];
    }
    
    void set(int key, int value) {
        auto itr = cacheMap.find(key);
        if(itr == cacheMap.end()){
            if(cacheList.size() == cacheCapacity){
                cacheMap.erase(cacheList.back());
                cacheList.pop_back();
            }
        
            cacheList.push_front(value);
            cacheMap[key] = cacheList.begin();
        }
        else{
            // shift
            *cacheMap[key] = value;
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            cacheMap[key] = cacheList.begin();
        }
    }

private:
    int cacheCapacity;
    list<int> cacheList;
    unordered_map<int, list<int>::iterator> cacheMap;
};


int main(){
    LRUCache cache(3);
    cache.set(2, 1);
    cache.set(3, 2);
    cache.set(4, 3);
    
    cache.set(4, 4);
    cout << cache.get(4) << endl;
    
    cache.set(3, 3);
    cout << cache.get(3) << endl;

    cache.set(5, 6);
    cout << cache.get(2) << endl;  // ERROR
    
    return 0;
}


