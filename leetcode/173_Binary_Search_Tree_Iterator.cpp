/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Inorder Traversal: 由小排到大


class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while(root){
            s.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        
        TreeNode* temp = s.top();
        s.pop();
        if(temp->right){
            
            /** put all the left child() of root */
            TreeNode* node = temp->right;
            while(node){
                s.push(node);
                node = node->left;
            }
        }
        return temp->val;
    }

private:
    stack<TreeNode*> s;

};
/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
