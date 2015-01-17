/*
 * =====================================================================================
 *
 *       Filename:  merge_intervals.cc
 *
 *    Description:  merge intervals
 *
 *        Created:  01/17/2015 17:00:08
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
class Solution {
public:
    // for priority queue
    struct cmp{
        bool operator()(Interval x, Interval y){
            if(x.start == y.start)
                return (x.end < y.end);
            return (x.start < y.start);
        }
    };

    // for sorting
    static bool comp(Interval x, Interval y){
        if(x.start == y.start)
            return (x.end < y.end);
        return (x.start < y.start);
    }
    
    // first sort
    // then merge
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        if(intervals.empty())   return res;
        
        // Sort: 1. using priority_queue
        //       2. sort directly
        sort(intervals.begin(), intervals.end(), comp);
        
        // Merge
        res.push_back(*intervals.begin());
        
        for(auto it = intervals.begin() + 1; it != intervals.end(); it ++){
            if(it->start > res.back().end){
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
