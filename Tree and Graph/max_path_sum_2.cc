/*
 * =====================================================================================
 *
 *       Filename:  max_path_sum.cc
 *
 *    Description:  Given a bt, find the max path sum. The path may start
 *                  and end at any node in the tree.
 *
 *        Created:  10/30/2014 21:56:06
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include "binaryTree.h"
#include <iostream>
#include <climits>
#include <cassert>

using namespace std;

class Solution{
    public:
        int maxPathSum(node* root){
            if(!root)   return 0;

            max_sum = INT_MIN;   
            int maxByOneSide = getMaxPathSum(root);
            return max(maxByOneSide, max_sum);
        }

    private:
        int getMaxPathSum(node* n){
            if(!n)  return 0;

            int leftMax = getMaxPathSum(n->left);
            int rightMax = getMaxPathSum(n->right);
            
            int cMax = n->data;
            if(leftMax > 0)
                cMax += leftMax;
            if(rightMax > 0)
                cMax += rightMax;
            max_sum = max(max_sum, cMax);
            int oneSideMax = max(n->data, max(n->data + leftMax, n->data + rightMax));
            return oneSideMax;
        }

    int max_sum;  // use max_sum to record the value of the current max path sum
};

int main(){
    int a[] = {1, -2, 3, 6, -5, -4};
    node* n = create_bst(a, 0, 5);
    levelOrderTrav(n);
    
    Solution sol;
    assert(sol.maxPathSum(nullptr) == 0 && "Failed in the nullptr test");
    assert(sol.maxPathSum(n) == 6 && "Failed in this general test");

    return 0;
}
