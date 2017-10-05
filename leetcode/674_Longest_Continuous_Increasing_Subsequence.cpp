class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
     
        if(nums.size()==0) return 0;
        if(nums.size()==1) return 1;
        
        int count=1;
        int max_count = 1;

        for(int i=1; i<nums.size();i++){
                
            if(nums[i]>nums[i-1]){
                count ++;
            } else {
                max_count = max(max_count, count);    
                count = 1;
            }
        }
        max_count = max(max_count, count);  //最後都是increase
        return max_count;
    }
};
