/*
 * =====================================================================================
 *
 *       Filename:  rotate_string.cc
 *
 *    Description:  rotate string with an offset
 *                  Given a string and an offset, rotate string by offset. (rotate from left to right)
 *
 *                  Example
 *                  Given "abcdefg"
 *
 *                  for offset=0, return "abcdefg"
 *                  for offset=1, return "gabcdef"
 *                  for offset=2, return "fgabcde"
 *                  for offset=3, return "efgabcd"
 *
 *        Created:  02/05/2015 13:29:53
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
  /**
     * param A: A string
     * param offset: Rotate string with offset.
     * return: Rotated string.
     */
    string rotateString(string A, int offset) {
        // wirte your code here
        if(A.empty())   return A;
        
        offset = offset % A.size();
        
        // METHOD 1: std library
        // std::rotate(A.begin(), A.end() - offset , A.end());
        
        // METHOD 2: 3-step reverse 
        if(offset == 0) return A;
        
        reverse(A.begin(), A.end());
        reverse(A.begin(), A.begin() + offset);    // reverse is [begin, end)
        reverse(A.begin() + offset, A.end());
        
        return A;
    }
};

