/*
 * =====================================================================================
 *
 *       Filename:  singleNumber.cc
 *
 *    Description:  given an array of integers, every element appears twice except for 
 *                  one. Find that single one.
 *
 *        Created:  09/18/2014 08:25:17 PM
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution{
    public:
        /* WITH EXTRA SPACE */
        int findSingleInteger(int* arr, size_t n){
            unordered_map<int, int> hashmap;
            for(size_t i = 0; i < n; i ++)
                hashmap[arr[i]] ++;
            
            for(auto it = hashmap.begin(); it != hashmap.end(); it++){
                if(it->second == 1)
                    return it->first;
            }
            
            return EXIT_FAILURE;
        }
       
        /* WITHOUT EXTRA SPACE */
        int findSingleInteger_2(int* arr, size_t n){
            while(--n != 0){
                arr[n-1] ^= arr[n];
            }
            return arr[0];
        }
};


int main(){
    Solution sol;

    int arr[] = {4, 2, 3, 4, 2, 3, 5};
    cout << sol.findSingleInteger(arr, 7) << endl;
    cout << sol.findSingleInteger_2(arr, 7) << endl;
}





