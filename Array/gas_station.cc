/*
 * =====================================================================================
 *
 *       Filename:  gas_station.cc
 *
 *    Description:  gas station, 2nd try
 *
 *        Created:  02/21/2015 10:43:30
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if(gas.empty()) return 0;
            
        int n = gas.size();
        int i = 0;
        
        while(i < n){
            int cnt =  0;
            int tmp = i;
            int tank = 0;
            
            while(tank + gas[i%n] - cost[i%n] >= 0){
                tank += gas[i%n] - cost[i%n];
                i++;
                cnt++;
                
                if(cnt == n){
                    return tmp;
                }
            }    
            
            i = i+1;
        }
        
        return -1;
    }
};

