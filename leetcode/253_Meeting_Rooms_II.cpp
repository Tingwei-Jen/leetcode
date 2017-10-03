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
    int minMeetingRooms(vector<Interval>& intervals) {
     
        //等同於 開始進去一個人 結束出來一個人 最多同時多少人在房間裡面
        if(intervals.empty()) return 0;
        if(intervals.size()==1) return 1;
        
        vector<int> start(intervals.size());
        vector<int> end(intervals.size());
        
        for(int i=0; i<intervals.size();i++){
            start[i] = intervals[i].start;
            end[i] = intervals[i].end;
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int count =0;
        int endpoint =0;
        //如果下一個start 小於前一個end 就多一個人在房間裡面
        for(int i=0;i<intervals.size();i++){
            
            if(start[i]<end[endpoint]){
                count++;
            } else {
                endpoint++;
            }
        }
        return count;
    }
};
