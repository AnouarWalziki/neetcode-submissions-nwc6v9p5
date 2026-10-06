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
        sort(s.begin(), s.end());
        return s[k-1];
    }

    void dfs(TreeNode* root, vector<int>& s){
        if(!root)
            return;
        
        s.push_back(root->val);
        dfs(root->left, s);
        dfs(root->right, s);
    }
};
