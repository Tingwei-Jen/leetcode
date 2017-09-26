class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        /*for (int i=0; i<nums.size();i++){
            
            if(nums[i]>=target)                   //找到比target大的 就把target 插進來
                return i;
            
        }
        
        return nums.size();*/                       // vector 內數字都比較小 放最後
        
        
        //binary search
        //二分法 時間複雜度 O(logn)
        //二分法的关键思想是   假设该数组的长度是N那么二分后是N/2，再二分后是N/4……直到二分到1结束
        //（当然这是属于最坏的情况了，即每次找到的那个中点数都不是我们要找的），
        //那么二分的次数就是基本语句执行的次数，于是我们可以设次数为x，N*（1/2）^x=1；则x=logn,底数是2，
        //ex. N = 2, x = 1; N = 4, x = 2;
        
        
        if (nums.back()<target) 
            return nums.size();
        
        int left = 0; 
        int right = nums.size()-1;
        
        while(left<right){
            
         int mid = left + (right-left)/2;   
         
         if (nums[mid]==target) 
             return mid;
         else if (nums[mid]<target)
             left = mid + 1;
         else
             right = mid;
            
        }
        
        return right;                        // [1,3], if target =2, right 的位置插入 target
        
    }
};
