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

    int first = 0 ;
    long long second = LLONG_MAX;

    void recursion(TreeNode* root){
        if(!root){
            return ;
        }

        if(root->val  > first && second > root->val ){
            second = root->val;
        }

        recursion(root->left);
        recursion(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {

        if(!root){
            return -1;
        }

        first = root->val;

        recursion(root);

        return second;
        
    }
};