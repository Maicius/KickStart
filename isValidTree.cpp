#include<iostream>
#include<limits.h>
 //* Definition for a binary tree node.
 using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
    long last = LONG_MIN;
    bool flag = true;
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        return check(root, NULL, NULL);
    }
    bool check(TreeNode* root, int left, int right) {
        if (root == NULL) return true;
        if(left != NULL && root->val >= left) return false;
        if(right != NULL && root->val <= right) return false;
        if(!check(root->left, root->val, right)) return false;
        if(!check(root->right, left, root->val)) return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        isValidBST(root->left);
        if (root->val <= last)
            flag = false;
        last = root->val;
        if (flag) isValidBST(root->right);
        return flag;
    }
};

int main() {
    Solution *so = new Solution();
    TreeNode *node = new TreeNode(0);
    TreeNode *r = new TreeNode(1);
    node ->right = r;
    cout << so->isValidBST(node) << endl;;
}