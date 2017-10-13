class Solution {
public:
    int search(vector<int>& nums, int target) {
     
        if(nums.empty()) return -1;
        int left = 0;
        int right = nums.size()-1;
        
        while(left<right){
            
            int mid = left + (right-left)/2;    
            if(nums[mid]==target) return mid;
            if(nums[left] <= nums[mid]){                          //mid 在左半           
                if(nums[left]<=target && nums[mid]>target)        //left target mid
                    right = mid-1;
                else                                              //left mid target
                    left = mid+1;
    
            } else {                                              //mid 在右半
                if(nums[right]>=target && nums[mid]<target)        //mid target right
                    left = mid+1;
                else                                              //target mid right
                    right = mid-1;
            }
        }
        
        //離開迴圈後 left=right 重疊 
        if(nums[left]==target) return left;
        else return -1;
    }
};
