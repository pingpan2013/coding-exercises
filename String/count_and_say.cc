/*
 * =====================================================================================
 *
 *       Filename:  count_and_say.cc
 *
 *    Description:  count and say
                    The count-and-say sequence is the sequence of integers beginning as follows:
                    1, 11, 21, 1211, 111221, ...

                    1 is read off as "one 1" or 11.
                    11 is read off as "two 1s" or 21.
                    21 is read off as "one 2, then one 1" or 1211.

                    Given an integer n, generate the nth sequence.

                    Note: The sequence of integers will be represented as a string. 
 *
 *        Created:  02/14/2015 17:15:19
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    string countAndSay(int n){
        if(n == 0)  return "";
        
        string result = "1";
        for(int i = 1; i < n; i++){
            string str;
            int count = 1;
            char say = result[0];
            
            for(int j = 1; j < result.size(); j++){
                // count
                if(result[j] != result[j-1]){
                    str += to_string(count) + say;
                    count = 1;   // next char
                    say = result[j];
                }
                else
                    count ++;
            }
            
            // the last pair
            str += to_string(count) + say;
            result = str;
        }
        
        return result;
    }
};

