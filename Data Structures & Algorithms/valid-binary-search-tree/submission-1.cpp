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
        if(!root)
            return true;

        if(!root->left && !root->right)
            return true;
        
        bool isValid = root->left ? root->left->val <= root->val : true;
        isValid = root->right ? isValid && (root->val <= root->right->val) : true;
        
        return isValid && isValidBST(root->left) && isValidBST(root->right);
    }
};
