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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;
        TreeNode* curr;
        int s;

        if(root == NULL){
            return ans;
        }

        q.push(root);

        while(!q.empty()){

            s = q.size();

            for(int i = 0 ; i < s ; i++){
                curr = q.front();
                q.pop();

                if(i == 0){
                    ans.push_back(curr -> val);
                }

                if(curr -> right != NULL){
                    q.push(curr -> right);
                }

                if(curr -> left != NULL){
                    q.push(curr -> left);
                }
            }
        }

        return ans;
    }
};