class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        //當要找東西的時候 用map 的find 是不錯的選項 O(n)
        
        map<int, int> mymap;                         //map<key, value>  
        map<int,int>::iterator iter;                 
        vector<int> ans;
    
        for (int i = 0; i<nums.size(); i++){
            
            int numtofind = target-nums[i];
            iter = mymap.find(numtofind);            //只能find key 
             
            
            if(iter != mymap.end()){                 //找到了
                
                
                //first:value, second:index
                ans.push_back(iter->second);
                ans.push_back(i);
                
                return ans;
                
            } else {     //沒找到 
                         //就把現在尋訪的數字  放進map裡面 //first:value, second:index //一開始map 是空的
                
                mymap[nums[i]] = i;
                
            }
            
             
        }
        
    }
};
