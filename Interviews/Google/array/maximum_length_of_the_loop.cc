/*
 * =====================================================================================
 *
 *       Filename:  maximum_length_of_the_loop.cc
 *
 *    Description:  Given an array
 *                  Indexes 0 1 2 3 4
 *                  Values 3 2 1 4 0
 *                  Values are the next index of the jump 0 -> 3 -> 4 -> 0... 1 -> 2 -> 1...
 *                  Write a function to detect if there are loops. If yes, get the max 
 *                  length of the loop possible, otherwise just return zero.
 *
 *        Created:  02/23/2015 11:09:11
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

// Simply use DFS and use a visited array to keep track of the history
void dfs(vector<int> &arr, unordered_map<int, int> &visited, int i, int curLen, int &maxLen){
    if(visited.find(arr[i]) != visited.end()){
        maxLen = maxLen(maxLen, curLen - visited[arr[i]]);
        return;
    }

    visited[arr[i]] = curLen;  // 0 based
    dfs(arr, visited, arr[i], curLen+1, maxLen);
}

int maxLenOfLoop(vector<int> &arr){
    if(arr.size() <= 1) return 0;

    int max_len = 0;
    
    for(int i = 0; i < arr.size(); i++){
        unordered_map<int, int> visited;  // map index to current length
        dfs(arr, visited, i, 0, max_len);
    }
    
    return max_len;
}
