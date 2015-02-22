/*
 * =====================================================================================
 *
 *       Filename:  majority_element_2nd.cc
 *
 *    Description:  2nd try
 *
 *        Created:  02/22/2015 15:50:16
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    int majorityElement(vector<int> &num) {
        assert(!num.empty() && "Empty array!");
        
        int n = num.size();
        int candidate = num[0];
        int cnt = 1;
        
        int i = 1;
        while(i < n){
            if(num[i] == candidate){
                cnt++;
            }
            else{
                if(cnt >= 1){
                   cnt--; 
                }
                else if(cnt == 0){
                    candidate = num[i];
                    cnt = 1;
                }
            }
            
            i++;
        }
        
        return candidate;
    }
};
