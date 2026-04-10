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
    int maxsum=INT_MIN;

    int solve(TreeNode* root){
        if(root==nullptr) return 0;
        int l=solve(root->left);
        int r=solve(root->right);

        int all=l+r+root->val;
        int one=max(l,r)+root->val;
        int rootmax=root->val;

        maxsum=max({maxsum,all,one,rootmax});
        return max(one,rootmax);
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxsum;

    }
};
