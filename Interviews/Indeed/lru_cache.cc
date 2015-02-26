/*
 * =====================================================================================
 *
 *       Filename:  lru_cache.cc
 *
 *    Description:  lru cache
 *
 *        Created:  02/25/2015 23:42:24
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class LRU_Cache{
public:
    LRU_Cache(size_t _size){
        cacheSize = _size;
    }

    void set(int key, int value){
        // key not present
        if(cacheMap.find(key) == cacheMap.end()){
            // full
            if(cacheData.size() == cacheSize){
                cacheMap.erase(cacheData.back().first);
                cacheData.pop_back();
            }
            
            // insert the new pair
            cacheData.push_front(make_pair(key, value));
            cacheMap[key] = cacheData.begin();
        }
        // key already present
        else{
            cacheMap[key]->second = value;
            cacheData.splice(cacheData.begin(), cacheData, cacheMap[key]);
            cacheMap[key] = cacheData.begin();
        }
    }

    int get(int key){
        // already present
        if(cacheMap.find(key) != cacheMap.end()){
            int ret = cacheMap[key]->second;
            cacheData.splice(cacheData.begin(), cacheData, cacheMap[key]);
            cacheMap[key] = cacheData.begin();

            return ret;
        }
        
        // no related record
        return -1;
    }

private:
    size_t cacheSize;
    list<pair<int, int> > cacheData;                                // store <key, value> pair
    unordered_map<int, list<pair<int,int> >::iterator> > cacheMap;  // map key to the location of its value in the list
}
