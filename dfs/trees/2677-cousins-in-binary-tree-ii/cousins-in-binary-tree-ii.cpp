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
    TreeNode* replaceValueInTree(TreeNode* root) {

        if(!root){
            return nullptr;
        }

        queue<TreeNode*> q;
        q.push(root);

        root->val = 0;

        while(!q.empty()){

            vector<TreeNode*> levelnode;
            int levelsum = 0;

            int n = q.size();

            for(int i=0;i<n;i++){

                TreeNode* node = q.front();
                q.pop();

                levelnode.push_back(node);

                if(node->left){
                    levelsum += node->left->val;
                    q.push(node->left);
                }

                if(node->right){
                    levelsum += node->right->val;
                    q.push(node->right);

                }
            }



            for(TreeNode* node:levelnode){

             int siblingsum = 0;
                if(node->left){
                    siblingsum += node->left->val;
                }

                if(node->right){
                    siblingsum += node->right->val;

                }


                if(node->left){
                    node->left->val = levelsum - siblingsum;
                }

                if(node->right){
                    node->right->val = levelsum - siblingsum;
                }

            }


        
        }


        return root;
        
    }
};