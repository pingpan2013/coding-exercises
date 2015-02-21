/*
 * =====================================================================================
 *
 *       Filename:  longest_continus_subarray_sum_up_to_zero.cc
 *
 *    Description:  reference: http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=113812&highlight=google
 *
 *        Created:  02/21/2015 16:31:25
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> sumUpToZero(vector<int> &arr){
    vector<int> result;
    if(arr.empty()) return result;

    unordered_map<int, int> map;  // map current sum to the last index it appears in
    int max_len = -1;
    int n = arr.size();
    int sum = 0;
    int start = -1;

    for(int i = 0; i < n; i++){
        sum += arr[i];
        
        // the is difinitely the longest so far
        if(sum == 0){
            if(i+1 > max_len){
                max_len = i+1;
                start = 0;
            }

            continue;
        }

        if(map.find(sum) == map.end()){
            map[sum] = i;
        }
        else{
            // the array between the two points sum up to 0
            if(i - map[sum] > max_len){
                max_len = i-map[sum];
                start = map[sum] + 1;
            }
        }
    }
       
    cout << start << endl;
    cout << max_len << endl;

    if(start != -1){
        result.assign(arr.begin()+start, arr.begin()+start+max_len);
    }

    return result;
}

int main()
{
    //vector<int> vec={8,1,2,3,-5,9,29,-29,4,-5,-1,2,1,-8,-3,2,3,3,3,3,-1,-12,2,3,-1};
    
    
    vector<int> vec={1, -1, 2, -2, 3, 4, -3, -4};
    vector<int> result=sumUpToZero(vec);
    
    int sum = 0;
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
        sum += result[i];
    }
    cout<<endl;
   
    cout << sum << endl;

    return 0;
}

