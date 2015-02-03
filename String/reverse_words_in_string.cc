/*
 * =====================================================================================
 *
 *       Filename:  reverse_words_in_string.cc
 *
 *    Description:  reverse words in a string
 *
 *        Created:  02/03/2015 11:50:18
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    void reverseWords(string &s) {
        if(s.empty())   return;
        
        int pos1 = 0;
        int pos2 = 0;
        
        string res("");
        for(int i = 0; i < s.size(); i ++){
            
            pos1 = s.find_first_not_of(" ", pos2);
            if(pos1 == string::npos)    break;
            
            pos2 = s.find_first_of(" ", pos1);
            if(pos2 == string::npos)    pos2 = s.size();
            
            string str = s.substr(pos1, pos2-pos1);
            
            //res = str + " " + res;      // consider the example "a", --> "a ", no leading or trailing spaces allowed
            if(res.empty()) res = str;   
            else
                res = str + " " + res;
            
        }
        
        s = res;
        return;
    }
};


