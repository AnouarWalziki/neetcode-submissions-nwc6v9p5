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

/*Do it with dfs and using N as Null and vector of strings*/

void dfsSerialize(TreeNode* root, vector<string>& res){
    if(!root){
        res.push_back("N");
        return;
    }
    
    res.push_back(to_string(root->val));
    dfsSerialize(root->left, res);
    dfsSerialize(root->right, res);
}

string join(const vector<string>& in, char separator){
    string res;
    for(int i = 0; i < in.size(); i++){
        res += in[i];
        if(i != in.size() - 1)
            res += separator;
    }
    return res;
}

vector<string> split(const string& in, char separator){
    vector<string> res;
    string current;
    for(int i = 0; i < in.size(); i++){
        if(in[i] == ','){
            res.push_back(current);
            current.clear();
        } else{
            current += in[i];
        }
        if(i == in.size() - 1 && !current.empty())
            res.push_back(current);
    }
    return res;
}

TreeNode* dfsDeserialize(const vector<string>& nodes, int& idx){
    if(nodes[idx] == "N")
        return nullptr;
    
    TreeNode* node = new TreeNode(stoi(nodes[idx]));
    idx++;
    node->left = dfsDeserialize(nodes, idx);
    idx++;
    node->right = dfsDeserialize(nodes, idx);
    return node;
}

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> nodes;
        dfsSerialize(root, nodes);
        return join(nodes, ',');
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes = split(data, ',');
        int idx = 0;
        return dfsDeserialize(nodes, idx);
    }
};
    