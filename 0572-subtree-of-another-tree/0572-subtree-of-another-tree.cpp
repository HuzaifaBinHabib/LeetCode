/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isidentical(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr) {
            return p == q;
        }

        bool lft = isidentical(p->left, q->left);
        bool rht = isidentical(p->right, q->right);

        return lft && rht && p->val == q->val;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr || subRoot == nullptr) {
            return root == subRoot;
        }
        if (root->val == subRoot->val && isidentical(root, subRoot)) {
            return true;
        }
        bool lft = isSubtree(root->left, subRoot);
        bool rht = isSubtree(root->right, subRoot);

        return lft || rht;
    }
};