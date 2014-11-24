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
            int length = digits.size();
            if(length == 0)
                return digits;

            int temp = 1;
            for(int i = length - 1; i >= 0; i --){
                int digit = digits[i];
                
                digits[i] = (digits[i] + temp >= 10) ? 
                        digits[i] + temp - 10 : digits[i] + temp;
                temp = (digit + temp >= 10) ? 1 : 0;
            
                cout << temp << endl;

                if(i == 0 && temp == 1){
                    digits.resize(length + 1, 1);
                    rotate(digits.begin(), digits.end()-1, digits.end());
                }
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





