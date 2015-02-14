/*
 * =====================================================================================
 *
 *       Filename:  longest_valid_parentheses.cc
 *
 *    Description:  longest valid parentheses, 2nd try
 *
 *        Created:  02/14/2015 15:42:50
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty())   return 0;
        
        int start = 0;
        int max_len = 0;
        int n = s.size();
        
        stack<int> st;  // store the index of the last '('
        
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                st.push(i);
            }            
            else{
                if(st.empty()){
                    start = i+1;
                }
                else{
                    int top = st.top();
                    st.pop();
                    
                    // case 0: "()()"
                    // case 1: "(()"
                    // case 2: "(()()"
                    max_len = max(max_len, (st.empty()) ? i-start+1 : i-st.top()); // attention here
                }
            }
        }
        
        return max_len;
    }
};



