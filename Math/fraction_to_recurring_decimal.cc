/*
 * =====================================================================================
 *
 *       Filename:  fraction_to_recurring_decimal.cc
 *
 *    Description:  fraction to recurring decimal, 
 *                  reference: http://www.meetqun.com/thread-3328-1-1.html
 *
 *        Created:  02/22/2015 15:38:41
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        assert(denominator != 0 && "Exception: Denominator is 0!");
        if(numerator == 0)  return "0";
        
        string result;
        
        // deal with sign
        if((numerator > 0) ^ (denominator > 0 ))    result += "-";
        
        // in case of overflow, e.g. numerator is INT_MIN, and denominator is -1
        long long Numerator = numerator;
        long long Denominator = denominator;
        Numerator = abs(Numerator);
        Denominator = abs(Denominator);
        
        // deal with the integer part
        long long quotient = Numerator / Denominator;
        result += to_string(quotient);
        
        // deal with the decimal part
        long long remainder = Numerator % Denominator;
        if(remainder == 0){
            return result;
        }
        
        result += ".";
        unordered_map<long long, int> map;  // map the remainder to the position it appears at
        
        while(map.find(remainder) == map.end()){
            map[remainder] = result.size();
            
            quotient = remainder*10 / Denominator;
            result += to_string(quotient);
            
            remainder = remainder*10 % Denominator;
            if(remainder == 0){
                return result;
            }
        }
        
        // recurring part, add "( )"
        result.insert(map[remainder], "(");
        result.push_back(')');
        return result;
    }
};
