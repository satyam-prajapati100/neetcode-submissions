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
    int balance(TreeNode *root , int &visit){
        if(!root){
            return 0;
        }

        int left = balance(root->left , visit);
        int right = balance(root->right , visit);

        if (abs(left - right) > 1){
            visit=0;
        }

        return 1+max(left ,right);
    }
    bool isBalanced(TreeNode* root) {
       int visit=1;
       balance(root ,visit);

       return visit;

        
    }
};
