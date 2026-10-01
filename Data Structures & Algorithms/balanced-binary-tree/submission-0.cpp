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
    bool balanced = true;
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return balanced;
    }

    int dfs(TreeNode* root){
        if(!root)
            return 0;

        int lHight = dfs(root->left);
        int rHight = dfs(root->right);
        int diff = abs(lHight - rHight);
        if(balanced && (diff > 1))
            balanced = false;
        
        return 1 + max(lHight, rHight);
    }
};
