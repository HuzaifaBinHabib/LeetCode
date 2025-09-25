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
    TreeNode* helper(TreeNode* root,int key) {
       if(root == nullptr){
        return new TreeNode(key);
       }
       if(key < root->val){
       root->left = helper(root->left,key);
       }
       if(key > root->val){
       root->right = helper(root->right,key);
       }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root =nullptr;
        for(int num: preorder){
         root = helper(root,num);
        }
        return root;
    }
};