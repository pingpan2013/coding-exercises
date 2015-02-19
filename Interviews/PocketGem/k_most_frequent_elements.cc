/*
 * =====================================================================================
 *
 *       Filename:  k_most_frequent_elements.cc
 *
 *    Description:  find the k most frequent elements in an array
 *
 *        Created:  02/19/2015 00:02:47
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct cmp{
    bool operator()(pair<int, int> &l, pair<int, int> &r){
        return l.second > r.second;
    }
};

vector<int> findElements(vector<int> &vec, int k){
    vector<int> result;
    
    if(vec.empty() || k <= 0) return result;
    
    unordered_map<int, int> map;  // map value to frequency
    for(auto itr : vec){
        map[itr] ++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> queue;
    
    int cnt = 0;
    for(auto itr : map){
        cnt ++;
        if(cnt <= k){
            queue.push(make_pair(itr.first, itr.second));
        }
        else{
            // Attention here, otherwise do nothing
            if(itr.second > queue.top().second){
                queue.pop();
                queue.push(make_pair(itr.first, itr.second));
            }
        }
    }
    
    // WRONG: cannot iterate over priority_queue in this way
    // for(auto itr : queue){
    //    result.push_back(itr.first);
    // }
    while(!queue.empty()){
        result.push_back(queue.top().first);
        queue.pop();
    }
    
    reverse(result.begin(), result.end());

    return result;
}

/* =====================================================================
 Follow up:

 If the input stream is already sorted and offer you a iterator of the 
 stream which has two functionalities:
 hasNext();
 next();

 How would you solve this probelm?

 int cnt = 0;
 int tmp = next();
 while(hasNext()){
    if(tmp == next()){
        cnt++;
    }
    else{
        //  operate on the queue ... pop and push, maintain the size of k
        // ...
        
        cnt = 0;
        tmp = next();
    }
 }
 
 * =====================================================================*/



int main(){
    vector<int> vec({1, 1, 1, 2, 3, 3, 4, 4, 4, 5, 4, 6});
    vector<int> result = findElements(vec, 2);
    
    for(auto itr : result)
        cout << itr << " ";
    cout << endl;

    return 0;
}


