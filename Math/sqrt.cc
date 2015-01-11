/*
 * =====================================================================================
 *
 *       Filename:  sqrt.cc
 *
 *    Description:  implement sqrt
 *
 *        Created:  01/11/2015 14:55:35
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    // TLE
    int sqrt_(int x) {
        if(x <= 0)   return 0;
        if(x == 1)   return 1;
        
        for(int i = 0; i <= x/2; i++){
            if(x == i*i)
                return i;
        }
    }
    
    
    //Utilizing binary search
    int sqrt(int x){
        if(x <= 0)  return 0;
        if(x == 1)  return 1;
        
        long l = 0;
        long r = x/2 + 1;  // q <= x/2
        while(l <= r){
            // use long or long long
            // otherwise may cause overflow
            long mid = (r -l)/2 + l;
            
            if(mid * mid <= x && (mid+1)*(mid+1) > x)    
                return mid;
            else if(mid*mid > x)    r = mid - 1;
            else l = mid + 1;
        }
    }
};

