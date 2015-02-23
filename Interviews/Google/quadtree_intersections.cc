// reference: http://www.fgdsb.com/2015/01/25/intersection-of-two-quadtrees/
/*
    Given a quadtree structure:
    
    struct QuadNode {
        QuadNode(int num_ones = 0) : ones(num_ones) {}
        int ones{ 0 };
        QuadNode* child[4]{ nullptr };
    };
    
    Please build a quadtree to represent a 0-1 matrix, assume the matrix is a square and the dimension is power of 2.
    Given two such quadtrees with same depth, please write a function to calculate how many 1s are overlapped.
    
    四叉树多次出现在G家的onsite面经中，构建0-1矩阵和求交集则属于频率比较高也比较简单的考查方式。
    注意在计算交集的时候，如果比较的两个节点有一个节点的ones等于0，则该子树可以直接砍掉，这就是四叉树的高效之处。
*
*/

#include <vector>
#include <iostream>

using namespace std;

struct QuadNode{
    QuadNode(int num_of_ones = 0) : ones(num_of_ones){}

    int ones;
    QuadNode* child[4]{ nullptr };
};

class QuadTree{
public:
    QuadNode* buildTree(vector<vector<int> > &matrix){
        if(matrix.empty())  return nullptr;

        int n = matrix.size();
        return buildTree(matrix, n, 0, 0);
    }

    int numOfIntersections(QuadNode *tree1, QuadNode *tree2){
        if(!tree1 || !tree2)    return 0;
        if(tree1->ones == 0 || tree2->ones == 0)    return 0;

        int result = 0;
        // single cell
        if(!tree1->child[0] && !tree2->child[0]){
            result += (tree1->ones && tree2->ones);
        }
        else{
            for(int i = 0; i < 4; i++){
                result += numOfIntersections(tree1->child[i], tree2->child[i]);
            }
        }
        
        return result;
    }
        
    // display QuadTree  
    void displayQuadTree(QuadNode* root){
        for(int i = 0; i < 4; i++)
            cout << root->child[i]->ones << " ";
        cout << endl;
    }


private:
    // recusively builder the tree
    QuadNode* buildTree(vector<vector<int>> &matrix, int tree_size, int row, int col){
        if(tree_size <= 0)  return nullptr;
        if(tree_size == 1)  return new QuadNode(matrix[row][col]);
        
        QuadNode *root = new QuadNode(0);
        int sub_size = tree_size/2;
        int subtrees[4][2] = { {row, col},                  // northwest substree
                               {row+sub_size, col},         // southwest substrr
                               {row, col+sub_size},         // northeast substree 
                               {row+sub_size, col+sub_size} // southeast substree
                             };
        
        for(int i = 0; i < 4; i ++){
            root->child[i] = buildTree(matrix, sub_size, subtrees[i][0], subtrees[i][1]);
            root->ones += root->child[i]->ones;
            
        }
        
        return root;
    }
};

int main()
{
    vector<int> tmp0={0, 1};
    vector<int> tmp1={1, 1};
    vector<vector<int> > matrix1={tmp0, tmp1};
        
    vector<int> vec0={0, 0};
    vector<int> vec1={1, 1};
    vector<vector<int> > matrix2={vec0, vec1};
    
    QuadTree qt;
    QuadNode* tree1= qt.buildTree(matrix1);
    qt.displayQuadTree(tree1);

    QuadNode* tree2= qt.buildTree(matrix2);
    qt.displayQuadTree(tree2);
    
    cout<< qt.numOfIntersections(tree1, tree2) << endl;
    
    return 0;
}

