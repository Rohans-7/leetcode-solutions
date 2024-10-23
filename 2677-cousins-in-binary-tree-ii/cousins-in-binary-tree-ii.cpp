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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root==NULL) return root;
        queue<TreeNode*>q;
        vector<int>levelSum;
        q.push(root);
        while(!q.empty()){
            int curr=0;
            int n=q.size();
            for(int i=0; i<n; ++i){
                TreeNode* temp=q.front();
                q.pop();
                curr+=temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            levelSum.push_back(curr);
        }

        q.push(root);
        root->val=0;
        int i=1;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                TreeNode* curr=q.front();
                q.pop();
                int sibSum=0;
                if(curr->left) sibSum+=curr->left->val;
                if(curr->right) sibSum+=curr->right->val;
                if(curr->left){
                    curr->left->val=levelSum[i]-sibSum;
                    q.push(curr->left);
                }
                if(curr->right){
                    curr->right->val=levelSum[i]-sibSum;
                    q.push(curr->right);
                }
            }
            i++;
        }
        return root;
    }
};