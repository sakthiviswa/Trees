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

    

    vector<int> rec(queue<TreeNode*>q){

        vector<int> arr;

        if(q.empty()){
            return arr;
        }

        while(!q.empty()){

            int n = q.size();

            for(int i=0;i<n;i++){
                TreeNode* ele = q.front();
                q.pop();

                arr.push_back(ele->val);

                if(ele->left){
                    q.push(ele->left);
                }
                if(ele->right){
                    q.push(ele->right);
                }
            }

        }

        return arr;
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {

       

        queue<TreeNode*>q;

        if(root1)
        q.push(root1);

       vector<int> arr1 = rec(q);

       queue<TreeNode*>q1;

       if(root2)
       q1.push(root2);

       vector<int>arr2 = rec(q1);

       

       arr1.insert(arr1.end(),arr2.begin(),arr2.end());

       sort(arr1.begin(),arr1.end());

       return arr1;


        
    }
};