/*
 * =====================================================================================
 *
 *       Filename:  majority_element.cc
 *
 *    Description: Given an array of size n, find the majority element. The majority 
 *                  element is the element that appears more than ⌊ n/2 ⌋ times.
 *
 *                  You may assume that the array is non-empty and the majority 
 *                 element always exist in the array.
 *
 *        Created:  12/22/2014 16:54:52
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    // with extra space
    int majorityElement_(vector<int> &num) {
        unordered_map<int, int> map;
        
        if(num.size() == 1)
            return num[0];
        
        for(auto it : num){
            if(map.find(it) == map.end()){
                map[it] = 1;
            }
            else{
                map[it] ++;
                
                if(map[it] > num.size()/2)
                    return it;
            }
        }
    }
    
    // without extra space
    int majorityElement(vector<int> &num){
        int candidate;
        int counter = 0;
        
        for(int i= 0; i< num.size(); i ++){
            if(counter == 0){
                candidate = num[i];
                counter ++;
            }
            else{
                if(num[i] == candidate){
                    counter ++;
                }
                else{
                    counter --;
                }
            }
        }
        
        return candidate;
    }
};

