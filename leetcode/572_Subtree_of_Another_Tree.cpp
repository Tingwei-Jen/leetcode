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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        
        //breaking condition 
        if(t==NULL) return true;
        else if (s==NULL) return false;
        else if (isSameTree(s,t)) return true;         
        
        //不然繼續往下找
        return isSubtree(s->left,t) || isSubtree(s->right,t);        
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(p==NULL && q==NULL) return true;
        else if (p==NULL || q==NULL) return false;
        else{
            return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right)); //往左右子樹確認
        }
    }
};
