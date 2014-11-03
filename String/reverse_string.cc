/*
 * =====================================================================================
 *
 *       Filename:  reverse_string.cc
 *
 *    Description:  reverse c string
 *
 *        Created:  11/03/2014 00:18:24
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */
#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

class Solution{
public:
    char* reverseString(char* s){
        if(!s)  return nullptr;

        char* end = s;
        char* beg = s;
        while(*end != '\0'){
            end++;
        }
        end--;
        //  or simply use: char *end = s + strlen(s) - 1;

        while(beg < end){
            swap(*beg, *end);
            beg++;
            end--;
        }
        
        return s;
    }
};

int main(){
    Solution sol;
    
    char s[] = "test";
    char s_res[] = "tset";
    assert(strcmp(sol.reverseString(s), s_res) == 0 && "failed in this general test!");   

    char s1[] = "te st";
    char s1_res[] = "ts et";
    assert(strcmp(sol.reverseString(s1), s1_res) == 0 && "failed in this general test!");   
 
    char s2[] = "";
    if(!sol.reverseString(s2))
        cout << "failed in the null pointer test!" << endl;

    cout << "passed all the tests" << endl;
    return 0;
}
