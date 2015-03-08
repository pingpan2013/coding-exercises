/*
 * =====================================================================================
 *
 *       Filename:  longest_repeated_substring.cc
 *
 *    Description:  LRS problem using siplified suffix array
 *
 *        Created:  02/06/2015 15:33:38
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution{
public:
    // Method 1: Utilizing Suffix Array
    // Time complexity: O(n^2 lgn)
    // Space complexity: O(n2)
    string findLRS(string &s){
        int n = s.size();
        if(n <= 1)  return "";

        // suffix tree
        vector<string> suffixs;
        for(int i = 0; i < n; i ++){
            suffixs.push_back(s.substr(i, n-i));
        }
        
        // O(nlgn)
        sort(suffixs.begin(), suffixs.end());
       
        string lrs("");
        for(int i = 0; i < n-1; i ++){
            string lcp_str = lcp(suffixs[i], suffixs[i+1]);
            if(lrs.size() < lcp_str.size()){
                lrs = lcp_str;
            }
        }

        return lrs;
    }

    // Method 2: DP
    string findLRS_DP(string &s){}


private:
    string lcp(string &s1, string &s2){
        if(s1.empty() || s2.empty())    return "";

        int len = min(s1.size(), s2.size());
        for(int i = 0; i < len; i++){
            if(s1[i] != s2[i]){
                string lcp_str = s1.substr(0, i);
                return lcp_str;
            }
        }
        
        // the whole string
        return s1.substr(0, len);
    }
};


int main(){
    Solution sln;

    string s("ababacdbacd");
    cout << sln.findLRS(s) << endl;

    return 0;
}
