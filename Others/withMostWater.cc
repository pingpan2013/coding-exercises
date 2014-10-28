/*
 * =====================================================================================
 *           Desc:  container with most water
 *        Created:  09/20/2014 05:36:08 PM
 *       Compiler:  g++ 4.7.0
 * =====================================================================================
 */

#include <iostream>
#include <climits>

using namespace std;

class Solution{
public:    
    int withMostWater(unsigned a[], int n){
        int l = 0;
        int h = n-1;
        
        int tempMax = INT_MIN; 
        int lIndex = -1, rIndex = -1;
        
        while(l <= h){
            // the volum depends on the shortest hand
            int tempVol = min(a[l], a[h])*(h-l);
            if(tempVol > tempMax){
                tempMax = tempVol;
                lIndex = l;
                rIndex = h;
            }

            (a[l] > a[h]) ? h-- : l++;
        }

        cout << "(i, j): " << lIndex << ", " << rIndex << endl;
        cout << "most water: " << tempMax << endl; 

        return tempMax;
    }
};

int main(){
    unsigned A[] = {2, 3, 1, 10, 3, 1};
    Solution sol;
    sol.withMostWater(A, 6);
}   




