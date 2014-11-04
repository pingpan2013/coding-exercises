//=================================================================
// Longest common prefix probelm
// find the longest common prefix amongst an array of strings
//=================================================================

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

class Solution{
public:
    string longestCommonPrefix(vector<string> &strs){
        if(strs.empty())    return "";
        
        int baseLen = INT_MAX;
        for(auto str: strs){
            baseLen = min(baseLen, (int)str.size());
        }

        string baseStr = strs[0];
        int len = -1;
        bool flag = false;
        for(int i = 0; i < baseLen; i ++){   
            for(auto str: strs){
                if(str[i] != baseStr[i]){
                    flag = true;
                    break;
                }
            }

            if(flag)  break;
            len ++;
        }

        cout << len << endl;
        return baseStr.substr(0, len+1);
    }
};

int main(){
    Solution sol;
    
    // general tests
    vector<string> vec;
    vec.push_back("a");
    vec.push_back("b");
    assert(sol.longestCommonPrefix(vec) == "" && "Failed in this test 1!");  
    
    vec.clear();
    string vec_res("string");
    vec.push_back("string");
    vec.push_back("string_test");
    vec.push_back("string_test_test");
    assert(sol.longestCommonPrefix(vec) == vec_res && "Failed in this test 2!");  

    // corner tests
    vec.clear();
    vec.push_back("");
    vec.push_back("string");
    assert(sol.longestCommonPrefix(vec) == "" && "Failed in this corner test 1!");  

    vec.clear();
    vec.push_back("");
    assert(sol.longestCommonPrefix(vec) == "" && "Failed in this corner test 2!");  

    vec.clear();
    assert(sol.longestCommonPrefix(vec) == "" && "Failed in this corner test 3!");  

    cout << "passed all the tests!" << endl;

    return 0;
}
