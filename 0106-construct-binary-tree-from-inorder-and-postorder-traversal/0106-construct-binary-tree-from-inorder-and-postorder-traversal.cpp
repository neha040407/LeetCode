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
    int postindex;
    unordered_map<int,int> mp;

    TreeNode* build(vector<int>& postorder , int instart , int inend){
        if(instart > inend){
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[postindex]);

        int i = mp[postorder[postindex]];
        postindex--;

        root -> right = build(postorder , i+1 , inend);
        root -> left = build(postorder , instart , i-1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        postindex = n-1;

        for(int i = 0 ; i < n ; i++){
            mp[inorder[i]] = i;
        }

        TreeNode* root = build(postorder , 0 , n-1);

        return root;
    }
};