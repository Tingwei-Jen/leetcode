class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> res;
        if (nums.size()<4) return res;
        
        sort(nums.begin(), nums.end());                              //排序 由小到大

        for (int i=0; i<nums.size()-3; i++){  
            int target2 = target - nums[i];     
            if (i>0 && nums[i]==nums[i-1])                          //從第二個數字開始 遇到重複跳過
                continue;
            
            //之後是3sum problem
            for (int left = i+1; left<nums.size()-2; left++){
                int temp = target2 - nums[left];
                int mid = left+1;     
                int right = nums.size()-1;
                
                if(left>i+1 && nums[left]==nums[left-1])           //重複跳過
                    continue;
                
                while(mid<right){
                    
                    if(nums[mid]+nums[right] == temp){             //找到了
                        
                        res.push_back({nums[i], nums[left], nums[mid], nums[right]});
                        
                        mid++;
                        right--;
                        
                        while(mid<right && nums[mid]==nums[mid-1]) mid++;           //與前一個數字相同 跳過
                        while(mid<right && nums[right]==nums[right+1]) right--; 
                        
                    } else if (nums[mid]+nums[right] > temp){
                        right--;
                    } else {
                        mid++;
                    }
                    
                }
            }
        }
                
        return res;
        
    }
};
