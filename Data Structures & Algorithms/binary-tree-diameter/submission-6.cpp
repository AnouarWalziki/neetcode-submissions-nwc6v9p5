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
        if(!root)
            return 0;
        dfs(root);
        return m_max;
    }

    int dfs(TreeNode* root){
        if(!root)
            return 0;

        int lHight = dfs(root->left);
        int rHight = dfs(root->right);
        m_max = max(m_max,lHight + rHight);
        return 1 + max(lHight, rHight);
    }
};
