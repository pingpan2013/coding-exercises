/*    
    Given an absolute path for a file (Unix-style), simplify it.

    For example,
    path = "/home/", => "/home"
    path = "/a/./b/../../c/", => "/c"
*/

#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        if(path.empty())    return "";
        
        stack<string> st;
        
        size_t pos1 = 0;
        size_t pos2;
        while(true){
            pos1 = path.find_first_not_of("/", pos1);
            if(pos1 == string::npos) break;
            
            pos2 = path.find_first_of("/", pos1);
            if(pos2 == string::npos) break;   // the string must end with a "/"?
            
            string sub_str = path.substr(pos1, pos2-pos1);
            pos1 = pos2;
            
            if(sub_str == "." || sub_str == ""){
                continue;
            }
            else if(sub_str == ".." || sub_str == "..."){
                if(!st.empty())
                    st.pop();
            }
            else{
                st.push(sub_str);
            }
        }
        
        string ret("");
        while(!st.empty()){
            string temp = st.top();
            ret = temp + ret;
            ret = "/" + ret;
            st.pop();
        }
        
        return ret;
    }
};


int main(){
    string path("/home/bar/..././foo/");
    Solution sol;
    cout << sol.simplifyPath(path) << endl;
}
