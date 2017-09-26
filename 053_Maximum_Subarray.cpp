class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int result = INT_MIN;                           //不能int reult = 0; 因為有可能比0小
        int cur_sum = 0;
        
        for(int i=0; i<nums.size();i++){
            
            cur_sum = max(cur_sum+nums[i], nums[i]);    //KEY!!  Dynamic Programming ??
            result = max(result, cur_sum);              //更新result
            
        }
        
        return result;
        
    }
};
