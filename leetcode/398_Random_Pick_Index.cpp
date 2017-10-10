//ex. [1,2,3,3,3]  p(1) = 1/1, p(2)=1/1, p(3)=1/3

class Solution {
public:
    Solution(vector<int> nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
        
        int res = -1;
        int count = 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                int j = rand()%count;              
                if(j==0) res = i;           //然后我们随机数生成为0的话，我们交换水塘中的值和当前遍历到底值
                count++;
            }
        }  
        return res;
    }
private:
    vector<int> nums;

};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
