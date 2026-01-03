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
    TreeNode* first = nullptr ;
    TreeNode* second = nullptr;

    TreeNode* pre  = new TreeNode(INT_MIN);;
    void recursion(TreeNode* root){

        if(!root){
            return ;
        }

        recursion(root->left);

        if(first == nullptr && pre->val > root->val){
            first = pre;
        }

        if(first != nullptr && root->val < pre->val){
            second = root;
        }
      
        pre = root;

        recursion(root->right);

    }

    void recoverTree(TreeNode* root) {

        recursion(root);

       swap(first->val,second->val);

        
    }
};