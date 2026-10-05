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
        
        bool isLeftValid = dfsSmaller(root->left, root->val);
        bool isRightValid = dfsBigger(root->right, root->val);
        bool isValid = isLeftValid && isRightValid;
        
        return isValid && isValidBST(root->left) && isValidBST(root->right);
    }

    bool dfsSmaller(TreeNode* root, int max){
        if(!root)
            return true;

        return root->val < max && dfsSmaller(root->left, max) && dfsSmaller(root->right, max);
    }

    bool dfsBigger(TreeNode* root, int min){
        if(!root)
            return true;

        return root->val > min && dfsBigger(root->left, min) && dfsBigger(root->right, min);
    }
};
