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
    int left = 0;
    int right = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }

        if(root->left)
            left = 1 + max(diameterOfBinaryTree(root->left->left), diameterOfBinaryTree(root->left->right));

        if(root->right)
            right = 1 + max(diameterOfBinaryTree(root->right->left), diameterOfBinaryTree(root->right->right));

        return left + right;
    }
};
