/*
 * =====================================================================================
 *
 *       Filename:  string_contains_all_chars_of_another_string.cc
 *
 *    Description:  check if string A contains all chars of string B, assume B is
 *                  shorter than A
 *
 *        Created:  02/02/2015 23:42:10
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <cassert>
#include <iostream>
using namespace std;

class Solution{
public:
    // method 1: sort + comparing
    //           time complexity O(nlgn), space O(1)
    //           drawback: need change the string, O(n) space needed for backup
    bool stringContains(string &str_a, string &str_b){
        assert(str_a.size() >= str_b.size());
        
        sort(str_a.begin(), str_a.end());
        sort(str_b.begin(), str_b.end());
        
        int pa = 0, pb = 0;
        while(pb < str_b.size()){
            while(pa < str_a.size() && str_a[pa] < str_b[pb]){
                pa ++;  // consider duplicate chars, don't move pa until pb steps to next char
            }
            
            if(pa >= str_a.size() || str_a[pa] > str_b[pb]){
                return false;
            }
            
            // str_a[pa] == str_b[pb]
            pb++;
        }

        return true;
    }

    // method 2: hash_map
    //           time complexity O(n), space O(n)
    
    // method 3: use a bit-manipulation
    //           here we assume that a and b only contain small characters
    bool stringContains_(string &str_a, string &str_b){
        int mask = 0;

        for(auto c : str_a){
            mask |= (1 << (c - 'a'));
        }

        for(auto c : str_b){
            if((mask & (1 << (c - 'a'))) == 0){
                return false;
            }
        }

        return true;
    }
};

// test method 3
int main(){
    string str_a("aabcddeffg");
    string str_b("aef");

    Solution sln;
    assert(sln.stringContains_(str_a, str_b) == true);

    str_b.push_back('c');
    assert(sln.stringContains_(str_a, str_b) == true);

    str_b.push_back('k');
    assert(sln.stringContains_(str_a, str_b) == false);
    
    cout << "Passed all the test cases!" << endl;

    return 0;
}
