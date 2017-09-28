class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        
        //binary search: complexity = O(logn)
        //这道题让我们在一个有序整数数组中寻找相同目标值的起始和结束位置
        //使用两次二分查找法，第一次找到左边界，第二次调用找到右边界即可
        
        
        vector<int> res(2,-1);
        
        if(nums.size()==0)                      //要加這個條件不然會不過
            return res;
        
   
        int left = 0;
        int right = nums.size()-1;
        int mid;
        
        
        //尋找左邊界
        while(left<right){
            
            int mid = left + (right-left)/2;   
            
            if(nums[mid]<target)                 //小於
                left = mid+1;
            else                               //如果大於等於
                right = mid;   
            
        }
        
        if(nums[left] != target)
            return res;
        
            
        res[0] = left;
        
        
        //尋找右邊界 , 左邊界已經找到   
        right = nums.size()-1;
        
        while(left<right){
            
            int mid = left + (right-left)/2+1;                    //這邊要加1 !!!!   因為 int(3/2) = 1  無條件捨去
                                                                  //所以迴圈到 剩最後兩個數字時 讓mid 去等於right
            if(nums[mid]>target)
                right = mid-1;
            else 
                left = mid;                    //如果小於等於
            
        }
        
        res[1] = right;
        
        return res;

    }
};
