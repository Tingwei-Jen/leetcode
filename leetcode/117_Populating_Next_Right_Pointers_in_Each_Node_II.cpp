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
        
        //O(n) time O(1) space
        TreeLinkNode* now = root;    
        TreeLinkNode* head = NULL;   //next level left most  
        TreeLinkNode* tail = NULL;   //next level right most
        
        while(now){
            
            if(now->left){
                if(tail){                    //tail接到旁邊另一個node的left;
                   tail->next = now->left;
                    tail = tail->next;
                } else{
                    head = now->left;
                    tail = now->left;
                }
            }
            if(now->right){
                if(tail){
                    tail->next = now->right;
                    tail = tail->next;
                } else{
                    head = now->right;
                    tail = now->right;
                }
            }
            if(!now->next){
                now = head;
                head = NULL;
                tail = NULL;
            } else {
                now = now->next;
            }
        }      
    }
};
