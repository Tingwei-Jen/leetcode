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
     
        //lowestCommonAncestor 會介於兩個值的中間 因為是binary search tree.
        if(root->val > max(p->val, q->val)) //往左邊找
            return lowestCommonAncestor(root->left, p, q);           
        else if (root->val < min(p->val, q->val)) //往右邊找
            return lowestCommonAncestor(root->right, p, q);  
        else
            return root;
    }
};
