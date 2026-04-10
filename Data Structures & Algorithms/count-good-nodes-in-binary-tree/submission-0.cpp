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
    int goodNodes(TreeNode* root) {
        if(root==nullptr)return 0;
        int count=0;

        queue<pair<TreeNode* ,int>>q;
        q.push({root,root->val});

        while(!q.empty()){
            int n=q.size();

            for(int i=0;i<n;i++){
                auto curr=q.front();
                q.pop();
                TreeNode* node=curr.first;
                int temp=curr.second; 
                if(node->val>=temp)count++;

                int newMax=max(node->val,temp);

                if(node->left) q.push({node->left,newMax});
                if(node->right) q.push({node->right,newMax});


                
            }
        }
        return count;
        
    }
};
