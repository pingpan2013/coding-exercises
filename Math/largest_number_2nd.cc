/*
 * =====================================================================================
 *
 *       Filename:  largest_number_2nd.cc
 *
 *    Description:  largest number, 2nd try
 *
 *        Created:  02/22/2015 16:28:38
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    static bool cmp(string &s1, string &s2){
        return (s1+s2) > (s2+s1);
    }

    string largestNumber(vector<int> &num) {
        string result;
        if(num.empty()) return result;
        
        vector<string> nums;
        for(auto itr : num){
            nums.push_back(to_string(itr));
        }
        
        sort(nums.begin(), nums.end(), cmp);
        
        for(auto itr : nums){
            result += itr;
        }
        
        // Corner case: [0, 0, 0, 0 ...], we should return "0"
        if(result[0] == '0')    return "0";
        
        return result;
    }
};
