class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        
        //http://www.cnblogs.com/grandyang/p/5336668.html
        //ex. [-2, -1, 2, 1]
        //cur_sum = [-2, -3, -1, 0]  ---> we know answer is [-1,2]
        //-2 + k = -1  --> -1-k = -2 找 map裡面有沒有-2   len = 2-0 = 2  (-1)的位置減去 (-2)的位置
        
        //For each i, check not only the current sum but also (currentSum - previousSum) 
        //to see if there is any that equals k, and update max length.
        
        
        int cur_sum = 0;
        int max_len = 0;
        unordered_map<int, int> map;
        
        for(int i=0; i<nums.size();i++){
            cur_sum += nums[i];
            if(cur_sum == k){
                max_len = i+1;
            } else if (map.find(cur_sum-k) != map.end()){     //更新 maxlength 因為找到一組解
                max_len = max(max_len, i-map[cur_sum-k]);
            }
            if(map.find(cur_sum) == map.end()){
                map[cur_sum] = i;
            }
            
        }
        return max_len;
        
    }
};
