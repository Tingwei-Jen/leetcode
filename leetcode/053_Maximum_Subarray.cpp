class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     
        int Curmax;
        int res;
        
        //initial
        Curmax = nums[0];
        res = nums[0];
        
        for(int i =1; i<nums.size();i++){      //從1開始遍歷(尋訪)
        
            Curmax = max((Curmax + nums[i]), nums[i]);     //更新Curmax
            res = max(res, Curmax);                        //更新max
        }
        return res;
    }
};
