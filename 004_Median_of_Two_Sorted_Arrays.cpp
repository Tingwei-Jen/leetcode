class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size()==0){
            
            int n = nums2.size();                                       // if size = 5, median = nums[2]
            if (n==0) return -1;                                        // if size = 4, median = (nums[1]+nums[2]) / 2
            
            double median = (nums2[n/2]+nums2[(n-1)/2])/2.0;            // return double!!!!!                 
            return median;
        }
             
        if(nums2.size()==0){
            
            int n = nums1.size();
            if (n==0) return -1;
            double median = (nums1[n/2]+nums1[(n-1)/2])/2.0;
            return median;
        }
        
        
        int n = nums1.size();                                         
        int m = nums2.size();
        
        if(n>m)                                                         //保證數組1 為短的
            return findMedianSortedArrays(nums2, nums1);
        
        
        int L1,L2,R1,R2;
        int C1,C2;                      //分割
        
        int low = 0;                    //更新c1  用來二分數組1             
        int high = 2*n ;                //加入 虛擬＃ 所以數組1現在長度為(2n+1) 最後一格內元素為 nums1[2n]
                                        // A = nums1'+nums2' 
                                        //所以 加入虛擬後 A的總長度為2m+2n+2 中位數位置為 m+n+1  所以是(A[m+n]+A[m+n+1])/2
        
        while(low<=high){                //二分 nums1
        
        
            C1 = (low+high)/2;
            C2 = m+n-C1;
        
            L1 = (C1==0)? INT_MIN : nums1[(C1-1)/2];         //如果L1整個比R2還要大 中位數在R2 所以 L1 = INT_MIN 下面break 跳出迴圈 
            L2 = (C2==0)? INT_MIN : nums2[(C2-1)/2];         //且 max(L1,L2)時 會等於L2
            R1 = (C1==2*n)? INT_MAX : nums1[C1/2];
            R2 = (C2==2*m)? INT_MAX : nums2[C2/2];
        
                
            if(L1>R2)                       //C1 往左
                high = C1-1;
            else if (L2>R1)                 //C1 往右            
                low = C1+1;
            else 
                break;
            
        }
        
        double median = (max(L1,L2) + min(R1,R2))/2.0;         //return double!!!
        return median;
        
        
        
    }
};
