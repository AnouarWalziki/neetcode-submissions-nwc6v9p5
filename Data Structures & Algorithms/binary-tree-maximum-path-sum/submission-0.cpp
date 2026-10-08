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
    int maxPathSum(TreeNode* root) {
        int res = -INT_MAX;
        dfs(root, res);
        return res;
    }

    int dfs(TreeNode* root, int& res){
        if(!root)
            return 0;
        
        int leftV = dfs(root->left, res);
        int rightV = dfs(root->right, res);
        int totalSum = root->val + leftV + rightV;
        int maxSum = root->val + max(leftV, rightV);
        res = max(res, totalSum);
        res = max(res, maxSum);
        return maxSum;
    }
};
