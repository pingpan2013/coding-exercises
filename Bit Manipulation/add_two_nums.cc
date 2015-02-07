/*
 * =====================================================================================
 *
 *       Filename:  add_two_nums.cc
 *
 *    Description:  reference : http://www.hawstein.com/posts/20.1.html
 *
 *        Created:  02/07/2015 17:40:49
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include <cassert>

using namespace std;

int add(int a, int b){
    if(b == 0)  return a;

    int sum = a ^ b;
    int carry = (a & b) << 1;

    return add(sum, carry);
}

int main(){
    assert(add(999, 111) == (999 + 111) && "Failed in test 1");
    assert(add(9999, 1) == (9999 + 1) && "Failed in test 2");
    assert(add(456, 789) == (456 + 789) && "Failed in test 3");

    cout << "Passed all test cases!" << endl;

    return 0; 
}
