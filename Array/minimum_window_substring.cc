/*
 * =====================================================================================
 *
 *       Filename:  minimum_window_substring.cc
 *
 *    Description:  minimum window substring
 *
 *        Created:  02/07/2015 11:40:21
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    string minWindow(string S, string T) {
        // 1. dp seems to be hard
        
        // 2. two pointers
        if(S.empty() || T.empty() || T.size() > S.size()){
            return "";
        }
        
        unordered_map<char, int> matched;
        
        unordered_map<char, int> expected;
        for(int i = 0; i < T.size(); i++){
            expected[T[i]] ++;
        }
        
        int min_len = INT_MAX;
        int start = 0;   // starting point of sliding window
        int cnt = 0;     // counter indicates how many chars already mateched
        
        int start_index = 0;
        
        for(int i = 0; i < S.size(); i++){
            if(expected[S[i]] > 0){
                matched[S[i]] ++;
                
                if(matched[S[i]] <= expected[S[i]]){
                    cnt++;
                }
            }
            
            if(cnt == T.size()){
                // narrow down the sliding window from the head until it cannot be narrowed dowm any more
                while(matched[S[start]] > expected[S[start]] || expected[S[start]] == 0){
                    matched[S[start]] --;
                    start++;
                }
                
                if(min_len > (i-start+1)){
                    min_len = i-start+1;
                    start_index = start;
                }
            }
        }
        
        return (min_len == INT_MAX) ? "" : S.substr(start_index, min_len);
    }
};


