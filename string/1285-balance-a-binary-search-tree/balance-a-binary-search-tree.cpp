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

    void inorder(TreeNode* root,vector<int>& values){

        if(!root){
            return;
        }

        inorder(root->left,values);
        values.push_back(root->val);

        inorder(root->right,values);

        return ;
    }

    TreeNode* balanced(vector<int>& values,int l,int r){

        if(l > r){
            return nullptr;
        }

        int mid = (l+r)/2;

        TreeNode* root = new TreeNode(values[mid]);

        root->left = balanced(values,l,mid-1);
        root->right = balanced(values,mid+1,r);

        return root;


    }
    TreeNode* balanceBST(TreeNode* root) {

        vector<int> values;

        inorder(root,values);
        int n = values.size();

        return balanced(values,0,n-1);
        
    }
};