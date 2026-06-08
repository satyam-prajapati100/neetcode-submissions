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
    int find(TreeNode *root ,int &din){
        if(!root){
            return 0;
        }

        int left = find(root->left ,din);
        int right = find(root->right ,din);

        din = max(din, left+right);

        return 1+max(left ,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int din=0;
        find(root , din);

        return din;
    }
};
