/*
 * =====================================================================================
 *
 *       Filename:  longest_valid_parentheses.cc
 *
 *    Description:  given a string containing just the characters '(' and ')', find 
                    the length of the longest valid parentheses substring
 *
 *        Created:  01/10/2015 16:08:19
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    // dp : local max VS global max
    //      this is similar to the "best time to sell stock problem"  --> update "curBase" and "maxProfit" at the same time
    int longestValidParentheses(string s) {
        if(s.empty())   return 0;
        
        int len = s.size();
        int i = 0;
        int max_len = 0;
        int start_point = 0;
        
        stack<pair<char, int> > st;
        while(i < len){
            if(s[i] == '('){
                st.push(make_pair('(', i));
            }
            else{
                if(!st.empty()){
                    st.pop();
                    int temp_max_len = (st.empty() ? (i - start_point + 1) : (i - st.top().second));
                    max_len = max(max_len, temp_max_len);
                }
                // key point:
                // if the number of ")" is larger than the number of ")", the previous sub string is invalid 
                else{
                    start_point = i + 1;
                }
            }
        }
        
        return max_len;
    }
};
