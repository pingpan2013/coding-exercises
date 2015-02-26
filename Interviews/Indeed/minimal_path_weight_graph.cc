/*
 * =====================================================================================
 *
 *       Filename:  minimal_path_weight_graph.cc
 *
 *    Description:  minimal path weight in graph instead of in tree
 *
 *        Created:  02/25/2015 23:56:55
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

struct Node{
    Node(int _val){
        val = _val;
    }

    int val;    // weight to its parent
    vector<Node*> child;
};

void dfs(Node *root, int cur_cost, int &min_cost, Node* &min_leaf){
    if(!root)   return;

    cur_cost += root->val;
    
    // exit
    if(root->child.empty() && cur_cost < min_cost){
        min_cost = cur_cost;
        min_leaf = root;
        return;
    }
    
    // cut off some subtrees
    if(cur_cost > min_cost){
        return;
    }
    
    // dfs
    for(int i = 0; i < root->child.size(); i++){
        dfs(root->child[i], cur_cost, min_cost, min_leaf);
    }
}

// using DFS: Complexity O(n), n is the number of nodes in the graph
Node* getMinPathLeaf(Node *root){
    if(!root)   return nullptr;

    int min_cost = INT_MAX;
    Node* min_leaf;
    dfs(root, 0, min_cost, min_leaf);

    return min_leaf;
}


// follow up:
//
// (1) if there is cycles in the graph, then we can use a hashmap to store the visited nodes
//     when meeting a already visited node, compare the current path cost with the recorded one,
//     if it's bigger, return else go down
//
// (2) Dijkstra's Algorithm
//     General idea as follows, the code might not be right, just to show the ideas

struct Cmp{
    bool operator()(Node* node1, Node *node2){
        return node1->val > node2->val;
    }
};

Node* getMinPathLeaf(Node* root){
    if(!root)   return nullptr;

    priority_queue<pair<Node*, int>, vector<pair<Node*, int> >, Cmp> pqueue;
    pqueue.push(make_pair(root, 0));
    
    // record the current smallest distance from root to each node 
    map<Node*, int> dist;  // map each node to its current small dist to root
    // Initialization:
    // Set the initial distance to INT_MAX

    while(!pqueue.empty()){
        auto cur = pqueue.top();
        pqueue.pop();

        if(cur->child.empty()){
            return cur.first;
        }

        for(int i = 0; i < cur->child.size(); i++){
            int cur_dist = cur.second + cur->child[i].val;
            if(cur_dist < dist[cur->child[i]]){
                dist[cur->child[i]] = cur_dist;
            }

            pqueue.push(make_pair(cur->child[i], dist[cur->child[i]]));
        }

    }
}

