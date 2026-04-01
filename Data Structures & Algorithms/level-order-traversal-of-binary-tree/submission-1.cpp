/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        int l =0;
    if(!root) return {};
        vector<vector<int>> ret;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int levelSize =q.size();
            vector<int>level;
            for(int i=0;i<levelSize;i++){
                TreeNode* s = q.front();
                q.pop();
                level.push_back(s->val);
                if(s->left)
                q.push(s->left);
                if(s->right)
                q.push(s->right);
            }
            ret.push_back(level);
        }
        return ret;
    }
};
