/*
 * =====================================================================================
 *
 *       Filename:  largest_rectangle.cc
 *
 *    Description:  largest rectangle using linear time
 *
 *        Created:  02/16/2015 18:36:38
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    // 1. trivial way O(n^2)
    
    // 2. O(n) solution
    int largestRectangleArea(vector<int> &height) {
        if(height.empty())  return 0;
        
        height.push_back(0);
        
        stack<int> st;  // record the index
        int i = 0;
        int max_rect = 0;
        
        while(i < height.size()){
            if(st.empty() || height[i] >= height[st.top()]){
                st.push(i++);
            }
            else{
                int j = height[st.top()];
                st.pop();
                
                max_rect = max(max_rect, (st.empty()) ? i*j : (i-st.top()-1) * j); // since i doesnt change
                                                    // if two heights are the same, this step will repeat and 
                                                    // can still get the max rectangle
            }
        }
        
        height.pop_back();
        return max_rect;
    }
};



