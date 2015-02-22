/*
 * =====================================================================================
 *
 *       Filename:  LRU_cache_3rd.cc
 *
 *    Description:  lru cache, 3rd try
 *
 *        Created:  02/22/2015 01:27:49
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class LRUCache{
public:
    LRUCache(int capacity) {
        cacheSize = capacity;
    }
    
    int get(int key) {
        // not present
        if(cacheMap.find(key) == cacheMap.end()){
            return -1;
        }
        
        auto pos = cacheMap[key];
        cacheList.splice(cacheList.begin(), cacheList, pos);
        cacheMap[key] = cacheList.begin();
        return pos->second;
    }
    
    void set(int key, int value) {
        if(cacheMap.find(key) == cacheMap.end()){
            // not full
            if(cacheList.size() == cacheSize){
                cacheMap.erase(cacheList.back().first);
                cacheList.pop_back();
            }
            
            cacheList.push_front(make_pair(key, value));
            cacheMap[key] = cacheList.begin();
        }
        else{
            auto pos = cacheMap[key];
            pos->second = value;
            cacheList.splice(cacheList.begin(), cacheList, pos);
            cacheMap[key] = cacheList.begin();
        }
    }
    
private:
    int cacheSize;
    list<pair<int, int> > cacheList;
    unordered_map<int, list<pair<int, int> >::iterator> cacheMap;  // map key to its location in the list
};


