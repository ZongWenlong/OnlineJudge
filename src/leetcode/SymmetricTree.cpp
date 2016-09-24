#include <iostream>
#include <list>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


bool isSymmetric(TreeNode* root) {
    if(root == NULL){
        return true;
    }

    list<TreeNode*> cur;
    list<TreeNode*> next;
    cur.push_front(root -> left);
    cur.push_back(root -> right);
    bool flag = true;

    while(cur.size() != 0 && next.size() != 0){
        if(cur.size() == 0){
            list<TreeNode*> temp = next;
            next = cur;
            cur = next;
        }
        TreeNode* left = cur.front();
        TreeNode* right = cur.back();
        cur.pop_front();
        cur.pop_back();

        if((left == NULL && right != NULL) || (left != NULL && right == NULL)  ){
            flag = false;
            break;
        }
        if(left != NULL && right != NULL){
            if(left -> val != right ->val){
                flag = false;
                break;
            }
            next.push_front(left -> right);
            next.push_front(left -> left);
            next.push_back(right -> left);
            next.push_back(left -> right);
        }
    }

    return flag;

}

int main(){
    TreeNode node1,node21,node22,node31,node32,node33;
    node1.val = 1;
    node21.val = 2;
    node22.val = 2;
    node31.val = 3;
    node32.val = 4;
    node33.val = 4;

    node1.left = &node21;
    node1.right = &node22;

    node21.left = &node31;
    node21.right = &node32;
    node22.left = &node33;
    node22.right = NULL;


    isSymmetric(&node1);
    return 0;
}

