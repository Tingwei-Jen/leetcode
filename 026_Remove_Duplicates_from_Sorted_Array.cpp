class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return 1;
        
        int count = 0;
        
        for (int i=1;i<nums.size();i++){
            
            if(nums[count] !=nums[i]){           // curent != next  看 下一個是不是等於現在這個
                count++;                         // 如果不等於 --> count +1, 然後把nums[i] 放進來 把原先的取代掉
                nums[count] = nums[i];
            }
        }
        
        count = count +1;     //加上最一開始的數字
        return count;        
    }
};
