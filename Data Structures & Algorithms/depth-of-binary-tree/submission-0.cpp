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
    int maxDepth(TreeNode* root) {
        int depth = 0;
        traverse(root, depth);
        return m_max;
    }
private:
    int m_max = 0;
    void traverse(TreeNode* root, int k){
        if(!root){
            m_max = max(m_max, k);
            return;
        }

        k++;
        traverse(root->left, k);
        traverse(root->right, k);
        k--;
    }
};
