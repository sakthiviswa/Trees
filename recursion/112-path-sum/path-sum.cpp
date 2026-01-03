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
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        return recursive(root,0,targetSum);
    }

    bool recursive(TreeNode* root,int sum,int targetSum){

        if(root == nullptr){
            return false;
        }

        if(root->left == nullptr && root->right == nullptr && targetSum == sum+root->val){
            return true;
        }

        bool left = recursive(root->left,sum + root->val,targetSum);
        bool right = recursive(root->right,sum + root->val,targetSum);


        return left || right;

    }
};