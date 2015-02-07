/*
 * =====================================================================================
 *
 *       Filename:  4sum.cc
 *
 *    Description:  4sum
 *
 *        Created:  01/21/2015 00:54:11
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > res;
        if(num.empty()) return res;
        
        sort(num.begin(), num.end());
        
        int n = num.size();
        for(int i = 0; i < n-3; i++){
            if(i >= 1 && num[i] == num[i-1]) continue;
           
            cout << num[i] << endl;

            for(int j = i+1; j < n-2; j++){
                if(j >= 1 && num[j] == num[j-1]) continue;
                
                cout << num[j] << endl;
                
                int target1 = target - num[i] - num[j];
                int st = j+1;
                int nd = n-1;
                
                cout << target1 << endl;

                while(st < nd){
                    int sum = num[st] + num[nd];
                    if(sum == target1){
                        res.push_back(vector<int>({num[i], num[j], num[st], num[nd]}));
                        st++;
                        nd--;
                        
                        while(st+1 < nd && num[st] == num[st-1]) st++;
                        while(nd-1 > st && num[nd] == num[nd+1]) nd--;
                    }
                    else if(sum < target1)
                        st++;
                    else
                        nd--;
                }
            }
        } 
        
        return res;
    }
};


int main() {
    Solution sln;

    vector<int> num({0,0,0,0});
    auto vv = sln.fourSum(num, 0);
    
    for(auto itr : vv){
        for(auto it : itr)
            cout << it << " ";
        cout << endl;
    }

    return 0;
}
