/*
 * =====================================================================================
 *
 *       Filename:  clone_graph_2nd.cc
 *
 *    Description:  clone graph, 2nd try
 *
 *        Created:  02/21/2015 10:22:19
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node)   return node;
        
        /*
        * the visited map:
        * 1. record the visited node with node's label
        * 2. map old node to new node
        */
        map<int, UndirectedGraphNode*> visited; 
        return dfs(node, visited);
    }
    
private:
    UndirectedGraphNode *dfs(UndirectedGraphNode *node, map<int, UndirectedGraphNode*> &visited){
        if(!node)   return node;
        
        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        visited[node->label] = newNode;
        
        for(int i = 0; i < node->neighbors.size(); i++){
            if(visited.find(node->neighbors[i]->label) == visited.end()){
                newNode->neighbors.push_back(dfs(node->neighbors[i], visited));
            }
            else{
                newNode->neighbors.push_back(visited[node->neighbors[i]->label]);
            }
        }
        
        return newNode;
    }
};

