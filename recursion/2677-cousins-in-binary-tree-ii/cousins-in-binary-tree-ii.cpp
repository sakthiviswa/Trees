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

        queue<TreeNode*>q;

        q.push(root);


        root->val = 0;


        while(!q.empty()){

            if(!root){
                return root;
            }

            int n = q.size();

            int levelsum = 0;

            vector<TreeNode*>levelnode;

            for(int i=0;i<n;i++){
                TreeNode* ele = q.front();
                q.pop();

               levelnode.push_back(ele);

                if(ele->left){
                    levelsum += ele->left->val;
                    q.push(ele->left);
                }

                if(ele->right){
                    levelsum += ele->right->val;
                    q.push(ele->right);
                }


            }



            for(TreeNode* node:levelnode){

                 int siblingsum  = 0;

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