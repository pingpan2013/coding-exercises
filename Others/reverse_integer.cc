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

using namespace std;

class Solution{
public:
    void reverseInteger(int n){
        vector<int> result;
        bool flag = false;

        while(n != 0){
            if(!flag){
                result.push_back(n%10);
                flag = true;
            }
            else    
                result.push_back(abs(n%10));
            n /= 10;
        }
        
        for(auto i: result)
            cout << i;
        cout << endl;
    }
};

int main(){
    Solution sol;
    sol.reverseInteger(2345);
    sol.reverseInteger(1);
    sol.reverseInteger(-12345);

}



