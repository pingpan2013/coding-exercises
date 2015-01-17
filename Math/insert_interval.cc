/*
 * =====================================================================================
 *
 *       Filename:  insert_interval.cc
 *
 *    Description:  insert interval
 *
 *        Created:  01/16/2015 23:21:53
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;
        
        if(intervals.empty()){
            res.push_back(newInterval);
            return res;
        }
        
        // 1. Insert
        auto it = intervals.begin();
        for( it ; it != intervals.end(); it++){
            if((it->start > newInterval.start) || (it->start == newInterval.start && it->end > newInterval.end)){            
                intervals.insert(it, newInterval);
                break;
            }
        }
        
        /* If not found */
        if(it == intervals.end())   intervals.insert(it, newInterval);
 
        // 2. Merge
        res.push_back(*intervals.begin());
        
        for(auto it = intervals.begin() + 1; it != intervals.end(); it ++){
            if(it->start > res.back().end) {
                res.push_back(*it);
                continue;
            }
            else{
                res.back().end = max(it->end, res.back().end);   
            }
        }
        
        return res;
    }
};


