/*
 * =====================================================================================
 *
 *       Filename:  roman_to_integer.cc
 *
 *    Description:  
 *
 *        Created:  01/11/2015 17:40:56
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    int romanToInt(string s) {
        if(s.empty())   return 0;
        
        map<char, int> map;
        map['M'] = 1000;
        map['D'] = 500;
        map['C'] = 100;
        map['L'] = 50;
        map['X'] = 10;
        map['V'] = 5;
        map['I'] = 1;
        
        int res = 0;
        for(int i = 0; i < s.size(); i++){
            // KEY IDEA:
            // if the previous char is smaller than the current, need substract twice the previous value because
            // already added that value once
            if(i > 0 && map[s[i]] > map[s[i-1]])
                res += map[s[i]] - 2*map[s[i-1]];
            else
                res += map[s[i]];
        }
        
        return res;
    }
};




