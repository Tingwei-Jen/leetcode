class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
     
        int count =0;
        
        for (int i=0;i<nums.size();i++){
            
            if (nums[i]!=val){                    //尋訪 不同的放進來 count ++
                nums[count] = nums[i];
                count ++;
            }
        }
        
        return count;       
        
        
    }
};
