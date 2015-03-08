/*
 * =====================================================================================
 *
 *       Filename:  topological_sorting.cc
 *
 *    Description:  topological sorting
 *                  Reference: http://www.geeksforgeeks.org/topological-sorting/
 *                  
 *                  Note that the graph shohuld be directed acyclic graph (DAG).
 *
 *                  Note that a vertex is pushed to stack only when all of its adjacent 
 *                  vertices (and their adjacent vertices and so on) are already in stack.
 *
 *        Created:  03/02/2015 23:50:47
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

struct Vertex{
    Vertex(int _label){
        label = _label;
    }
    
    int label;              // from 0 to n
    vector<Vertex> adj;     // record its neighbors
};

void helper(vector<Vertex> &graph, Vertex &curVertex, vector<bool> &visited, stack<int> &Stack){
    visited[curVertex] = true;

    for(auto vertex : curVertex.adj){
        if(!visited[vertex.label]){
            helper(graph, vertex, visited, Stack);
        }
    }
    
    // only push the vertex in the stack when all of its adjacent vertexes have already
    // been visited
    Stack.push(curVertex.label);
}

vector<int> topologicalSort(vector<Vertex> &graph){
    vector<int> ret;
    if(graph.empty())   return ret;

    int n = graph.size();
    
    vector<bool> visited(n, false);  // record if the vertex has already been visited
    stack<int> Stack;   // use stack to record the path

    for(int i = 0; i < i; i ++){
        Vertex curVertex = graph[i];

        if(!visited[curVertex.label]){
            helper(graph, curVertex, visited, Stack);
        }
    }
    
    // pop out the result
    while(!st.empty()){
        ret.push_back(Stack.top());
        Stack.pop();
    }

    return ret;
}


