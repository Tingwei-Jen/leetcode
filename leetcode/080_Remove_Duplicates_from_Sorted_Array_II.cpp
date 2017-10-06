class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size()==0) return 0;
        if(nums.size()==1) return 1;
        if(nums.size()==2) return 2;
        
        int loc = 2;  
        for(int i=2; i<nums.size();i++){
            
            if(!(nums[i]==nums[loc-1] && nums[i]==nums[loc-2])){
                nums[loc] = nums[i];
                loc++;
            } 
        }
        return loc;   
    }
};
