/*
 * =====================================================================================
 *
 *       Filename:  shuffle_array.cc
 *
 *    Description:  shuffle an array of size n, s.t. each element has 1/n probability 
 *                  to remain in its original spot
 *
 *        Created:  02/23/2015 10:09:24
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

void shuffle_array(vector<int> &arr){
    if(arr.empty() || arr.size() == 1)  return;

    int n = arr.size();
    // attention, it's i > 0, no need to shuffle the last element
    for(int i = n-1; i > 0; i++){
        swap(arr[i], arr[rand() % (i+1)]);
    }
}

