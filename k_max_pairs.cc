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
#include <cassert>

using namespace std;

struct node{
    int value;
    int x;
    int y;

    node(int _value, int _x, int _y){
        value = _value;
        x = _x;
        y = _y;
    }
};

class CompareNode{
public:
    bool operator()(node* n1, node* n2){
        return (n1->value < n2->value);
    }
};

class Solution{
public:
    vector<int> findMaxPairs(int a[], int m, int b[], int n, int k){
        assert(m > 0 && n > 0);
        
        k = min(m+n, k);
        vector<int> resVec;
        priority_queue<node*, vector<node*>, CompareNode> resQueue;  
        node* maxNode = new node(a[0]+b[0], 0, 0);
        resQueue.push(maxNode);
                
        while(k > 0){
            node* temp = resQueue.top();
            resVec.push_back(temp->value);
            resQueue.pop();
           
            //TODO: should check the rangs of the indexes here 
            //      should also check if there are duplicates here
            node* t1 = new node(a[temp->x + 1] + b[temp->y], temp->x+1, temp->y);
            node* t2 = new node(a[temp->x] + b[temp->y + 1], temp->x, temp->y+1);
    
            delete temp;

            resQueue.push(t1);
            resQueue.push(t2);

            k --;            
        }

        for(auto i: resVec)
            cout << i << " ";
        cout << endl;

        return resVec;
    }
};


int main(){
    int a[] = {20, 18, 12, 10, };
    int b[] = {10, 9, 6, 4, 2};

    Solution sol;
    sol.findMaxPairs(a, 5, b, 5, 6);

}
