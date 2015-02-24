/*
 * =====================================================================================
 *
 *       Filename:  minimal_number_of_insertions_to_create_palindrome.cc
 *
 *    Description:  Given a string S, you are allowed to convert it to a palindrome 
 *                  by adding 0 or more characters in front of it.
 *
 *                  Find the length of the shortest palindrome that you can create 
 *                  from S by applying the above transformation. 
 *
 *        Created:  02/21/2015 17:30:39
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

bool isPalindrome(const string &s, int i, int j){
    while(i < j){
        if(s[i++] != s[j--])    return false;
    }

    return true;
}

int minInsertions(string &s, int l, int r){
    if(isPalindrome(s, l, r))   return 0;

    return 1+minInsertions(s, l, r-1);
}

int minPalindrome(string &s){
    if(s.empty())   return 0;

    return minInsertions(s, 0, s.size()-1) + s.size();
}

int main(){
    string s = "abcd";
    assert(minPalindrome(s) == 7 && "failed in test 1");
    
    s[1] = 'a';
    assert(minPalindrome(s) == 6 && "failed in test 2");

    return 0;
}
