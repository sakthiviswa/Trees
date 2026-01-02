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

    unordered_map<int,int> inorder_index;

    TreeNode* recursion(vector<int>& preorder,int rootindex,int left,int right){

        if(left > right){
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[rootindex]);
        int mid = inorder_index[preorder[rootindex]];

        if(left < mid){

            root->left = recursion(preorder,rootindex+1,left,mid-1);
        }

        if(mid < right){
            root->right = 
            recursion(preorder,
            rootindex+(mid-left)+1,
            mid+1,
            right
            );
        }

       return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for(int i=0;i<inorder.size();i++){
            inorder_index[inorder[i]] = i;
        }

        return recursion(preorder,
        0,
        0,
        inorder.size()-1);


        
    }
};