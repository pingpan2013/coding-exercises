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
#include <set>

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
        set<node*> dupSet;
        
        node* maxNode = new node(a[0]+b[0], 0, 0);
        resQueue.push(maxNode);
        dupSet.insert(maxNode);
                
        while(k > 0){
            node* temp = resQueue.top();
            resVec.push_back(temp->value);
            resQueue.pop();
           
            if(temp->x + 1 < m){
                node* t1 = new node(a[temp->x + 1] + b[temp->y], temp->x+1, temp->y);
                if(!findEleInSet(t1, dupSet)){
                    resQueue.push(t1);
                    dupSet.insert(t1);
                }
           }
           
            if(temp->y + 1 < n){
                node* t2 = new node(a[temp->x] + b[temp->y + 1], temp->x, temp->y+1);
                if(!findEleInSet(t2, dupSet)){
                    resQueue.push(t2);
                    dupSet.insert(t2);
                }
            }                
            
            delete temp;
            k --;            
        }
        
        // print results
        for(auto i: resVec)
            cout << i << " ";
        cout << endl;
        
        // clean up
        //while(!resQueue.empty()){
        //    node* t = resQueue.top();
        //    delete t;
        //    resQueue.pop();
        //}
        return resVec;
    }

private:
    bool findEleInSet(node* n, set<node*> dupSet){
        for(auto iter = dupSet.begin(); iter != dupSet.end(); iter ++){
            if((*iter)->value == n->value && (*iter)->x == n->x && (*iter)->y == n->y)
                return true;
        }
        return false;
    }
};


int main(){
    int a[] = {20, 18, 12, 10};
    int b[] = {10, 9, 6, 4, 2};

    Solution sol;
    sol.findMaxPairs(a, 5, b, 5, 8);

}
