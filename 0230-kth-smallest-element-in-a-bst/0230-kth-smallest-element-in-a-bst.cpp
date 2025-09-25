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
    int order = 0;
    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr){
            return -1;
        }
        if(root->left!= nullptr){
           int lft = kthSmallest(root->left,k);
           if(lft != -1){
              return lft;
           }
        }
        if(order+1 == k){
            return root->val;
        }
        order++;
        if(root->right != nullptr){
            int rht = kthSmallest(root->right,k);
            if(rht != -1){
               return rht;
            }
        }
        return -1;
    }
};