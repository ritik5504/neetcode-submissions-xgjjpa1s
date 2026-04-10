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
    bool subtree(TreeNode* p, TreeNode* q){
        if(p==nullptr && q==nullptr) return true;
        if(p!=nullptr && q==nullptr) return false;
        if(p==nullptr && q!=nullptr) return false;

        bool left=subtree(p->left,q->left);
        bool right=subtree(p->right,q->right);

        bool value=p->val==q->val;

        if(left && right && value) return true;

        return false;

    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr)return false;
        if(subtree(root,subRoot)) return true;
        if(root->left != nullptr && isSubtree(root->left,subRoot)) return true;
        if(root->right != nullptr && isSubtree(root->right,subRoot)) return true;

        return false;
        
    }
};
