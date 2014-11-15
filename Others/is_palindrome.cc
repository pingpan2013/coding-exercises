/*
 * =====================================================================================
 *
 *       Filename:  is_palindrome.cc
 *
 *    Description:  Determine whether an integer is a palindrome. Do this
 *                  without extra space.
 *
 *        Created:  11/15/2014 04:57:09 PM
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include <cassert>

using namespace std;

class Solution{
    public:
        // if we can use extra space, then we use simply use a 
        // stack to solve this problem easily. Otherwise calculate 
        // the first and the last digit repeatedly and compare them 
        // to decide if it is a palindrome;
        bool isPalindrome(int x){
            if(x < 0)   return false;

            int div = 1;
            while(x / div >= 10)
                div *= 10;

            int l;
            int r;
            while(x > 0){
                r = x % 10;
                l = x / div;
                if(r != l) return false;
                x = (x % div) / 10;
                div /= 100;
            }

            return true;
        }
};

int main(){
    Solution sol;

    assert(sol.isPalindrome(1) == true && "failed in test 1!");
    assert(sol.isPalindrome(10) == false && "failed in test 2!");
    assert(sol.isPalindrome(123) == false && "failed in test 3!");
    assert(sol.isPalindrome(121) == true && "failed in test 4!");
    assert(sol.isPalindrome(1221) == true && "failed in test 5!");
    assert(sol.isPalindrome(12321) == true && "failed in test 6!");
    assert(sol.isPalindrome(123456) == false && "failed in test 7!");
    
    // testcases from leetcode OJ
    assert(sol.isPalindrome(-2147483648) == false && "failed in test 7!");
    
    cout << "Passed all the tests!" << endl;

    return 0;
}
