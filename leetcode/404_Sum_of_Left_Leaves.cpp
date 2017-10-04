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
    int sumOfLeftLeaves(TreeNode* root) {
        
        //edge
        if(!root) return 0;

        if(root->left && !root->left->left && !root->left->right)   //is leave!!
            return root->left->val + sumOfLeftLeaves(root->right);  //要同時return root->left and root->right
        
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);  //not leave; 進去找leave
        
    }
};
