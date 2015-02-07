/*
 * =====================================================================================
 *
 *       Filename:  add_binary.cc
 *
 *    Description:  add two binary strings
 *
 *        Created:  02/06/2015 23:51:21
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.empty())   return b;
        if(b.empty())   return a;
        
        int i = a.size();
        int j = b.size();
        
        if(i > j){
            b.insert(0, i-j, '0');
        }
        else if(i < j){
            a.insert(0, j-i, '0');
        } 
           
        int carry = 0;
        string sum;
        for(int i = a.size()-1; i >= 0; i--){
            int c = a[i] - '0' + b[i] - '0' + carry;
            sum.push_back(c%2 + '0');
            carry = c/2;
        }
        
        if(carry == 1){
            sum.push_back(1 + '0');
        }
        
        reverse(sum.begin(), sum.end());
        return sum;
    }
};

int main(){
   Solution sln;

   cout << sln.addBinary("1111111", "111") << endl;

   return 0;
}
