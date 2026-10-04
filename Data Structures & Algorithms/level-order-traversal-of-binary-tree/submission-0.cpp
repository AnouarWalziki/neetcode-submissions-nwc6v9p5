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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
            
        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> res;
        while(!q.empty()){
            int lvlSize = q.size();
            vector<int> currVec;
            for(int i = 0; i < lvlSize; i++){
                auto current = q.front();
                q.pop();
                
                currVec.push_back(current->val);

                if(current->left)
                    q.push(current->left);

                if(current->right)
                    q.push(current->right);
            }
            res.push_back(currVec);
        }
        return res;
    }
};
