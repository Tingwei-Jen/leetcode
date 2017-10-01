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
    bool isValidBST(TreeNode* root) {
     
        //root 介於[min, max] 之間 left介於[min, (root->val)-1 ], right 介於[(root->val)+1, max]
        //binary search tree 不能有重複的值
        
        return helper(root, NULL, NULL);      //不知道root 的範圍 先設NULL
    }
    bool helper(TreeNode* node, TreeNode* minNode, TreeNode* maxNode){
        
        if(node==NULL) return true;      //找完了, 遞迴結束
        if((minNode != NULL && node->val<= minNode->val)||(maxNode!=NULL && node->val>=maxNode->val)) return false;    

        bool flag1 = helper(node->left, minNode, node);
        bool flag2 = helper(node->right, node, maxNode);
        
        return flag1 && flag2;        
    }
};
