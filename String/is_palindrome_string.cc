/*
 * =====================================================================================
 *
 *       Filename:  is_palindrome_string.cc
 *
 *    Description:  if palindromw string
 *
 *        Created:  02/19/2015 15:34:28
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty())   return true;
        
        int i = 0;
        int j = s.size()-1;
        
        while(i < j){
            //while( !(s[i] >= 'a' && s[i] <= 'Z') && i <= j) i++;
            //while( !(s[j] >= 'a' && s[j] <= 'Z') && j >= i) j--;
            
            while(!isalnum(s[i]) && i < j) i++;
            while(!isalnum(s[j]) && j > i) j--;

            if(s[i++] != s[j--])    return false;
        }
        
        return true;
    }
};

int main(){
    string s("a.");

    Solution sln;
    cout << sln.isPalindrome(s) << endl;

    return 0;
}
