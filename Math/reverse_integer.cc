/*
 * =====================================================================================
 *
 *       Filename:  reverseInteger.cc
 *
 *    Description:  Reverse digits of an integer
 *
 *        Created:  09/20/2014 05:16:02 PM
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;

class Solution{
public:
    // without extra space
    int reverse(int x){
        int r;
        int res = 0;
        while(x != 0){
            r = x % 10;
            res = res*10 + r;
            x /= 10;
        }
        
        // deal with overflow
        if((x < 0 && res > 0) ||
                (x > 0 && res < 0))    return 0;

        return res;
    }
};

int main(){
    Solution sol;
    assert(sol.reverse(1) == 1 && "failed in test 1");
    assert(sol.reverse(12) == 21 && "failed in test 2");
    assert(sol.reverse(123) == 321 && "failed in test 3");
    assert(sol.reverse(-1234) == -4321 && "failed in test 4");
    
    // testcases for the overflow problem
    assert(sol.reverse(2147483647) == 0 && "failed in test 5");

    cout << "Passed all the tests!" << endl;

    return 0;
}



