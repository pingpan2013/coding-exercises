/*
    Given a string s, partition s such that every substring of the partition is a palindrome.

    Return all possible palindrome partitioning of s.

    For example, given s = "aab",
    Return

    [
        ["aa","b"],
        ["a","a","b"]
    ]
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > res;
        if(s.empty())   return res;
        
        vector<string> one_partition;
        dfs(s, res, one_partition, 0);
        
        return res;
    }
    
    void dfs(string &s, vector<vector<string> > &res, vector<string> &one_partition, int start){
        if(start == s.size()){
            res.push_back(one_partition);
            return;
        }
        
        for(int i = start; i < s.size(); i++){
            string possible_palin = s.substr(start, i-start+1);
            if(isvalid(possible_palin)){
                one_partition.push_back(possible_palin);
                dfs(s, res, one_partition, i+1);
                one_partition.pop_back();
                cout << "test" << endl;
            }
        }
    }
    
    bool isvalid(string &s){
        int i = 0;
        int j = s.size()-1;
        
        while(i < j){
            if(s[i] != s[j])    return false;
            
            i++;
            j--;
        }
        
        return true;
    }
};


int main() {
    Solution sln;
    
    vector<vector<string> > vvs = sln.partition("aab");
    for(size_t i = 0; i < vvs.size(); i++) {
        for(size_t j = 0; j < vvs[i].size(); j++) {
            cout << vvs[i][j] << "\t";
        }
        cout << endl;
    }

    return 0; 
}

