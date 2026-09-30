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
    int m_max = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }

        m_max = hight(root->left) + hight(root->right);
        return m_max;
    }

    int hight(TreeNode* root){
        if(!root){
            return 0;
        }
        
        return 1 + max(hight(root->left), hight(root->right));
    }
};
