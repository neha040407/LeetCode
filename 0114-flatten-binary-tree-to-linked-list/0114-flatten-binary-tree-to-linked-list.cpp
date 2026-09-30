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
    void flatten(TreeNode* root) {

        TreeNode *temp, *temp2;

        if(root == NULL || (root -> left == NULL && root -> right == NULL)){
            return;
        }

        flatten(root -> right);
        flatten(root -> left);

        temp2 = root -> left;
        if(temp2 == NULL){
            return;
        }
        temp = root -> right;
        root -> right = temp2;
        root -> left = NULL;

        while(temp2 -> right != NULL){
            temp2 = temp2 -> right;
        }

        temp2 -> right = temp;
    }
};