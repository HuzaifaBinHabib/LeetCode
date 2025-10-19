/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->val == p->val || root->val == q->val) {
            return root;
        }
        TreeNode* lft = lowestCommonAncestor(root->left, p, q);
        TreeNode* rht = lowestCommonAncestor(root->right, p, q);

        if (lft != nullptr && rht != nullptr) {
            return root;
        } else if (lft != nullptr) {
            return lft;
        } else {
            return rht;
        }
        return nullptr;
    }
};