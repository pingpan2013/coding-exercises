/*
 * =====================================================================================
 *
 *       Filename:  anagrams.cc
 *
 *    Description:  given an array of strings, return all groups of strings that are
 *    		    anagrams
 *
 *        Created:  10/18/2014 20:56:28
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <cstring>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:
    void findAnagrams(vector<string> strArr){
        // use a map or hashmap to store the results
        // time and space complexity O(n)
        unordered_map<string, vector<string> > res;
         
         for(auto str: strArr){
            string curStr(str);
            sort(str.begin(), str.end());
            res[str].push_back(curStr);
         }
        
        // display results
        for(auto str_pair: res){
            cout << str_pair.first << ": ";
            for(auto str: str_pair.second){
                cout << str << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    vector<string> strArr;
    strArr.push_back("abc");
    strArr.push_back("bca");
    strArr.push_back("ab");
    strArr.push_back("ba");
    strArr.push_back("c");

    Solution s;
    s.findAnagrams(strArr);
    
    return 0;
}



