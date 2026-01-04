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
    vector<TreeNode*> forest;
    unordered_set<int> del;
    
    void recursion(TreeNode* &root){

        if(!root){
            return ;
        }

        recursion(root->left);
        recursion(root->right);

        if(del.count(root->val)){

            if(root->left){
                forest.push_back(root->left);
            }

            if(root->right){
                forest.push_back(root->right);
            }

            root = nullptr;
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {

       

        del = unordered_set<int>(to_delete.begin(),to_delete.end());

        recursion(root);

        if(root){
            forest.push_back(root);
        }

        sort(forest.begin(),forest.end());


        return forest;

        
        
    }
};