/*
 * =====================================================================================
 *
 *       Filename:  atoi.cc
 *
 *    Description:  implement atoi() function
 *
 *        Created:  01/02/2015 16:52:22
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include <cassert>

using namespace std;

class Solution {
    public:
        int atoi(const char *str) {
            if(!str)    return 0;
            
            const char *cur = str;
            while(*cur == ' ')
                cur ++;
            
            bool if_positive = true;
            if(*cur == '+'){
                cur ++;
            }
            else if(*cur == '-'){
                if_positive = false;
                cur ++;
            }
            
            long long result = 0;
            while(*cur != '\0'){
                if(isdigit(*cur)){
                    int value = *cur - '0';
                    result = result * 10 + value;
                    
                    // dealing with out of range testcases
                    if(if_positive && result > INT_MAX)
                        return INT_MAX;
                    if(!if_positive && -result < INT_MIN)
                        return INT_MIN;
                    
                    cur ++;
                }
                else{
                    break;
                }
            }
           
            return (if_positive) ? result : -result;
        }

};


int main(){
    Solution sol;
    // normal tests
    assert(sol.atoi("1234") == 1234 && "failed in test 1");
    assert(sol.atoi(" 1234") == 1234 && "failed in test 2");
    assert(sol.atoi(" +1234") == 1234 && "failed in test 3");
    assert(sol.atoi(" -1234") == -1234 && "failed in test 4");
    
    // containing no-digit chars after digits
    assert(sol.atoi(" -1234 ") == -1234 && "failed in test 5");
    assert(sol.atoi(" -1234a") == -1234 && "failed in test 6");
    
    // out of range tests
    cout << INT_MIN << endl;
    cout << INT_MAX << endl;
    
    assert(sol.atoi("-2147483649") == INT_MIN && "failed in test 7");
    assert(sol.atoi("2147483649") == INT_MAX && "failed in test 8");

    cout << "Passed all tests!" << endl;

    return 0;
}
