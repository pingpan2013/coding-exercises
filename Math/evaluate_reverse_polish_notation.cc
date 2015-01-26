/*
 * =====================================================================================
 *
 *       Filename:  evaluate_reverse_polish_notation.cc
 *
 *    Description:  evaluate reverse polish notation
 *
 *        Created:  01/26/2015 00:06:58
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

//TODO:
// 1. all int??
// 2. overflow??

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if(tokens.empty())  return 0;
        
        stack<int> st;
        string op = "+-*/";
        
        for(int i = 0; i < tokens.size(); i ++){
            string tmp = tokens[i];
            
            auto pos = op.find(tmp);
            if(pos == string::npos){
                st.push(atoi(tmp.c_str()));
            }
            else{
                if(st.size() < 2)   return -1;
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                
                switch(pos){
                    case 0: 
                        st.push(op1+op2);   break;
                    case 1:
                        st.push(op2-op1);   break;  // note the order
                    case 2:
                        st.push(op1*op2);   break;
                    case 3:
                        st.push(op2/op1);   break;  // note the order
                    default:
                        return -1;
                }
            }
        }
        
        return st.top();
    }
};


