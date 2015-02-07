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

bool check(int x){
    return (x & (x-1) == 0);
}

int main(){

    assert(check(1024) && "Failed in test 2.");
    assert(check(1022) && "Failed in test 3.");
    
    return 0;
}
