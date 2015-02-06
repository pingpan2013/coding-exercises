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
    // Brute-force method: Using a two-level for loop，time complexity O(n^2)
    //
    // Second method: Using a hash map to record the last position of the repeated char,
    // start over from there and record the current max length.
    // Time complexity depends on the number of times that there are duplications
    // TODO: It cannot pass the leetcode OJ since time limit exceeds
    int lengthOfLongestSubstring_(string s){
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
    
    // Third method:
    // In the above method, each time we fund a repeated char, we clear the hashmap.
    // This leads to repeated accesses which leads to exceed the final time limit
    // Actually, use two pointers can solve this problem.
    int lengthOfLongestSubstring(string s){
        if(s.empty())   return 0;

        unordered_map<char, int> hashMap;
        int i = 0, j = 0;
        int curMax = -1;
        int n = s.length();

        for(i = 0; i < n; i ++){
            if(hashMap.find(s[i]) == hashMap.end()){
                hashMap[s[i]] = i;
            }
            else{
                curMax = max(curMax, i - j);
                // partially clear the hashmap unitl the last occurance of the repeated char
                for(int k = j; k < hashMap[s[i]]; k ++)
                    hashMap.erase(hashMap[s[k]]);
                
                j = hashMap[s[i]] + 1;
                hashMap[s[i]] = i;
            }
        }

        curMax = max(curMax, n - j);
        return curMax;
    }
};

int main(){
    Solution sol;
    string s("");
    assert(sol.lengthOfLongestSubstring(s) == 0 && "Failed in this null string test!");

    string s1("abcabcbb");
    assert(sol.lengthOfLongestSubstring(s1) == 3 && "Failed in this general test!");
    
    string s3("abcade");
    assert(sol.lengthOfLongestSubstring(s3) == 5 && "Failed in this general test!");
    
    string s2("bbbbb");
    assert(sol.lengthOfLongestSubstring(s2) == 1 && "Failed in this corner test!");

    cout << "Passed all the 4 tests!" << endl;

    return 0;
}
