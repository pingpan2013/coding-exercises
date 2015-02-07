/*
 * =====================================================================================
 *
 *       Filename:  largest_number.cc
 *
 *    Description:  largest number
                    Given a list of non negative integers, arrange them such that they form the largest number.

                    For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
                    Note: The result may be very large, so you need to return a string instead of an integer.
 *
 *        Created:  02/07/2015 12:02:27
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static bool cmp(string &s1, string &s2){
        string str1 = s1 + s2;
        string str2 = s2 + s1;
        
        return str1.compare(str2) > 0;
    }
    
    string largestNumber(vector<int> &num) {
        if(num.empty()) return "";
        
        vector<string> num_str;
        for(auto itr : num){
            num_str.push_back(to_string(itr));
        }
        
        sort(num_str.begin(), num_str.end(), cmp);
        
        string result;
        for(auto itr : num_str){
            result += itr;
        }
    
        // TAKE CARE HERE:
        // remove the possible '0' in the head
        int pos = result.find_first_not_of("0");
        if(pos == string::npos) pos = result.size() - 1;
        
        return result.substr(pos);    
    }
};

int main(){
    vector<int> num({95, 2, 9, 8});
    Solution sln;
    cout << sln.largestNumber(num) << endl;
    
    return 0;
}


