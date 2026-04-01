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
    
    int dfs(TreeNode* root,int& maxVal){
        if(!root) return 0;
        int leftVal = max(dfs(root->left,maxVal),0);
        int rightVal = max(dfs(root->right,maxVal),0);
        int total = leftVal + rightVal + root->val;
        leftVal += root->val;
        rightVal += root->val;
        maxVal = max(maxVal,total);
        return max(leftVal,rightVal);
    }
public:
    int maxPathSum(TreeNode* root) {
        int res = root->val;
        dfs(root,res);
        return res;
    }
};
