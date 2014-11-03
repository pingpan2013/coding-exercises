/*
 * =====================================================================================
 *
 *       Filename:  length_of_last_word.cc
 *
 *    Description:  geiven a string s consists of upper/lower-case alphabets and empty 
 *                  characters ' ', return the length of the last word in the string.
 *                  If the last word doesn't exist, return 0
 *
 *                  For example, s = "Hello world"
 *                  return 5.
 *
 *        Created:  11/02/2014 21:49:44
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */


#include <iostream>
#include <cassert>

using namespace std;

class Solution{
public:
    int lengthOfLastWord(const char* s){
        if(s[0] == '\0')  return 0;
        int spacePos = 0;
        int cnt = 0;   // record the length of the string
        
        while(s[cnt] != '\0'){
            if(s[cnt] == ' ')
                spacePos = cnt; 
            cnt ++;
        }

        if(s[cnt-1] == ' ')
            return 0;
        else
            return cnt-spacePos-1;
    }
};

int main(){
    Solution sol;
    
    // BTW: convert string to char*
    // 1. const char *s = str.c_str();   can only be converted to const char*
    // 2. char *s = &str[0]; 
    // 3. Deep copy of the char*
    //    char *s = new char[str.length() + 1];
    //    strcpy(s, str.c_str());
    //    delete [] s;
    string str("Hello World");
    assert(sol.lengthOfLastWord(str.c_str()) == 5 && "failed in this general test!");
    
    string str1("");
    assert(sol.lengthOfLastWord(str1.c_str()) == 0 && "failed in this corner test!");

    string str2("Hello World  ");
    assert(sol.lengthOfLastWord(str2.c_str()) == 0 && "failed in this general test!");

    return 0;
}
