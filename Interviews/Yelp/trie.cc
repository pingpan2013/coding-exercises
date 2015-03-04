/*
 * =====================================================================================
 *
 *       Filename:  trie.cc
 *
 *    Description:  implement a trie and the insert functionality
 *
 *        Created:  03/04/2015 10:24:30
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#define ALPHABETA_SIZE 26

struct trie_node{
    int value;  // the node is a leaf node if value is not 0
    trie_node* child[ALPHABETA_SIZE];
};

class trie{
public:
    trie_node* root; // the root node of the trie    
    int count;       // record the # of substrees

    void init_trie(){
        root = new trie_node();
        root->count = 0;

        for(int i = 0; i < ALPHABETA_SIZE; i++){
            root->child[i] = nullptr;
        }
    }

    void insert(string str){
        int n = str.size();
        if(n == 0)  return;
        
        root->count++;
        trie_node *p = root;

        for(int i = 0; i < n; i++){
            int index = str[i] - 'a';
            
            // the node  doesn't have the child 'str[i]''
            // construct the new child node
            if(!p->child[index]){
                p->child[index] = new trie_node();

                for(int j = 0; j < ALPHABETA_SIZE; j++){
                    p->child[index]->child[j] = nullptr;
                }
            }

            // go to the next child
            p = p->child[index];
        }

        p->value = root->count;  // if it is not 0, p is a leaf node
    }
};

