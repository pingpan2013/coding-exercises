/*
 * =====================================================================================
 *
 *       Filename:  length_of_longest_substring.cc
 *
 *    Description:  Given a string, find the length of the longest substring without 
 *                  repeating characters. 
 *                  
 *                  For example, the longest substring without repeating letters for 
 *                  "abcabcbb" is "abc", which the length is 3. 
 *                  For "bbbbb" the longest substring is "b", with the length of 1.
 *
 *        Created:  11/01/2014 11:55:52
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include <cassert>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution{
public:
    // Brute-force method
    // Time complexity depends on the number of times that there are duplications
    int lengthOfLongestSubstring(string s){
        if(s.empty())   return -1;
        
        unordered_map<char, unsigned int> hashMap;
        int curMax = -1;
        int curSize = -1;
        
        for(int i = 0; i < s.length(); i ++){
            if(hashMap.find(s[i]) == hashMap.end())
                hashMap[s[i]] = i;
            else{
                i = hashMap[s[i]];
                curSize = hashMap.size();
                curMax = max(curMax, curSize);
                hashMap.clear();
            }
        }
        
        curSize = hashMap.size();
        return max(curMax, curSize);
    }
};

int main(){
    Solution sol;
    string s("");
    assert(sol.lengthOfLongestSubstring(s) == -1 && "Failed in this null string test!");

    string s1("abcabcbb");
    assert(sol.lengthOfLongestSubstring(s1) == 3 && "Failed in this general test!");
    
    string s3("abcade");
    assert(sol.lengthOfLongestSubstring(s3) == 5 && "Failed in this general test!");
    
    string s2("bbbbb");
    assert(sol.lengthOfLongestSubstring(s2) == 1 && "Failed in this corner test!");

    cout << "Passed all the 4 tests!" << endl;

    return 0;
}
