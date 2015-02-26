/*
 * =====================================================================================
 *
 *       Filename:  get_k_most_frequent_integers.cc
 *
 *    Description:  get k most frequent integers from n sorted streams
 *
 *        Created:  02/26/2015 01:25:59
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

struct Comp{
    bool operator()(pair<int, int> &p1, pair<int, int> &p2){
        return p1.second > p2.second;
    }
}


vector<int> getKMostFrequentInts(vector<ListNode*> &lists, int k){
    assert(k >= 0 && "Invalid K!");
    
    vector<int> ret;
    if(lists.empty() || k == 0)   return ret;

    unordered_map<int, int> IntToFreq;  // map each integet to its frequency

    // ... traverse all the lists to build the hashmap
    // ... we omit this procedure here
    
    priority_queue<pair<int, int>, vector<<pair<int, int> >, Comp> pqueue;
    int cnt = 0;

    for(auto itr : IntToFreq){
        cnt++;
        // first fill the pqueue with k elements, and then
        // maintain the pqueue with fixed size of k
        if(cnt > k)
            if(itr.second < pqueue.top().second)    continue;
            pqueue.pop();
        }
        pqueue.push(make_pair(itr.first, itr.second));
    }

    // get the k
    while(!pqueue.empty()){
        ret.push_back(pqueue.top().first);
        pqueue.pop();
    }

    return ret;
}
