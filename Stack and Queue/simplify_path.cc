/*
 * =====================================================================================
 *
 *       Filename:  simplify_path.cc
 *
 *    Description:  Given an absolute path for a file (Unix-style), simplify it.

                    For example,
                    path = "/home/", => "/home"
                    path = "/a/./b/../../c/", => "/c" 
 *
 *        Created:  02/06/2015 22:34:52
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    string simplifyPath(string path) {
        if(path.empty())    return "";
        
        stack<string> st;
        int pos1 = 0;
        int pos2 = 0;
        int n = path.size();
        while(true){
            pos1 = path.find_first_not_of("/", pos2);
            if(pos1 == string::npos)    break;
            
            pos2 = path.find_first_of("/", pos1);
            if(pos2 == string::npos)    pos2 = n;
            
            string s = path.substr(pos1, pos2 - pos1);
            
            if(s == "."){
                continue;
            }
            else if(s == ".."){
                if(st.empty()){   // corner case
                    continue;     
                }
                st.pop();
                
                //if(!st.empty())
                //    st.pop();
            }
            else{
                st.push(s);
            }
        }
        
        if(st.empty())  return "/";
        
        string final_path;
        while(!st.empty()){
            final_path = "/" + st.top() + final_path;
            st.pop();
        }
        
        return final_path;
    }
};

