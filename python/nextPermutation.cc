/*
 * =====================================================================================
 *    Description:  Next permutation 
 *        Created:  09/20/2014 05:36:08 PM
 *       Compiler:  g++ 4.7.0
 * =====================================================================================
 */


#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:    
    void nextPermutation(vector<int> &vec){
        assert(!vec.empty() && "Input is empty!");
        if(vec.size() == 1) return;

        // search from the end find the first element that is smaller than
        // the previous element
        int swapPoint = -1;
        for(vector<int>::size_type i = vec.size()-1; i >= 0; i --){
            if(vec[i] > vec[i-1]){
                swapPoint = i-1;
                break;
            }
        }
        
        // corner cases
        if(swapPoint == -1) return;
        assert(swapPoint >= 0);

        // swap 
        swap(vec[swapPoint], vec[vec.size()-1]);

        // reorder the rest parts
        sort(&vec[swapPoint+1], &vec[vec.size()]);
    }
    
    void printVec(vector<int> &vec){
        for(auto i: vec)
            cout << i;
        cout << endl;
    }
};

int main(){
    Solution sol;
    vector<int> vec;
    vec.push_back(4);
    
    sol.nextPermutation(vec);
    sol.printVec(vec);

    vec.push_back(3);
    vec.push_back(2);
    sol.nextPermutation(vec);
    sol.printVec(vec);

    vec.push_back(8);
    vec.push_back(7);
    vec.push_back(6);
    sol.nextPermutation(vec);
    sol.printVec(vec);

    return 0;
}



