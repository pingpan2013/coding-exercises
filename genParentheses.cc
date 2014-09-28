/*
 * =====================================================================================
 *    Description:  Given n pairs of parentheses, generate all combinations of 
 *                  well-formed parentheses*
 *        Created:  09/20/2014 05:36:08 PM
 *       Compiler:  g++ 4.7.0
 * =====================================================================================
 */


#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:    
    vector<string> genParentheses(int n){
        vector<string> res;     // record the result
        string temp(n<<1, '.');            // record the current combination
        helper(res, n, n, temp, n*2); // n means the number of left or right parentheses left
        return res;
    }
private:
    void helper(vector<string> &res, int left, int right, string &s, int n){
        // exit of recursion
        if(left == 0 && right == 0){
            res.push_back(s);
            cout << s << endl;
            return;
        }

        // invalid state
        if(left > right || left < 0){
            return;
        }
        
        // recursion
        if(left > 0){
            //s.append("(");
            int index1 = n*2 - left - right;
            s[index1] = '(';
            helper(res, left - 1, right, s, n);
        }

        if(left < right){
            int index = n*2 - left - right;
            s[index] = '(';
            helper(res, left, right - 1, s, n);
        }
    }
};

int main(){
    Solution sol;
    sol.genParentheses(3);
    return 0;
}


