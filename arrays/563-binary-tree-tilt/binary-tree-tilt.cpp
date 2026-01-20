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

    int tilt = 0;

    int recursion(TreeNode* root){

        if(!root){
            return 0;
        }

        int leftsum = recursion(root->left);

        int rightsum = recursion(root->right);

        tilt += abs(leftsum - rightsum);


        return leftsum + rightsum + root->val;


    }

    int findTilt(TreeNode* root) {

        if(!root){
            return tilt;
        }

        recursion(root);

        return tilt;



        
    }
};