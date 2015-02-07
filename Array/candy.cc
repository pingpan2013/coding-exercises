/*
 * =====================================================================================
 *
 *       Filename:  candy.cc
 *
 *    Description:  There are N children standing in a line. Each child is assigned 
 *                  a rating value.
 *
 *                  You are giving candies to these children subjected to the 
 *                  following requirements:
 *
 *                  Each child must have at least one candy.
 *                  Children with a higher rating get more candies than their neighbors.
 *                  What is the minimum candies you must give?
 *
 *        Created:  11/23/2014 22:45:16
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */


class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<int> num(ratings.size(), 1);
        
        // rightwards
        for(int i = 1; i <= ratings.size() - 1; i ++){
            if(ratings[i] > ratings[i-1])
                num[i] = num[i-1] + 1;
        }
        
        // leftwards
        for(int i = ratings.size() - 2; i >= 0; i --){
            if(ratings[i] > ratings[i+1] && num[i] <= num[i+1])
                num[i] = num[i+1] + 1;
        }
        
        // find the min
        int res = 0;
        for(int item: num)
            res += item;
            
        return res;
    }
};
