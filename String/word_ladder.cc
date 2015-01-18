/*
 * =====================================================================================
 *
 *       Filename:  word_ladder.cc
 *
 *    Description:  word ladder
 *
 *        Created:  01/18/2015 01:04:43
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    // BFS
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        vector<string> cur;
        vector<string> next;
        cur.push_back(start);
        
        int lvl = 1;
        while(!cur.empty()){
            lvl++;
            
            for(size_t i = 0; i < cur.size(); i ++){
                // add new elements qualified
                for(size_t j = 0; j < cur[i].size(); j++){
                    string temp = cur[i];
                    for(char c = 'a'; c < 'z'; c++){
                        if(temp[j] == c)  continue;
                        
                        temp[j] = c;
                        if(temp == end){
                            return lvl;
                        }
                        
                        if(dict.find(temp) != dict.end()){
                            next.push_back(temp);
                            dict.erase(temp);
                        }
                    }
                }
            }
            
            cur = next;
            next.clear();
        }
        
        return 0;
    }
};

