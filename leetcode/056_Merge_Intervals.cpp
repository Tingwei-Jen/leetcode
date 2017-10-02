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
    vector<Interval> merge(vector<Interval>& intervals) {
        
        vector<Interval> res;
        if(intervals.empty()) return res;
        
        vector<int> interval_start(intervals.size());
        vector<int> interval_end(intervals.size());        
        
        for(int i=0; i<intervals.size();i++){
            interval_start[i] = intervals[i].start;
            interval_end[i] = intervals[i].end;
        }
        sort(interval_start.begin(), interval_start.end());       //將每個區間的起點與終點做排序
        sort(interval_end.begin(), interval_end.end());
        
        int i=0;
        while(i<intervals.size()){
            
            int st = interval_start[i];
            while(i< intervals.size()-1 && interval_start[i+1] <= interval_end[i]) i++;   //如果有重疊
            int end = interval_end[i];
            Interval temp(st, end);
            res.push_back(temp);
            i++;
        }
        return res;
    }
};
