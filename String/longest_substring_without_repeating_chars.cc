/*
 * =====================================================================================
 *
 *       Filename:  longest_substring_without_repeating_chars.cc
 *
 *    Description:  longest substring without repeating characters
 *                  
 *                  Given a string, find the length of the longest substring without 
 *                  repeating characters. For example, the longest substring without 
 *                  repeating letters for "abcabcbb" is "abc", which the length is 3. 
 *
 *                  For "bbbbb" the longest substring is "b", with the length of 1.
 *
 *        Created:  02/03/2015 11:15:18
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution{
    int lengthOfLongestSubstring(string &s){
        if(s.empty())   return 0;

        /* map each char to the index it last appears */
        unordered_map<char, int> map; 
        int start = 0;
        int max_Len = 0;
        
        int n = s.size();
        for(int i = 0; i < n; i ++){
            if(map.find(s[i]) == map.end())  map[s[i]] = i;
            else{
                max_len = max(max_Len, i - start);

                for(int i = start; i < map[s[i]]; i ++){
                    map.erase(s[i]);
                }

                start = map[s[i]] + 1;
                map[s[i]] = i;
            }
        }

        //return max_len;      // what if no repeating chars
        return max(max_len, n-start);
    }
};
