class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        

        map<int, int> mymap;
        map<int,int>::iterator iter;
        vector<int> ans;
    
        for (int i = 0; i<nums.size(); i++){
            
            int numtofind = target-nums[i];
            iter = mymap.find(numtofind);
             
            
            if(iter != mymap.end()){
                
                
                //first:value, second:index
                ans.push_back(iter->second);
                ans.push_back(i);
                
                return ans;
                
            } else {     //沒找到放進map裡面 //first:value, second:index //一開始map 是空的
                
                mymap[nums[i]] = i;
                
            }
            
             
        }
        
    }
};