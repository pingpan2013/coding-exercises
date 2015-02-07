/*
 * =====================================================================================
 *
 *       Filename:  3_sum_rewrite.cc
 *
 *    Description:  3 sum probelm
 *
 *        Created:  12/07/2014 23:33:38
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // no duplicates, so we can use set
        // set<vector<int> > resSet;         // Just using the set to resolve duplicates will result
                                             // in "Time Limit Exceeded", need handly remove duplicates
                                             // within the while loops
        
        vector<vector<int> > resSet;
        
        // sorting
        sort(num.begin(), num.end());
        
        for(int i = 0; i < num.size(); i ++){
            int value = -num[i];
            int l = i + 1;
            int r = num.size() - 1;
            
            // reduce the probelm to two-sum problem
            while(l < r){
                if(num[l] + num[r] == value){
                    vector<int> res;
                    res.push_back(-value);
                    res.push_back(num[l]);
                    res.push_back(num[r]);
                    l ++;   // attention, alter the indexes here
                    r --;
                    
                    // handle duplicates here, if there are several same numbers in the following
                    if(l < r){
                        while(num[l] == num[l-1]) l++;
                        while(num[r] == num[r+1]) r--;
                    }
                    
                    resSet.push_back(res);
                }   
                else if(num[l] + num[r] < value){
                    l ++;
                }
                else{
                    r --;
                }
            }
            
            // handle duplicates here
            if(i < num.size() - 1){
                while(i + 1 < num.size() -1 && num[i] == num[i+1]) i++;  
            }
        }
        
        return resSet;
    }
};

