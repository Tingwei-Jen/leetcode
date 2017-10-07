class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> res;
        if(nums.size()==0) return res;
        
        sort(nums.begin(), nums.end());
        vector<int> cur;
        addNumberDFS(res, nums, cur, 0, true);        //一開始是true!!
        return res;
    }
    void addNumberDFS(vector<vector<int>> &res, vector<int> &nums, vector<int> cur, int index, bool choosen){
        //choosen : 前一個有沒有被取
        
        if(index==nums.size()){
            res.push_back(cur);
        }
        else {
            //not choose
            addNumberDFS(res, nums, cur, index+1, false);
            
            if(choosen==true || nums[index-1] != nums[index]){
                cur.push_back(nums[index]);
                addNumberDFS(res, nums, cur, index+1, true);
                cur.pop_back();
            } //兩數相同 只有當前面被choosen 的時候才取  
        }
    }
};
