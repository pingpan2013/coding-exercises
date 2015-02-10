/*
 * =====================================================================================
 *
 *       Filename:  check_if_power_of_2.cc
 *
 *    Description:  check if a number is the power of 2
 *
 *        Created:  02/07/2015 18:12:20
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <cassert>

using namespace std;

// check if x is the power of 2
bool check(int x){
    return (x & (x-1)) == 0;
}


// cout number of 1 in the binary representation of a number
int countNum(int x){
    int cnt = 0;
    while(x){
        cnt++;

        x = x & (x-1);
    }

    return cnt;
}

int main(){

    assert(check(1024) && "Failed in test 2.");
    assert(!check(1022) && "Failed in test 3.");

    assert(countNum(7) == 3 && "Failed in test 4.");
    assert(countNum(255) == 8 && "Failed in test 4.");
    
    return 0;
}
