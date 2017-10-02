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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
     
        //找 newInterval's start 小於 某個interval的end的話 
        //選擇 newInterval 與 該interval 的start 較小的那個 作為插入的新start
        
        //找 newInterval's end 小於 某個Interval的start, 則該Interval 
        //前面一個 Interval 的end 來與newInterval 的end 來做比較 選擇較大的作為新end
    
        vector<Interval> res;
        int i = 0;
        int n = intervals.size();
        int nstart = newInterval.start;
        int nend = newInterval.end;
        
        while(i<n && intervals[i].end < nstart){     //找新起點, 沒找到的情況
            res.push_back(intervals[i]);
            i++;
        } 
        if(i==n){                                     //排在最後面的情況
            res.push_back(newInterval);
            return res;
        }                     
        
        //找到且判斷何者為新起點：
        nstart = min(newInterval.start, intervals[i].start);   
        
        //找到起點接著找新終點
        while(i<n && intervals[i].start <= nend){      //沒找到的情況
            nend = max(newInterval.end, intervals[i].end);        //end point 不斷更新 直到某個start > end point
            i++;
        }
        Interval temp(nstart,nend);
        res.push_back(temp);
        
        while(i<n){
            res.push_back(intervals[i]);              //把剩下加進去
            i++;
        }
        
        return res;   
    }
};
