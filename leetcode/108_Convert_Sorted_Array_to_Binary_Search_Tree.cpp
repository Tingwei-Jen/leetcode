/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      
        TreeNode* res;
        res =  BuildTree(0 ,nums.size()-1, nums);
        return res;      
    }
    TreeNode* BuildTree(int left, int right, vector<int> &nums){
        
        if(left>right) return NULL;
        int mid = left+(right-left)/2;
        TreeNode* temp = new TreeNode(nums[mid]);
        
        temp->left = BuildTree(left,mid-1,nums);
        temp->right = BuildTree(mid+1,right,nums);
        
        return temp;
    }
    
    
};
