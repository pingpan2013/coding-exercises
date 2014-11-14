/*
 * =====================================================================================
 *
 *       Filename:  reverseWords.cc
 *
 *    Description:  Given an input string, reverse the string word by word.
 *                  For example,
 *                  Given s = "the sky is blue",
 *                  return "blue is sky the".
 *
 *        Created:  11/14/2014 14:33:37
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */


#include <iostream>
#include <cassert>

using namespace std;

class Solution{
public:
    void reverseWords(string &s){
        if(s.empty() || s.size() == 1)   return;
        
        string res("");
        for(int i = s.size() - 1; i >= 0; ){
            // if the last chars are ' '
            while(s[i] == ' ' && i >= 0) 
                i--;
            if(i < 0)   
                break;
            
            // append space between each word
            if(!res.empty())
                res.push_back(' ');

            // handle each word
            string word;
            while(s[i] != ' ' && i >= 0)
                word.push_back(s[i--]);
            reverse(word.begin(), word.end());
            res.append(word);
        }

        s = res;
    }
    
    // used some std functions to resolve the problem
    // e.x. find_last_of 
    void reverseWords2(string &s){
        string res("");
        string delimiter = " ";
        string::size_type pos1;
        string::size_type pos2 = 0;
        
        while(true){
            if(pos2 == string::npos)    break;
            
            pos1 = s.find_first_not_of(delimiter, pos2);
            if(pos1 == string::npos)
                break;

            pos2 = s.find_first_of(delimiter, pos1);
            if(pos2 == string::npos)
                pos2 = s.size();

            string word = s.substr(pos1, pos2-pos1);
            
            if(res.empty())
                res = word;
            else
                res = word + " " + res;
        }

        s = res;
    }

};

int main(){
    Solution sol;
   
    string s0(" ");
    string res0("");
    sol.reverseWords(s0);
    assert(s0 == res0 && "failed in test0 !");

    string s("sky is blue");
    string res("blue is sky");
    sol.reverseWords2(s);
    assert(s == res && "failed in test1 !");

    s = "  sky is  blue ";
    sol.reverseWords2(s);
    assert(s == res && "failed in test2 !");

    s = "sky";
    res = "sky";
    sol.reverseWords2(s);
    assert(s == res && "failed in test2 !");


    cout << "Passed all tests!" << endl;

    return 0;
}


