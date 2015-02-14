/*
 * =====================================================================================
 *
 *       Filename:  divide_two_integers.cc
 *
 *    Description:  divide two integers
 *
 *        Created:  02/14/2015 14:58:31
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)    return INT_MAX;   // case 1: overflow
        
        // case 2:
        // cannot do in this way:
        // long long a = abs(dividend), since abs(INT_MIN) == 0
        // cannot pass testcases where dividend == INT_MIN
        long long a = dividend;
        long long b = divisor;
        a = abs(a);
        b = abs(b);
        
        int ret = 0;
        for(int i = 31; i >= 0; i--){
            if(a >= (b << i)){
                a = a - (b << i);
                ret += (1 << i);
            }
        }

        return ((dividend < 0) ^ (divisor < 0)) ? -ret : ret;
    }
};

