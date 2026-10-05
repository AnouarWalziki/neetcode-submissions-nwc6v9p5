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
    int goodNbr = 0;
    int goodNodes(TreeNode* root) {
        if(!root)
            return 0;

        dfs(root, root->val);
        return goodNbr;
    }
    
    void dfs(TreeNode* root, int maximum){
        if(!root)
            return;

        if(maximum <= root->val)
            goodNbr++;

        dfs(root->left, max(maximum, root->val));
        dfs(root->right, max(maximum, root->val));
    }
};
