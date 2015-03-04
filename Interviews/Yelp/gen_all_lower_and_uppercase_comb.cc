/*
 * =====================================================================================
 *
 *       Filename:  gen_all_lower_and_uppercase_comb.cc
 *
 *    Description:  generate all possible lowercase and upper case combinations
 *
 *        Created:  03/04/2015 08:13:37
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

void dfs(vector<string> &ret, string &str, int index){
    if(index == str.size()){
        ret.push_back(str);
        return;
    }

    str[index] = oupper(str[index]);
    dfs(ret, str, index+1);
    str[index] = tolower(str[index]);
    dfs(ret, str, index+1);
}

vector<string> genCombs(string &str){
    vector<string> ret;
    dfs(ret, str, 0);
    return ret;
}
