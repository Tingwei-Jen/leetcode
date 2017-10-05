/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        
        //method1(root);
        method2(root);
    }
    
    void method1(TreeLinkNode *root){
        
        //use 102 Binary Tree Level Order Traversal method
        if(!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){    
                TreeLinkNode* temp = q.front();
                q.pop();
                if(i<n-1)
                    temp->next = q.front();
                else
                    temp->next = NULL;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }                   
    }
    
    void method2(TreeLinkNode *root){
        
        if(!root) return;    
        TreeLinkNode* pre = root;
        TreeLinkNode* cur = NULL;
        
        //從左邊往右接
        while(pre->left){
            cur = pre;
            while(cur){
                cur->left->next = cur->right;
                if(cur->next) cur->right->next = cur->next->left;
                cur = cur->next;
            }
            pre = pre->left;   
        }
    }
};
