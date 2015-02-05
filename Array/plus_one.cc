/*
 * =====================================================================================
 *
 *       Filename:  plus_one.cc
 *
 *    Description:  Given a non-negative number represented as an array of digits, 
 *                  plus one to the number.
 *
 *                  The digits are stored such that the most significant digit is 
 *                  at the head of the list.
 *
 *        Created:  11/23/2014 22:49:18
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        if(digits.empty())  return digits;
        
        int c = 1;
        
        for(int i = digits.size()-1; i >= 0; i --){
            int sum = digits[i] + c;
            c = (sum >= 10) ? 1 : 0;
            digits[i] = (sum >= 10) ? sum - 10: sum;
        }

        if(c == 1){
            digits.push_back(1);
            rotate(digits.begin(), digits.end() - 1, digits.end());
        }
        
        return digits;
    }
};

int main(){
    Solution sol;
    vector<int> t = {9, 9, 9};

    for(auto i: sol.plusOne(t))
        cout << i << " ";
    cout << endl;

    return 0;
}





