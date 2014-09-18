/*
 * =====================================================================================
 *
 *    Filename:  3sum.cpp
 *
 *    Description:  3Sum problem
 *	Given a set S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets 
 *  	in the set which gives the sum of zero.
 *	For example, given set S = {-1 0 1 2 -1 -4},
 *	One possible solution set is:
 *	(-1, 0, 1)
 *	(-1, 2, -1)
 *       
 *    Created:  09/18/2014 12:56:24 AM
 *    Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution{
public:
    set<vector<int> > 3Sum(vector<int> arr){
        sort(arr.begin(), arr.end());
	set<vector<int> > result;
        
        for(int i = 0; i < arr.size(); i ++){
            int value = - arr[i];
            int low = i + 1;
            int high = arr.size() - 1;
            
            /* Applying the idea of 2sum to 3sum problem */
            while(low < high){
                if(arr[low] + arr[high] > value)
                    high --;
                else if(arr[low] + arr[high] < value)
                    low++;
                else{
                    vector<int> temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[low]);
                    temp.push_back(arr[high]);
                    result.insert(temp);
                    low ++;
                    high --;
                }
            }
        }
        return result;
    }
}


int main(){
    Solution sol;
    set<vector<int> > result = sol.3Sum([-1, 0, 1, 2, -1, 4]);
    for(auto vec: result)
        for(auto it = vec.begin(); vec.end(); it ++)
            cout << *it << " ";
        cout << endl;    

    return 0;
}


