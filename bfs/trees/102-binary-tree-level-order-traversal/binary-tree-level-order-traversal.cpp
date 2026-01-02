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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;

        if(root == nullptr){
          return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int count = q.size();

            vector<int>arr;

            for(int i=0;i<count;i++){

                TreeNode* ele = q.front();
                q.pop();

                arr.push_back(ele->val);

                if(ele->left != nullptr){
                    q.push(ele->left);
                }

                if(ele->right != nullptr){
                    q.push(ele->right);
                }
            }

            ans.push_back(arr);
        }

        return ans;
    }
};