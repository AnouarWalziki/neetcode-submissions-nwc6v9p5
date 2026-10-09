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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "";
        queue<TreeNode*> q;
        q.push(root);

        string res;
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();

            if(current){
                res += to_string(current->val);
                q.push(current->left);
                q.push(current->right);
            }

            if(!q.empty())
                res += ',';
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())
            return nullptr;
        
        std::cout << data << endl;

        vector<TreeNode*> nodes = toNodeVector(data);

        queue<TreeNode*> q;
        q.push(nodes[0]);
        int idx = 1;

        while(!q.empty() && idx < nodes.size()){
            TreeNode* current = q.front();
            q.pop();

            if(current){
                current->left = nodes[idx++];
                if(idx < nodes.size())
                    current->right = nodes[idx++];
                if(current->left)
                    q.push(current->left);
                if(current->right)
                    q.push(current->right);
            }
        }
        return nodes[0];
    }

    vector<TreeNode*> toNodeVector(string data){
        vector<TreeNode*> res;
        string sNode;
        int i = 0;
        while(i < data.size()){
            if(data[i] == ','){
                if(sNode.empty())
                    res.push_back(nullptr);
                else{
                    res.push_back(new TreeNode(stoi(sNode)));
                    sNode = "";
                }
            } else
                sNode += data[i];

            i++;

            if(i == data.size() && !sNode.empty())
                res.push_back(new TreeNode(stoi(sNode)));
        }
        return res;
    }
};





























