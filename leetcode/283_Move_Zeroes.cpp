class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        //設雙指針 從0開始跑 一個記錄不為0的狀況
        int index = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nums[index] = nums[i];
                index++;
            }
        }
        //剩下補0
        for(int i=index; i<nums.size();i++){
            nums[i] = 0;
        } 
    }
};
