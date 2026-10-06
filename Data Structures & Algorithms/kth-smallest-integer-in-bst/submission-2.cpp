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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> s;
        dfs(root, s);
        return s[k-1];
    }

    void dfs(TreeNode* root, vector<int>& s){
        if(!root)
            return;
        
        dfs(root->left, s);
        s.push_back(root->val);
        dfs(root->right, s);
    }
};
