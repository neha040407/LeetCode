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
    vector<int> inorder;

    void inOrderT(TreeNode* root){
        if(root == NULL){
            return;
        }

        inOrderT(root -> left);
        inorder.push_back(root -> val);
        inOrderT(root -> right);
    }
    int kthSmallest(TreeNode* root, int k) {
        inOrderT(root);

        return inorder[k-1];
    }
};