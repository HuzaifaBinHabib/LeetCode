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
    int search(vector<int>& inorder, int val, int left, int right) {
        for (int i = left; i <= right; i++) {
            if (inorder[i] == val) {
                return i;
            }
        }
        return -1;
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& idx,int left, int right) {
        if (left > right) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[idx]);
        idx++;

        int nodeidx = search(inorder,root->val, left, right);

        root->left = helper(preorder, inorder, idx, left, nodeidx - 1);
        root->right = helper(preorder, inorder, idx, nodeidx + 1, right);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        return helper(preorder, inorder, idx, 0, preorder.size() - 1);
    }
};