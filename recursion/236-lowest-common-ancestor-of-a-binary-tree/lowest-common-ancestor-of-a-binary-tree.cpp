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

      return   recursion(root,p,q);

        
    }

    TreeNode* recursion(TreeNode* root,TreeNode* p,TreeNode* q){
        if(!root){
            return root;
        }

        if(root == p || root == q){
            return root;
        }

        TreeNode* l = recursion(root->left,p,q);
        TreeNode* r = recursion(root->right,p,q);

        if(l && r){
           return root;
        }

        return l?l:r;

        
    }

};