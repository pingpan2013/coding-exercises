/*
 * =====================================================================================
 *
 *       Filename:  first_bad_version.cc
 *
 *    Description:  first bad version
 *
 *                  The code base version is an integer and start from 1 to n. One day, 
 *                  someone commit a bad version in the code case, so it caused itself 
 *                  and the following versions are all failed in the unit tests.
 *
 *
 *        Created:  02/05/2015 13:03:34
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

/**
 * class VersionControl {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use VersionControl::isBadVersion(k) to judge wether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
        int l = 1;
        int r = n;
        
        while(l <= r){
            int mid = (r -l)/2 + l;
            
            if(VersionControl::isBadVersion(mid)){
                if(mid == l || mid - 1 >= l && !VersionControl::isBadVersion(mid+1))  return mid;
                r = mid-1;
            }
            else
                l = mid+1;
        }
    }
};


