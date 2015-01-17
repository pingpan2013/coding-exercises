/*
 * =====================================================================================
 *
 *       Filename:  max_points_on_a_line.cc
 *
 *    Description:  max points on a line
 *
 *        Created:  01/17/2015 15:19:24
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
 
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if(points.empty())  return 0;
        
        int n = points.size();
        
        unordered_map<double, int> slopeToNum;
        int maxCnt = 0;
        
        for(size_t i = 0; i < n; i ++){
            slopeToNum.clear();
            Point p1 = points[i];
            
            int dumpNum = 0;
            int tempMaxCnt = 1;
            
            for(size_t j = i + 1; j < n; j++){
                Point p2 = points[j];  
                double slope;
                
                if(p1.x != p2.x){
                    slope = (double)(p1.y - p2.y)/(double)(p1.x - p2.x);
                }
                else{
                    if(p1.y == p2.y){
                        dumpNum++;
                        continue;
                    }
                    else    slope = std::numeric_limits<double>::max();
                }
                
                if(slopeToNum.find(slope) == slopeToNum.end())
                    slopeToNum[slope] = 2;
                else
                    slopeToNum[slope]++;
                
                if(slopeToNum[slope] > tempMaxCnt)
                    tempMaxCnt = slopeToNum[slope];
            }
            
            if(dumpNum + tempMaxCnt > maxCnt)
                maxCnt = dumpNum + tempMaxCnt;
        }
        
        return maxCnt;
    }
};


