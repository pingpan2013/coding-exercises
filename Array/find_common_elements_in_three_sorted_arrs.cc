/*
 * =====================================================================================
 *
 *       Filename:  find_common_elements_in_three_sorted_arrs.cc
 *
 *    Description:  find commom elements in three sorted arrs
 *
 *        Created:  02/06/2015 01:27:18
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

Class Solution{
    public:
        vector<int> findCommomElements(vector<int> &v1, vector<int> &v2, vector<int> &v3){
            int l1 = v1.size();
            int l2 = v2.size();
            int l3 = v3.size();

            assert(l1 > 0 && l2 > 0 && l3 > 0);  // otherwise no common elements
            set<int> result;

            int i = 0, j = 0, k = 0;
            while(i < l1 && j < l2 && k < l3){
                if(v1[i] == v2[j] && v2[j] == v3[k]){
                    set.insert(v1[i]);  // use set to prevent duplicates
                    i++;
                    j++;
                    k++;
                }
                
                if(v1[i] < v2[j]) i++;
                else if(v2[j] < v3[k]) j++;
                else k++;                    // each time move only one pointer
            }
    
            vector<int> res(set.begin(), set.end());
            return res;
        }
};
