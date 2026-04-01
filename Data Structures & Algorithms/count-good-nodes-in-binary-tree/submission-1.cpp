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
    int count =0;
    void dfs(TreeNode* root , int maxx =-101){
        if(root != nullptr){
            if(root->val >= maxx){
                maxx = root->val;
                count++;
            }
            dfs(root->left,maxx);
            dfs(root->right,maxx);
        }

    }
public:
    int goodNodes(TreeNode* root) {
        if(root != nullptr){
            dfs(root);
            return count;
        }       
        return 0;     
    }
};
