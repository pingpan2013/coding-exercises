/*
 * =====================================================================================
 *
 *       Filename:  word_break_2.cc
 *
 *    Description:  Given a string s and a dictionary of words dict, add spaces 
                    in s to construct a sentence where each word is a valid 
                    dictionary word.

                    Return all such possible sentences.

                    For example, given
                    s = "catsanddog",
                    dict = ["cat", "cats", "and", "sand", "dog"].

                    A solution is ["cats and dog", "cat sand dog"].
 *
 *        Created:  01/08/2015 21:20:36
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> res;
        vector<int> index;
        
        dfs(s, dict, res, index, 0);
        
        return res;
    }
    
    // brute-force dfs with backtracking
    void dfs(string &s, unordered_set<string> &dict, vector<string> &res, vector<int> &index, int st){
        if(st >= s.size()){
            string temp_str = s;
            for(int i = 0; i < index.size(); i++){
                temp_str.insert(index[i]+i, " ");
            }   
            
            res.push_back(temp_str);
            return;
        }
        
        for(int i = st; i < s.size(); i ++){
            string word = s.substr(st, i-st+1);
            if(dict.find(word) != dict.end()){
                index.push_back(i+1);
                dfs(s, dict, res, index, i+1);
                index.pop_back();
            }
        }
    }
    
    // another solution according to Word Break I
    
};


int main(){
    string s("catsanddog");
    unordered_set<string> word_set;
    word_set.insert(string("cat"));
    word_set.insert(string("cats"));
    word_set.insert(string("and"));
    word_set.insert(string("sand"));
    word_set.insert(string("dog"));

    Solution sol;
    vector<string> vec = sol.wordBreak(s, word_set);

    for(auto i : vec){
        cout << i << endl;
    }

    return 0;
}



