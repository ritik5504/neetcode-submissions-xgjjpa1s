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
    bool isValidBST(TreeNode* root) {
        if(root==nullptr) return true;
        queue<pair<TreeNode*, pair<long long, long long>>> q;
        q.push({root, {LLONG_MIN, LLONG_MAX}});

        while(!q.empty()){
            auto curr=q.front();
            q.pop();

            TreeNode* node=curr.first;
            long long low=curr.second.first;
            long long high=curr.second.second;

            if(node->val <= low || node->val>=high){
                return false;
            }
            if(node->left)q.push({node->left,{low,node->val}});
            if(node->right)q.push({node->right,{node->val,high}});
        }
        return true;
    }
};
