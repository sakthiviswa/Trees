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

    int maxsum = INT_MIN;

    int recursion(TreeNode* root){

        if(!root){
            return 0;
        }

        int left = max(0,recursion(root->left));
        int right = max(0,recursion(root->right));

        maxsum = max(maxsum,root->val+left+right);

        return root->val+max(left,right);


    }
    int maxPathSum(TreeNode* root) {

        recursion(root);

       return maxsum;
        
    }
};