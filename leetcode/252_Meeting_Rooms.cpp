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
    bool canAttendMeetings(vector<Interval>& intervals) {
        
        //排序過後, 思路：開始進來一個人, 結束出去一個人, 房間內不能同時有兩個人
        if(intervals.empty()) return true;
        if(intervals.size()==1) return true;
        vector<int> start(intervals.size());
        vector<int> end(intervals.size());
        for(int i=0;i<intervals.size();i++){
            start[i] = intervals[i].start; 
            end[i] = intervals[i].end;
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        
        for(int i=1;i<intervals.size();i++){
            
            if(end[i-1] > start[i])
                return false;
        }
        return true;
    }
};
