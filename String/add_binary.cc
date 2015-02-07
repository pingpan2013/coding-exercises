/*
 * =====================================================================================
 *
 *       Filename:  add_binary.cc
 *
 *    Description:  Given two binary strings, return their sum (also a binary string).
 *
 *                  For example,
 *                  a = "11"
 *                  b = "1"
 *                  Return "100".
 *
 *        Created:  01/07/2015 14:52:30
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.empty())   return b;
        if(b.empty())   return a;
    
        int a_len = a.length() - 1;
        int b_len = b.length() - 1;
        
        string result;
        int carry = 0;
        int temp_digit = 0;
        while(a_len >= 0 && b_len >= 0){
            int temp = (a[a_len] - '0') + (b[b_len] - '0') + carry;
            
            carry = (temp >= 2) ? 1 : 0;
            temp_digit = (carry == 1) ? temp - 2 : temp;
            
            result.insert(result.begin(), temp_digit+'0');
            a_len --;
            b_len --;
        }
        
        string rest_str;
        int rest_len;
        if(a_len == -1 && b_len == -1){
            if(carry == 1){
                result.insert(result.begin(), '1');
            }  
            return result;
        }
        else{ 
            rest_str = (a_len == -1) ? b : a;
            rest_len = (a_len == -1) ? b_len : a_len;
        }
        
        while(rest_len >= 0){
            int temp = rest_str[rest_len] - '0' + carry;
            carry = (temp >= 2) ? 1 : 0;
            temp_digit = (carry == 1) ? temp - 2 : temp;
            
            result.insert(result.begin(), temp_digit+'0');
            rest_len --;
        }
        
        if(carry == 1){
            result.insert(result.begin(), '1');
        }
        return result;
    }
};

int main(){
    string a("111");
    string b("11");

    Solution sol;
    cout << sol.addBinary(a, b) << endl;

    return 0;
}
