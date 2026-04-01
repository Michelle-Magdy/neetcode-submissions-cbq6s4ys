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
private:

    vector<string> tokenize(string& data){
        vector<string> ret;
        string temp="";
        for(char& c: data){
            if(c ==','){
                ret.push_back(temp);
                temp = "";
            }else{
                temp += c;
            }
        }
        return ret;
    }
   
  
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "n";
        queue<TreeNode*> q;
        string s="";
        q.push(root);
        while(!q.empty()){
            TreeNode* r = q.front();
            q.pop();
            if(!r){
                s+= "n,";
                continue;
            }
            q.push(r->left);
            q.push(r->right);
            s+= to_string(r->val) +',';
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tokens = tokenize(data);
        int n = tokens.size();
        if(n==0||tokens[0] == "n") return nullptr;
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(tokens[0]));
        q.push(root);
        int i=1;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(tokens[i] != "n"){
                temp->left = new TreeNode(stoi(tokens[i]));
                q.push(temp->left);
            }
            i++;
            if(tokens[i] != "n"){
                    temp->right = new TreeNode(stoi(tokens[i]));
                    q.push(temp->right);
            }
            i++;            
        }
        return root;

    }
};
