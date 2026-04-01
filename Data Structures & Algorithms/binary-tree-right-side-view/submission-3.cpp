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
    vector<int> bfs(TreeNode* root){
        deque<TreeNode*> q;
        vector<int> v;
        q.push_back(root);        
        while(!q.empty()){
             v.push_back(q.back()->val);
            int levelSize = q.size();
            for(int i =0;i<levelSize;i++){
                TreeNode* curr = q.front();
                q.pop_front();
                if(curr->left!=nullptr){
                    q.push_back(curr->left);
                }
                if(curr->right!= nullptr){
                    q.push_back(curr->right);
                }
            }
           
        }
        return v;
    }
    vector<int> rightSideView(TreeNode* root) {
        if(root != nullptr)
            return bfs(root);
        else return {};
    }
};
