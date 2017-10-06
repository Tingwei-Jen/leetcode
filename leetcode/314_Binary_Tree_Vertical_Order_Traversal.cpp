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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        
        //level order traversal + hash table
        //level order traversal use queue        
        vector<vector<int>> res;
        if(!root) return res;
        
        
        queue<TreeNode*> q_node;                   //record node
        queue<int> q_node_vd;                      //record node's virtical distance
        
        unordered_map<int, vector<int>> hash;
        
        int max_cur = 0;
        int min_cur = 0;
        
        q_node.push(root);                         //enqueue
        q_node_vd.push(0);                              
        
        while(!q_node.empty()){
            
            TreeNode* temp = q_node.front();       //dequeue
            q_node.pop();
            int vd = q_node_vd.front();
            q_node_vd.pop();
            
            hash[vd].push_back(temp->val);         //update map
            max_cur = max(vd, max_cur);            //update max & min
            min_cur = min(vd, min_cur);
            
            if(temp->left){                        //check left child & right child and put int the queue
                q_node.push(temp->left);
                q_node_vd.push(vd-1);
            }
            if(temp->right){
                q_node.push(temp->right);
                q_node_vd.push(vd+1);
            }
        }
        
        for(int i=min_cur; i<=max_cur; i++){
            res.push_back(hash[i]);
        }
        
        return res;        
    }
};
