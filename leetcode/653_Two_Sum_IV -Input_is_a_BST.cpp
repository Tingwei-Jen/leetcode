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
    bool findTarget(TreeNode* root, int k) {

        unordered_set<int> set;
        return DFSmethod(root, set, k);
    }
    
    bool DFSmethod(TreeNode* root, unordered_set<int> &set, int k){
        
        if(root==NULL) return false;                         //沒找到
        if (set.count(k-root->val)) return true;             //找到
        else{                                                //繼續找
            set.insert(root->val);
            return DFSmethod(root->left, set, k)  || DFSmethod(root->right, set, k);   //找找左邊 找找右邊
        }   
    }
};
