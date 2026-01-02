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

    void recursioin(TreeNode* root,vector<vector<int>>& ans,vector<int>&path,
    int curSum,int targetSum){

        if(root == nullptr){
            return ;
        }

        curSum += root->val;
        path.push_back(root->val);

        if(root->left == nullptr && root->right == nullptr && curSum == targetSum){
            ans.push_back(path);
        }

        recursioin(root->left,ans,path,curSum,targetSum);
        recursioin(root->right,ans,path,curSum,targetSum);

        path.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> ans;

        vector<int>path;
        recursioin(root,ans,path,0,targetSum);
        return ans;
    }
};