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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return nullptr;
        
        TreeNode* ances = nullptr;
        if(isDescendant(root, p) && isDescendant(root, q)){
            ances = root;
        }
        if(ances){
            auto leftAnces = lowestCommonAncestor(root->left, p, q);
            if(leftAnces)
                ances = leftAnces;
        }
        else{
            auto rightAnces = lowestCommonAncestor(root->right, p, q);
            if(rightAnces)
                ances = rightAnces;
        }
        return ances;
    }

    bool isDescendant(TreeNode* root, TreeNode* d){
        if(!root || !d)
            return false;

        int dsd = root->val == d->val;
        return dsd || isDescendant(root->left, d) || isDescendant(root->right, d);
    }
};
