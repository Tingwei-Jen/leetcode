class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        //return  method1_twopointer(s, nums);
        return method2_binarysearch(s, nums);
    }
    
    // O(n)
    int method1_twopointer(int s, vector<int>& nums){
        
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
    
    //O(nlogn)
    int method2_binarysearch(int s, vector<int>& nums){
        
        //用二分查找法找到子数组的右边界位置，使该子数组之和大于sums[i] + s，
        int len = nums.size();
        vector<int> sums(len+1, 0); 
        int res = len + 1;
        for (int i = 1; i < len + 1; ++i) 
            sums[i] = sums[i - 1] + nums[i - 1];
        for (int i = 0; i < len + 1; ++i) {
            int right = searchRight(i + 1, len, sums[i] + s, sums);
            if (right == len + 1) break;
            if (res > right - i) res = right - i;        //更新
        }
        return res == len + 1 ? 0 : res;
    }
    int searchRight(int left, int right, int target, vector<int> sums){
        
        while(left<=right){
            int mid = left+(right-left)/2;
            if(sums[mid]>=target) right = mid-1;
            else left = mid+1;
        }
        return left;
    }
};
