/*
 * =====================================================================================
 *
 *       Filename:  LRUCache.cc
 *
 *    Description:  Design and implement a data structure for Least Recently Used (LRU) 
 * 		    cache. It should support the following operations: get and set.
 *
 *		    (1)get(key) - Get the value (will always be positive) of the key if 
 *		    the key exists in the cache, otherwise return -1.
 *                  (2)set(key, value) - Set or insert the value if the key is not 
 *                  already present. When the cache reached its capacity, it should 
 *                  invalidate the least recently used item before inserting a new item.
 *
 *        Created:  12/09/2014 23:18:24
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */
#include <list>   // doubly linked list 
#include <unordered_map> 
#include <iostream>
#include <cassert>

using namespace std;

struct Node{
    Node(int _key, int _value):key(_key), value(_value){
    }

    int key;
    int value;
};

class LRUCache{
public:
    LRUCache(int capacity) {
        cacheCapacity = capacity;
    }
    
    int get(int key) {
        // not present
        if(cacheMap.find(key) == cacheMap.end()){
            return -1;
        }
        
        // move to the front
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        cacheMap[key] = cacheList.begin();

        return cacheMap[key]->value;
    }
    
    void set(int key, int value) {
        // Not present
        if(cacheMap.find(key) == cacheMap.end()){
            // insertion
            if(cacheList.size() == cacheCapacity){
                cacheMap.erase(cacheList.back().key);
                cacheList.pop_back();
            }
        
            cacheList.push_front(Node(key, value));
            cacheMap[key] = cacheList.begin();
        }
        // Key already present
        else{
            // update the value and move the cacehed node to the front
            cacheMap[key]->value = value;
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            cacheMap[key] = cacheList.begin();
        }
    }

private:
    int cacheCapacity;
    list<Node> cacheList;
    unordered_map<int, list<Node>::iterator> cacheMap;
};

int main(){
    LRUCache lc(4);
    lc.set(1, 1);
    assert(lc.get(1) == 1 && "Failed in test 1");
    
    lc.set(2, 2);
    assert(lc.get(2) == 2 && "Failed in test 2");
    
    lc.set(3, 3);
    assert(lc.get(3) == 3 && "Failed in test 3");
    
    lc.set(4, 4);
    assert(lc.get(4) == 4 && "Failed in test 4");
    
    lc.set(5, 5);
    assert(lc.get(5) == 5 && "Failed in test 5");
    
    assert(lc.get(1) == -1 && "Failed in test 6");

    lc.set(5, 6);
    assert(lc.get(5) == 6 && "Failed in test 7");

    cout << "Passed all tests!" << endl;

    return 0;
}
