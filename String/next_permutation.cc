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

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if(num.empty() || num.size() == 1)
            return;
        
        int length = num.size();
        int swapPoint = -1;
        for(int i = length - 2; i >= 0; i --){
            if(num[i] < num[i+1]){
                swapPoint = i;
                break;
            }
        }
        
        if(swapPoint == -1){
            sort(num.begin(), num.end());
            return;
        }
        
        int sp = -1;
        for(int j = length - 1; j > swapPoint; j --){
            if(num[j] > num[swapPoint]){
                sp = j;
                break;
            }
        }

        swap(num[swapPoint], num[sp]);
        sort(num.begin() + swapPoint + 1, num.end());
        
        return;
    }

    void printVec(vector<int> &vec){
        for(auto i: vec)
            cout << i << " ";
        cout << endl;
    }
};
  

int main(){
    Solution sol;
    // 5,4,7,5,3,2
    vector<int> vec;
    vec.push_back(5);
    vec.push_back(4);
    vec.push_back(7);
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(2);
    
    sol.printVec(vec);
    sol.nextPermutation(vec);
    sol.printVec(vec);

    return 0;
}



