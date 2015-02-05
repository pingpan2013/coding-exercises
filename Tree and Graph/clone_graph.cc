/*
 * =====================================================================================
 *
 *       Filename:  clone_graph.cc
 *
 *    Description:  clone undirected graph
 *
 *        Created:  02/04/2015 21:03:49
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
    // dfs + visited array(should contains new nodes)
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node){
        if(!node)   return node;
        
        unordered_map<int, UndirectedGraphNode*> map;  // map lable to new node!! Also treated as the visited nodes map
        return dfs(node, map);
    }
    
private:
    UndirectedGraphNode *dfs(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode*> &map){
        if(!node)   return node;
        
        UndirectedGraphNode *p = new UndirectedGraphNode(node->label);
        map[node->label] = p;
        
        for(int i = 0; i < node->neighbors.size(); i ++){
            if(map.find(node->neighbors[i]->label) == map.end()){
                p->neighbors.push_back(dfs(node->neighbors[i], map));
            }
            else
                p->neighbors.push_back(map[node->neighbors[i]->label]); // add the new node
        }
        
        return p;
    }
};




