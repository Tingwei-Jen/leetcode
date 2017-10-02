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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        //Edge/Condition   結束遞迴
        if(!root)                            //沒找到
            return NULL;
        if(root==p || root==q)               //找到了
            return root;
        
        //Divide
        TreeNode* left = lowestCommonAncestor(root->left, p, q);        //往左找
        TreeNode* right = lowestCommonAncestor(root->right, p, q);      //往右找
        
        //Conquer
        if(left && right)                  
            return root;           // LCA 會回傳到最上層
        else if (!left)                   
            return right;          // [left, right] = [NULL, right] --> return right
        else if (!right)
            return left; 
        
    }
};
