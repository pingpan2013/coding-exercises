/*
 * =====================================================================================
 *
 *       Filename:  two_sum.cc
 *
 *    Description:  two sum problem
 *
 *        Created:  12/07/2014 23:07:44
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */


class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        
        // record the index
        multimap<int, int> indexMap;   // in case there are two same numbers
                                       // or we can use hashmap<int, set<int>>;
        int index = 1;
        for(auto itr : numbers){
            indexMap.insert(pair<int, int>(itr, index));
            index ++;
        }
        
        sort(numbers.begin(), numbers.end());
        
        vector<int> res;
        int i = 0;
        int j = numbers.size() - 1;
        
        while(i < j){
            if(numbers[i] + numbers[j] == target){
                if(numbers[i] != numbers[j]){
                    int minIndex = min(indexMap.find(numbers[i])->second, 
                                        indexMap.find(numbers[j])->second);
                    int maxIndex = max(indexMap.find(numbers[i])->second, 
                                        indexMap.find(numbers[j])->second);
                    res.push_back(minIndex);
                    res.push_back(maxIndex);
                }
                else{
                    auto ret = indexMap.equal_range(numbers[i]);
                    for(auto it = ret.first; it != ret.second; it++){
                        res.push_back(it->second);
                    }
                }
                
                return res;
            }            
            else if(numbers[i] + numbers[j] > target){
                j --;
            }
            else{
                i ++;
            }
        }
    }
};
