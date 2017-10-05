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
    vector<double> averageOfLevels(TreeNode* root) {
     
        vector<double> res;
        vector<int> num;
        DFSmethod(res, num, root, 0);
        return res;
    }
    
    void DFSmethod(vector<double>& res, vector<int>& num, TreeNode* root, int level){
        
        if(root==NULL) return;
        
        if(res.size()<=level){      //長度不夠
            res.push_back(0);
            num.push_back(0);
        }
        
        double temp;
        temp = res[level]*num[level] + root->val;                //原先總和加上新的數
        num[level] +=1;
        temp = temp/num[level];
        res[level] = temp;
            
        DFSmethod(res, num, root->left, level+1);
        DFSmethod(res, num, root->right, level+1);
    }
};
