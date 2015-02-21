/*
 * =====================================================================================
 *
 *       Filename:  longest_consective_sequence.cc
 *
 *    Description:  longest consective sequence
 *
 *        Created:  02/20/2015 20:14:56
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if(num.empty()) return 0;
        
        unordered_set<int> nums;
        for(auto itr : num){
            nums.insert(itr);
        }
        
        int i = 0;
        int len = 0;
        while(i < num.size()){
            int cur = num[i];
            int tmp_len = 1;
            nums.erase(cur);
            
            int tmp = cur;
            while(nums.find(++tmp) != nums.end()){
                tmp_len++;
                nums.erase(tmp);
            }
                      
            tmp = cur;
            while(nums.find(--tmp) != nums.end()){
                tmp_len++;
                nums.erase(tmp);
            }
            
            if(tmp_len > len){
                len = tmp_len;
            }
            
            i++;
        }
        
        return len;
    }
};


