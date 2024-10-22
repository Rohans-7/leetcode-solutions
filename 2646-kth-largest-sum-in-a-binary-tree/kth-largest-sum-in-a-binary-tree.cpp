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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>levelSum;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            long long sumOfCurrentLevel=0;
            for(int i=q.size(); i>0; --i){
                root=q.front();
                q.pop();
                sumOfCurrentLevel += root->val;
                if(root->left){
                    q.push(root->left);
                }
                if(root->right){
                    q.push(root->right);
                }
            }
            levelSum.push_back(sumOfCurrentLevel);
        }
        if(levelSum.size()<k) return -1;
        sort(levelSum.rbegin(),levelSum.rend());
        return levelSum[k-1];
    }
};