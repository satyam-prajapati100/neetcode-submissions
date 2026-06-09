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
    bool find(TreeNode *root, TreeNode *subRoot){
        if(!root && !subRoot){
            return true;
        }

        if((!root && subRoot) || (root && !subRoot)){
            return false;
        }

        if(root->val != subRoot->val){
            return false;
        }

        return find(root->left, subRoot->left) &&
               find(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root){
            return false;
        }

        // Check if current subtree matches
        if(find(root, subRoot)){
            return true;
        }

        // Search in left and right subtrees
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};
