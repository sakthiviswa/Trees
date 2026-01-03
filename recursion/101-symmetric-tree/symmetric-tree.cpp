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

    bool recursion(TreeNode* p,TreeNode* q){
        if(!p && !q){
            return true;
        }

        if(!p || !q ){
            return false;
        }

        if(p->val != q->val ){
            return false;
        }

        bool l = recursion(p->left,q->right);
        bool r = recursion(p->right,q->left);

        return l && r;


    }
    bool isSymmetric(TreeNode* root) {
        
        return recursion(root,root);
    }
};