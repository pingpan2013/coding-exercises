/*
 * =====================================================================================
 *
 *       Filename:  minimal_window_substring.cc
 *
 *    Description:  minimal window substring 2nd try
 *
 *        Created:  02/16/2015 11:56:12
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    string minWindow(string S, string T) {
        string result;
        if(T.empty())   return result;
        
        unordered_map<char, int> expectedStat;
        unordered_map<char, int> currentStat;
       
        // get the stat of the template
        for(auto c : T){
            expectedStat[c] ++;
        }
        
        // traverse the string S utilizing sliding window
        int i = 0;
        int matchCnt = 0;
        int start = 0;
        int min_len = INT_MAX;

        while(i < S.size()){
            char c = S[i];
            if(expectedStat[c] > 0){
                currentStat[c]++;
                
                if(currentStat[c] <= expectedStat[c]){
                    matchCnt++;
                }
            }
            
            if(matchCnt == T.size()){
                // narrow down the length from the start
                while(expectedStat[S[start]] == 0 || currentStat[S[start]] > expectedStat[S[start]]){
                    if(currentStat[S[start]] > 0)   currentStat[S[start]] --;
                    start++;
                }
                    
                // update the result if necessary
                string oneMatch = S.substr(start, i-start+1);
                if(oneMatch.size() < min_len){
                    min_len = oneMatch.size();
                    result = oneMatch;
                }
            }
            
            i++;
        }
        
        return result;
    }
};

