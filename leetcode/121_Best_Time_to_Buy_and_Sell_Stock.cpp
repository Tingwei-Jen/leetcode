class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int res = 0;
        int buy = INT_MAX;
        
        for(int i=0; i<prices.size();i++){
        
            buy = min(buy, prices[i]);        //找最小 buy;
            res = max(res, (prices[i]-buy));  //更新最大差距
        }
        
        return res;
    }
};
