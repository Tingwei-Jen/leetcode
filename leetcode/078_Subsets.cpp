class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> res;
        if(nums.size()==0) return res;
        
        vector<int> cur;
        addnumberDFS(res, nums, 0, cur);
        
        return res;
        
    }
    
    void addnumberDFS(vector<vector<int>> &res, vector<int> &nums, int index, vector<int> cur){
        
        res.push_back(cur);                               //遞迴這個動作
        
        for(int i=index; i<nums.size();i++){    
            cur.push_back(nums[i]);
            addnumberDFS(res, nums, i+1, cur);            // i + 1 !!
            cur.pop_back();                              //回到上一個node  //[1,2]---> [1,3]
        }
    }
};
