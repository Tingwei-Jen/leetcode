class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //2*sum(p)  = sum(nums)    //sum(nums) 須為偶數
        //sum(p) = sum(nums)/2
        //subsetsum problem
        
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2==1) return false;
        int target = sum/2;
        
        
        /*bool T[nums.size()+1][target+1];
        for(int i=0;i<(nums.size()+1);i++){
            for(int j=0;j<(target+1);j++){
                T[i][j] = false;
            }
        }
        
        T[0][0] = true;
        
        for(int i=1;i<(nums.size()+1);i++){        //第一行都是True;
            T[i][0] = true;
        }
  
        for (int i = 1; i < nums.size()+1; i++) {
            for (int j = 1; j < target+1; j++) {
                T[i][j] = T[i-1][j];
                if (j >= nums[i-1]) {
              o      T[i][j] = (T[i][j] || T[i-1][j-nums[i-1]]);
                }
            }
        }
        
        return T[nums.size()][target];*/
        
        //optimize space complexity
        bool dp[target+1];
        for(int i=0;i<target+1;i++)
            dp[i] = false;
        
        dp[0]=true;
        
        for(int k: nums){
            for(int j=target; j>=k;j--)
                dp[j] = dp[j] || dp[j-k];
        }
        return dp[target];
    }
};
