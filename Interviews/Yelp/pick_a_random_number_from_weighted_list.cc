/*
 * =====================================================================================
 *
 *       Filename:  pick_a_random_number_from_weighted_list.cc
 *
 *    Description:  pick a random number from weighted list based on weight
 *
 *        Created:  03/04/2015 08:29:35
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

// assume the array only contains positive numbers
int pickRandomNum(vector<int> edges){
    if(edges.empty())   return -1;
    
    int sum = 0;
    for(auto edge : edges){
        sum += edge;
    }

    int randomSum = rand() % sum;

    for(int i = 0; i < edge.size(); i++){
        if(randomSum - edges[i] < 0){
            return edges[i];
        }
        
        randomSum -= edges[i];
    }
}
