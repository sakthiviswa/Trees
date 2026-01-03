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
    void flatten(TreeNode* root) {

        if(root == nullptr){
            return ;
        }

        while(root != nullptr){

            if(root->left != nullptr){
                TreeNode* templeft = root->left;
                TreeNode* temproot = templeft;
            

                while(temproot ->right != nullptr){
                    temproot = temproot->right;
                }

                temproot->right = root->right;

                root->left = nullptr;

                root->right = templeft;

            }

            root = root->right;

        }


        
    }
};