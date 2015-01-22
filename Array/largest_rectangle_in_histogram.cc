/*
 * =====================================================================================
 *
 *       Filename:  largest_rectangle_in_histogram.cc
 *
 *    Description:  largest rectangle in histogram
 *
 *        Created:  01/22/2015 15:07:05
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // 1. the trivial solution will be traversing the array and find the max
        //    rectangle for each height O(n^n)
        
        // 2. O(n)
        if(height.empty())  return 0;
        height.push_back(0);
        
        stack<int> st;
        int max_area = 0;
        int i = 0;
        
        while(i != height.size()){
            cout << i << endl;
            if(st.empty() || height[i] >= height[st.top()])
                st.push(i++);
            else{
                int h = height[st.top()];
                st.pop();
                max_area = max(max_area, st.empty() ? i*h : (i-st.top()-1)*h);
            }
        }
        
        height.pop_back();
        return max_area;
    }
};

