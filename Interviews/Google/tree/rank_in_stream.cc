/*
 * =====================================================================================
 *
 *       Filename:  rank_in_stream.cc
 *
 *    Description:  rank in stream
 *                  Reference 1: CC150 Ch 11.8
 *                  Reference 2: Order statistic tree && find the kth samllest element 
 *                               in BST
 *
 *        Created:  02/23/2015 00:45:53
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

struct TreeNode{
    TreeNode(int _val) : val(_val), lcnt(0), left(nullptr), right(nullptr){
    }

    int val;
    int lcnt;
    TreeNode *left;
    TreeNode *right;
};


class OrderStatisticTree{
public:
    OrderStatisticTree() : root(nullptr){}

    void insert(int x){
        insert(x, root);        
    }

    int getRank(int x){
        return getRank(x, root);
    }

private:
    void insert(int x, TreeNode* &cur){
        if(!cur){
            cur->val = x;
            return;
        }
        
        if(x > cur->val){   // attention: here use > instead of >=, for getting correct order for duplicates
            insert(x, cur->right);
        }
        else{
            // attention
            cur->lcnt++;
            insert(x, cur->left);
        }
    }

    int getRank(int x, TreeNode *cur){
        if(!cur)    return 0;

        if(x == cur->val)   return cur->lcnt;  // 0 based
        else if(x < cur->val){
            return getRank(x, x->left);
        }
        else if(x > cur->val){
            return cur->lcnt+1 + getRank(x, cur->right);
        }
    }

    TreeNode *root;
};
