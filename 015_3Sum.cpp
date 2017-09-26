class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());                                 //先做大小排序   由小到大
        
        
        // two pointers 向中間集中 找答案
        // 先指定 left 的值  為一個小於零的值
        // mid 只能往右 right 只能往左
        
        for(int left = 0; left<nums.size(); left++){        //left 從 整個陣列的最小開始
            
            int mid = left +1;
            int right = nums.size()-1;       
            int temp = 0-nums[left];                         //left + mid + right = 0
        
            if (left>0 && nums[left] == nums[left-1])                //從第二個數字開始 遇到重複跳過 
                continue;
            
            
            while(mid < right){
            
                if (nums[mid]+nums[right] == temp){                       //找到答案放入 res 如果重複則跳過
                

                    res.push_back({nums[left], nums[mid], nums[right]});
                

                    while(mid<right && nums[mid]==nums[mid+1]) mid++;           //如果重複直到找到下一個沒出現過的mid  先排序過了                
                    while(mid<right && nums[right]==nums[right-1]) right--;
                                    
                    mid++;                                                      //mid 往右一格 right 往左一格
                    right--;
                    
                } else if (nums[mid]+nums[right] > temp){
                     right --;                                           //太大 right 往左
                } else {
                    mid ++;                                              //太小 mid 往右
                }
            }     
            
        }
        

        return res;

        
    }
};
