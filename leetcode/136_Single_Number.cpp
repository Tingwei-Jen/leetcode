class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        //XOR will return 1 only on two different bits. So if two numbers are the same, XOR will return 0. 
        //Finally only one number left.
        //A ^ A = 0 and A ^ B ^ A = B.
        
        int res = nums[0];
        for(int i=1;i<nums.size();i++){
            res = res^nums[i];
        }
        return res;
            
    }
};
