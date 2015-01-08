/*
 * =====================================================================================
 *
 *       Filename:  restore_ip.cc
 *
 *    Description:  Given a string containing only digits, restore it by returning all 
                    possible valid IP address combinations.

                    For example:
                    Given "25525511135",

                    return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 *
 *        Created:  01/07/2015 23:49:22
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if(s.empty() || s.size() > 12)   return res;
        
        vector<string> ip;
        dfs(s, res, ip, 0, 0);
        
        return res;
    }
    
private:
    void dfs(string &s, vector<string> &res, vector<string> &ip, int start, int depth){
        if(depth == 4 && start == s.size()){
            string one_sol("");
            for(auto str : ip){
                one_sol += str;
                one_sol += ".";
            }  
            
            res.push_back(one_sol.substr(0, one_sol.length()-1));
            return;
        }
        
        for(int i = start; i < s.size(); i ++){
            string partial_ip = s.substr(start, i-start+1);
            if(isvalid(partial_ip)){
                ip.push_back(partial_ip);
                dfs(s, res, ip, i+1, depth+1);   // good point
                ip.pop_back();
            }
        }
    }
    
    bool isvalid(string &s){
        int ip_val = atoi(s.c_str());
        
        if(s.size() == 1){
            return  (ip_val >= 0 && ip_val <= 9);
        }
        else if(s.size() == 2){
            return (ip_val >= 10 && ip_val <= 99);  // cannot be 0X
        }
        else if(s.size() == 3){
            return (ip_val >= 100 && ip_val <= 255);  // cannot be 00X or OX
        }
        
        return false;
    }
};



