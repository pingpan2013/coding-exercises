/*
 * =====================================================================================
 *
 *       Filename:  pow.cc
 *
 *    Description:  implement pow(x, )
 *
 *        Created:  01/11/2015 17:39:53
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    double helper(double x, int n) {
        if(n == 0)  return 1;
        if(n == 1)  return x;
        
        double v = helper(x, n/2);
        if(n%2 == 1){
            return x*v*v;
        }
        else{
            return v*v;
        }
    }
    
    double pow(double x, int n){
        if(n < 0)
            return 1.0/helper(x, -n);
        else
            return helper(x, n);
    }
};
