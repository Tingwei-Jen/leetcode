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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        
        //case1:如果有 right subtree find min in the right subtree or the leftmost node in the right subtree
        //case2:如果沒有 right subtree, go to nearest ancestor for which given node would be in left subtree
        
        //complexity O(h) h: height of BST
        
        if(p->right){    //case1
            p = p->right;
            while(p->left){
                p = p->left;
            }
            return p;
        }
        
        //Otherwise do a regular search from root to p 
        //but remember the node of the last left-turn and return that.
        //我们首先看根节点值和p节点值的大小，如果根节点值大，说明p节点肯定在左子树中
        //那么此时我们先将res赋为root，然后root移到其左子节点，循环的条件是root存在，
        //我们再比较此时root值和p节点值的大小，如果还是root值大，我们重复上面的操作，
        //如果p节点值，那么我们将root移到其右子节点，这样当root为空时，res指向的就是p的后继节点
        else {
            
            TreeNode* res = NULL;
            while(root){
                
                if(root->val>p->val){
                    res = root;
                    root = root->left;
                } else {
                    root = root->right;                     //值相等會往右子樹走 但因這個條件是沒有右子樹的情況所以迴圈結束
                }
            }
            return res;
        }

    }
};
