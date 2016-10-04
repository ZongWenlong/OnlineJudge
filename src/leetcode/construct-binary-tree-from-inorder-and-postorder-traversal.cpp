/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        if(n > 0){
            stack<TreeNode*> curs;
            TreeNode* root = new TreeNode(postorder[n - 1]);
            curs.push(root);
            TreeNode* parent = NULL;
            int inorderIndex = n - 1;
            for(int i = n - 2;i >= 0;){
                if(!curs.empty() && curs.top() -> val == inorder[inorderIndex]){
                    parent = curs.top();
                    curs.pop();
                    inorderIndex--;
                }
                else if(parent){
                    TreeNode* newNode = new TreeNode(postorder[i]);
                    parent -> left = newNode;
                    curs.push(newNode);
                    parent = NULL;
                    i--;
                }
                else{
                    TreeNode* newNode = new TreeNode(postorder[i]);
                    curs.top() -> right = newNode;
                    curs.push(newNode);
                    parent = NULL;
                    i--;
                }
            }
            return root;
        }
        else{
            return NULL;
        }
    }
};