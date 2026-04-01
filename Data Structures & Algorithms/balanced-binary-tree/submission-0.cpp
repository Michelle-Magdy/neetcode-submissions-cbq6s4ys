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
    
    pair<int,int> dfs( TreeNode* root){
        if(!root) return {1,0};
        pair<int,int> left = dfs(root->left);
        pair<int,int> right = dfs(root->right);
        bool balanced = (left.first == 1 && right.first == 1) && 
        (abs(left.second - right.second) <=1 );

        return {balanced? 1:0 ,1 + max(left.second,right.second)};

    }
  
    bool isBalanced(TreeNode* root) {
        return dfs(root).first == 1;

    }
};
