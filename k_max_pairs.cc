/*
 * =====================================================================================
 *
 *       Filename:  k_max_pairs.cc
 *
 *    Description:  Find the k sums of two sorted arrays
 *
 *        Created:  10/04/2014 08:44:51 PM
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */


#include <iostream>
#include <queue>
#inlcude <cassert>

using namespace std;

struct node{
    int value;
    int x;
    int y;
};

class Solution{
public:
    vector<int> findMaxPairs(int a[], int m, int b[], int n, int k){
        assert(m > 0 && n > 0);
        
        k = min(m+n, k);
        vector<int> resVec;
        priority_queue<node> resQueue;  // TODO: should implement the comparasion function of the priority_queue here
        node a(a[0]+b[0], 0, 0);
        resQueue.push(node);
                
        while(k > 0){
            node temp = resQueue.front();
            resVec.push(temp.value);
            resQueue.pop();
           
            //TODO: should check the rangs of the indexes here 
            //      should also check if there are duplicates here
            node t1(a[temp.x + 1] + b[temp.y], temp.x+1, temp.y);
            node t2(a[temp.x] + b[temp.y + 1], temp.x, temp.y+1);

            resQueue.push(t1);
            resQueue.push(t2);

            k --;            
        }

        for(auto i: res)
            cout << i << " ";
        cout << endl;

        return resVec;
    }
};

