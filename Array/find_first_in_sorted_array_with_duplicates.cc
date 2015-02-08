/*
 * =====================================================================================
 *
 *       Filename:  find_first_in_sorted_array_with_duplicates.cc
 *
 *    Description:  Given a sorted array having duplicate elements,how would you find 
 *                  first index of a given element in O(nlogn). 
 *                  
 *                  Write code for it. Change the condition to find out last index of 
 *                  that elements. 
 *
 *        Created:  02/07/2015 22:29:40
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */


int searchFirstOccurance(vector<int> a, int key) {
    if(a.empty())   return -1;

    int l = 0;
    int r = a.size() - 1;
    int m = (l + r) / 2;
    int keyPosition = INT_MAX;

    while (l <= r) {
        m = (l + r) / 2;
        if (key == a[m]) {
            keyPosition = min(keyPosition, m);
            r = m - 1;  // keep search in lower indexes
        } else if (key < a[m]) {
            r = m - 1;
        } else if (key > a[m]) {
            l = m + 1;
        }

    }
    return keyPosition == Integer.MAX_VALUE ? -1 : keyPosition;
}


