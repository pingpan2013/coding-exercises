/*
 * =====================================================================================
 *
 *       Filename:  multiply_strings.cc
 *
 *    Description:  multiply strings
 *
 *        Created:  01/11/2015 17:38:44
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.empty() || num2.empty())    return "0";
        
        // key point is how to how to store the result at the correct position conviniently
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        string res(num1.size() + num2.size(), '0');
        for(int i = 0; i < num1.size(); i++){
            int carry = 0;
            int a = num1[i] - '0';
            for(int j = 0; j < num2.size(); j++){
                int b = num2[j] - '0';
                
                // CORE IDEA: !!!             
                // for pair[i, j], the position of the result should be stored in res[i+j]
                int c = res[i + j] - '0';
                res[i+j] = (a * b + c + carry)%10 + '0';
                carry = (a * b + c + carry)/10;
            }
            
            if(carry > 0){
                res[i + num2.size()] = carry + '0';
            }
        }
        
        reverse(res.begin(), res.end());
        res.erase(0, res.find_first_not_of('0'));
        
        return (res.empty() ? "0" : res);
    }
};
