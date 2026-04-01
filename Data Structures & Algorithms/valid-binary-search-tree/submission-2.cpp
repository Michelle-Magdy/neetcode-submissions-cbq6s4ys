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
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, nullptr, nullptr);
    }
    
private:
    bool isValidBSTHelper(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if (!root) return true;
        
        // Check if current node's value violates the min/max constraints
        if (minNode && root->val <= minNode->val) return false;
        if (maxNode && root->val >= maxNode->val) return false;
        
        // For left subtree: current node becomes the max boundary
        // For right subtree: current node becomes the min boundary
        return isValidBSTHelper(root->left, minNode, root) && 
               isValidBSTHelper(root->right, root, maxNode);
    }
};