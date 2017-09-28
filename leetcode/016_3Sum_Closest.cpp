class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
     
        
        sort(nums.begin(), nums.end());    //排序 小到大
        
        int sum;      //三數相加
        sum = nums[0]+nums[1]+nums[2];      //initial
        
        
        for(int left=0; left<nums.size()-2; left++){
            
            int mid = left + 1;
            int right = nums.size()-1;
            
            
            while(mid<right){
                
                int temp = target-nums[left];                                           // (target-nums[left])   (nums[mid]+nums[right]) 越接近越好
                
                if(abs(temp-(nums[mid]+nums[right]))  <  abs(target-sum)){              //更新sum , 找到更接近的一組
                    
                   sum = nums[left] + nums[mid] + nums[right];
                    
                }
                
                if (nums[mid]+nums[right] == temp){                                     //剛好等於 結束, 回傳 前一個最接近的sum
                    return sum;
                } else if (nums[mid]+nums[right] > temp){
                    right--;
                } else {
                    mid++;
                }
                
            }
        }
        
        
        return sum;
        
    }
};
