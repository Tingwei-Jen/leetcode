class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        //ex.[1,2,3] target=4
        //走到第四層有三種選擇  1,2,3
        //state: f[i]
        //init: f[0] = 1
        //transition func: f[i] = f[i-1] + f[i-2] + f[i-3] --> f(4) = f(4-1)+f(4-2)+f(4-3)+...
        //res=f[target]
    
        vector<int> f(target+1,0);
        f[0] = 1;
        for(int i=1;i<=target;i++){
            for(int j=0;j<nums.size();j++){
                if(i>=nums[j]){
                    f[i]+=f[i-nums[j]];      
                }
            }    
        }    
        return f[target];
    }
};
