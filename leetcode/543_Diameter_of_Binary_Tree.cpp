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
    int diameterOfBinaryTree(TreeNode* root) {

        //max(leftheight+righheight+1, max(leftdiameter, rightdiameter))
        if(!root)
            return 0;
        int leftheight = HeightOfBT(root->left);
        int rightheight = HeightOfBT(root->right);
        int leftdiameter = diameterOfBinaryTree(root->left);
        int rightdiameter = diameterOfBinaryTree(root->right);
        
        return max(leftheight+rightheight, max(leftdiameter, rightdiameter));
    }
    
    int HeightOfBT(TreeNode* node){
        
        if(!node) return 0;
        int leftheight =  HeightOfBT(node->left);
        int rightheight = HeightOfBT(node->right);
        return 1+ max(leftheight, rightheight);   
    }
};
