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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root) addStringDFS(root, res, "");
        return res;
    }
    
    void addStringDFS(TreeNode* node, vector<string> &res, string curString){
        
        curString = curString + to_string(node->val);
        if(!node->left && !node->right){                      //遞迴結束
            res.push_back(curString);
            return;
        }
        if(node->left)addStringDFS(node->left, res, curString+"->");
        if(node->right)addStringDFS(node->right, res, curString+"->");
    }
};
