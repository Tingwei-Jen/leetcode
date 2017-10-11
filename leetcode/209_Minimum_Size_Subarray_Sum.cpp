class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        if(nums.size()==0) return 0;
        int minLen = INT_MAX; 
        int left = 0; 
        int sum = 0;
        
        for(int i=0;i<nums.size();i++){
            
            sum+=nums[i];                           //一直加 直到sum>=s  然後從左邊開始扣 扣到小於s 然後在加入新的數
            
            while(sum>=s && left<=i){              //找到才進入迴圈
                
                minLen = min(minLen, (i-left)+1);
                sum-=nums[left];
                left++;                
            }
        }
        
        if(minLen==INT_MAX) return 0;        //沒找到
        else return minLen;
    }
};
