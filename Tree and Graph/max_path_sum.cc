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

            int maxAcrossRoot = INT_MIN;   
            int maxByOneSide = getMaxPathSum(root, maxAcrossRoot);

            return max(maxAcrossRoot, maxByOneSide);
        }

    private:
        int getMaxPathSum(node* n, int &maxAcrossRoot){
            if(!n)  return 0;

            int leftMax = getMaxPathSum(n->left, maxAcrossRoot);
            int rightMax = getMaxPathSum(n->right, maxAcrossRoot);
            
            int cMax = n->data;
            if(leftMax > 0)
                cMax += leftMax;
            if(rightMax > 0)
                cMax += rightMax;
            maxAcrossRoot = max(maxAcrossRoot, cMax);
            int oneSideMax = max(n->data, max(n->data + leftMax, n->data + rightMax));
            return oneSideMax;
        }

}

int main(){
    int a[] = {1, -2, 3, -4, 5, 6};
    node* n = create_bst(a, 0, 5);
    levelOrderTrav(n);
    
    Solution sol;
    cout << sol.max_path_sum(n) << endl;

    return 0;
}
