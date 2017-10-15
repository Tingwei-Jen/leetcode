class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> res;
        if(nums.size()==0) return res;
        
        vector<int> cur;
        //addnumberDFSmethod1(res, nums, 0, cur);
        addnumberDFSmethod2(res, nums, 0, cur);
        return res;
        
    }
    
    void addnumberDFSmethod1(vector<vector<int>> &res, vector<int> &nums, int index, vector<int> cur){
        
        res.push_back(cur);                               //遞迴這個動作
        
        for(int i=index; i<nums.size();i++){    
            cur.push_back(nums[i]);
            addnumberDFSmethod1(res, nums, i+1, cur);            // i + 1 !!
            cur.pop_back();                              //回到上一個node  //[1,2]---> [1,3]
        }
    }
    
    void addnumberDFSmethod2(vector<vector<int>> &res, vector<int> &nums, int index, vector<int> cur){       
        if(index == nums.size()){
            res.push_back(cur);
            return;            
        } //跑完 做紀錄

        //not chooose
        addnumberDFSmethod2(res, nums, index+1, cur);
        // choose
        cur.push_back(nums[index]);
        addnumberDFSmethod2(res, nums, index+1, cur);
        cur.pop_back();
    }
};
