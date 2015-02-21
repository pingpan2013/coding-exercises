/*
 * =====================================================================================
 *
 *       Filename:  word_ladder_ii_2nd.cc
 *
 *    Description:  word ladder ii, second try
 *
 *        Created:  02/20/2015 19:48:10
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string>> ladders;
        unordered_map<string, unordered_set<string> > prevs; // map each string to its previous level strings
        
        deque<string> words;
        bool found = false;
        words.push_back(start);
        dict.erase(start);
        
        for(auto itr : dict){
            prevs[itr] = unordered_set<string>();
        }
        
        unordered_set<string> levelWords;  // keep track of all possible words in each level
        
        while(!words.empty()){
            levelWords.clear();  
            size_t num = words.size();
                
            for(int i = 0; i < num; i++){
                string top = words.front();
                words.pop_front();
                string prev = top;
                
                for(int i = 0; i < top.size(); i++){
                    char oldChar = top[i];
                    
                    for(auto c = 'a'; c <= 'z'; c++){
                        if(c == oldChar)    continue;
                        
                        top[i] = c;
                        if(top == end){
                            found = true;
                            prevs[top].insert(prev);
                            break;  // check next word in the current level
                        }
                        
                        if(dict.find(top) != dict.end()){
                            prevs[top].insert(prev);
                        
                            if(levelWords.find(top) == levelWords.end()){
                                levelWords.insert(top);
                                words.push_back(top);
                            }
                        }
                        
                        top[i] = oldChar;
                    }
                }
            }
            
            if(found){
                break;
            }
                
            for(auto itr : levelWords){
                dict.erase(itr);
            }
        }
        
        if(!found)  return ladders;
        
        vector<string> tmp; 
        bfs(end, end, prevs, tmp, ladders);
        
        return ladders;
    }
    
private:
    void bfs(const string &word, const string &end,                 // word is the current word in bfs, end is the initial end 
            unordered_map<string, unordered_set<string> > &prevs,   // map each word to the words that can be transformed to it
            vector<string> &path,                                   // one path
            vector<vector<string>> &paths){                         // stores all the possible paths
           
        auto it = prevs.find(word);         
        if(it == prevs.end()){   // reaching the end of the path
            auto tmp = path;
            reverse(tmp.begin(), tmp.end());
            tmp.push_back(end);
            paths.push_back(tmp);
            return;
        }    
        
        for(auto it : prevs[word]){
            path.push_back(it);
            bfs(it, end, prevs, path, paths);
            path.pop_back();
        }
    }
};

