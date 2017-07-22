/*

Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

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

bool compare(Interval i1,Interval i2)
{
    if(i1.start<i2.start)
        return true;
    else if(i1.start==i2.start)
        return i1.end<i2.end;
    else return false;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        
        sort(intervals.begin(),intervals.end(),compare);
        vector<Interval> res;
        if(intervals.size()==0)
            return res;
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();++i)
        {
            Interval last=res[res.size()-1];
            if(last.end<intervals[i].start)
                res.push_back(intervals[i]);
            else 
            {
                res.pop_back();
                if(last.end<intervals[i].end)
                last.end=intervals[i].end;
                res.push_back(last);
            }
        }
        return res;
        
    }
};
