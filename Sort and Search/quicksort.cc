/*
 * =====================================================================================
 *
 *       Filename:  quicksort.cc
 *
 *    Description:  implement quicksort with random pivot
 *
 *        Created:  02/01/2015 17:18:03
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    void quicksort(vector<int> vec){
        printVec(vec);
        quickSort(vec, 0, vec.size()-1);
        printVec(vec);
    }
    
private:
    void printVec(vector<int> &vec){
        for(auto itr : vec)
            cout << itr << " ";
        cout << endl;
    }

    void quickSort(vector<int> &arr, int left, int right) {
        if(left >= right)   return;
        
        int i = left, j = right;
       // int pivot = arr[(left + right) / 2];
        int pivot = arr[rand()%(right-left+1) + left];

        /* partition */
        while (i < j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {   // attention  <=, guranteeed that j > i in the final
                  swap(arr[i++], arr[j--]);
            }
        };
 
        /* recursion */
        quickSort(arr, left, j);
        quickSort(arr, i, right);
    
        printVec(arr);
    }
};


int main(){
    vector<int> vec({1, 2, 4, 5, 1, 3, 10, 20, 9, 12, 13, 0}); 
    
    Solution sln;
    sln.quicksort(vec);

    return 0;
}


