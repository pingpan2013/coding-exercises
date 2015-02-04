/*
 * =====================================================================================
 *
 *       Filename:  vilaid_number.cc
 *
 *    Description: Validate if a given string is numeric.
 *
 *                   Some examples:
 *                   "0" => true
 *                   " 0.1 " => true
 *                   "abc" => false
 *                   "1 a" => false
 *                   "2e10" => true
 *                   
 *                   Note: It is intended for the problem statement to be ambiguous. You 
 *                   should gather all requirements up front before implementing one. 
 *
 *        Created:  02/03/2015 22:59:18
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include <cstdio>

using namespace std;

class Solution {
public:
    bool isNumber(const char *s) {
        if(*s == '\0')  return true;
        
        string ss(s);
        
        int i = 0;
        while(isspace(s[i]))    i++;
        int j = ss.size()-1;
        while(isspace(s[j]))    j--;
        
        ss = ss.substr(i, j-i+1);
        
        // three flags for different situations
        bool dot = false;
        bool num = false;
        bool exp = false;
        
        for(int i = 0; i < ss.size(); i++){
            char c = ss[i];
            if(c == '.'){
                if(dot || exp)  return false;
                dot = true;
            }
            else if(c == 'e' || c == 'E'){
                if(exp || !num) return false;
                
                exp = true;
                num = false;            // e must be followed by numbers
            }
            else if(c >= '0' && c <= '9')   num = true;
            else if(c == '+' || c == '-'){
                if(i != 0 && ss[i-1] != 'e')    return false;
            }
            else
                return false;  // invalid input
        }
        
        return num;
    }
};

