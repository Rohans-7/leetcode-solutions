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
    pair<int,int> f(TreeNode* root,int &count){
        if(root==NULL){
            return {0,0};
        }

        auto l=f(root->left,count);
        auto r=f(root->right,count);

        int sum=l.first+r.first+root->val;
        int ele=l.second+r.second+1;

        if(sum/ele==root->val){
            count++;
        }

        return {sum,ele};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int count=0;
        f(root,count);
        return count;
    }
};