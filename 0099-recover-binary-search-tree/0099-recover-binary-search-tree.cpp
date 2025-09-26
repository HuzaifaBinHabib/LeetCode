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
    TreeNode* prev = nullptr;
    TreeNode* first = nullptr;
    TreeNode* sec = nullptr;


    void helper(TreeNode* root){
        if(root == nullptr){
            return;
        }
        helper(root->left);
        if(prev!=nullptr && prev->val > root->val){
            if(first == nullptr){
                first = prev;
            }
            sec = root;
        }
         prev = root;
        helper(root->right); 
    }
    void recoverTree(TreeNode* root) {
        if(root == nullptr){
            return;
        }
        helper(root);
        int temp = first->val;
        first->val = sec->val;
        sec->val = temp;
    }
};