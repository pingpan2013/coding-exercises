/*
 * =====================================================================================
 *
 *       Filename:  word_ladder_ii.cc
 *
 *    Description:  word ladder ii
 *
 *        Created:  01/18/2015 11:25:02
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    unordered_map<string, unordered_set<string> > prevs;
    vector<vector<string> > ladders;
    
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        deque<string> cur;
        cur.push_back(start);
        dict.erase(start);
        
        //for(auto itr : dict){
        //    prevs[itr] = unordered_set<string>();
        //}
        
        bool found = false;
        unordered_set<string>   check_set;
        
        while(!cur.empty()){
            check_set.clear();
            size_t cnt = cur.size();
            
            for(size_t i = 0; i < cnt; i ++){
                string prev = cur.front();
                cur.pop_front();

                for(size_t j = 0; j < prev.size(); j ++){
                    string tmp = prev;
                    for(char c = 'a'; c < 'z'; c++){
                        if(c == tmp[j]) continue;
                        
                        tmp[j] = c;
                        if(tmp == end){
                            prevs[tmp].insert(prev);
                            found = true;
                            break;
                        }
                        
                        if(dict.find(tmp) != dict.end()){
                            prevs[tmp].insert(prev);
                            
                            // in case of duplication
                            if(check_set.find(tmp) == check_set.end()){
                                check_set.insert(tmp);
                                cur.push_back(tmp);
                            }
                        }
                    }
                }
            }
            
            if(found)   break;
            
            // remove from dict 
            for(auto itr : check_set)
                dict.erase(itr);
        }
       
        if(found){
            vector<string> ladder;
            dfs(end, end, ladder);
        }
        
        return ladders;
    }
    
private:
    void dfs(string &word, string &end, vector<string> &ladder){
        auto it = prevs.find(word);
        if(it == prevs.end()){
            vector<string> tmp = ladder;
            reverse(tmp.begin(), tmp.end());
            tmp.push_back(end);
            
            ladders.push_back(tmp);
            return;
        }
        
        for(auto it : prevs[word]){
            ladder.push_back(it);
            dfs(it, end, ladder);
            ladder.pop_back();
        }
    }
};

int main(){
    Solution sln;
    unordered_set<string> dict = {"a", "b", "c"};
    vector<vector<string> > ladders = sln.findLadders("a", "c", dict);

    for(auto itr1 : ladders)
        for(auto itr2 : itr1)
            cout << itr2 << " ";
        cout << endl;

    return 0;
}
