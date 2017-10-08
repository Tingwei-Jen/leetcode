class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        //http://tianshilei.me/2017/02/10/leetcode494/
        //https://kingsfish.github.io/2017/08/22/Leetcode-494-Target-Sum/
        //0-1背包问题
        
        /*method1:
        //helper(nums, S, 0);
        return count;*/
        
        //method2:
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }
        if(sum<S || (sum+S)%2==1) return 0;     //sum+S 須為偶數
        return subsetsum(nums, (sum+S)/2);          
    }
    /*void DFShelper(vector<int> &nums, int target, int index){
        
        if(index==nums.size()){
            if(target==0){
                count++;
            }
            return;
        }        
        helper(nums, target-nums[index],index+1); 
        helper(nums, target+nums[index],index+1);
    }*/
    
    int subsetsum(vector<int> &nums, int target){
        //use dynamic programming method!!
        //sum(p) - sum(n) = S
        //sum(p) + sum(n) = sum(nums)
        //2*sum(p) = S+sum(nums)
        //sum(p) = (S+sum(nums))/2 ---> become a subset sum problem    
        
        vector<int> DP(target+1,0);
        DP[0] = 1;
            
        for(int i=0;i<nums.size();i++){
            for(int j=target;j>=nums[i];j--){
                DP[j] = DP[j] + DP[j-nums[i]];
            }
        }
        return DP[target];   
    }
    
public:
    int count = 0;
    
};
