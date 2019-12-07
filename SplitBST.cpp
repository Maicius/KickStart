#include<iostream>
#include<vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    /* data */
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        vector<TreeNode*> splitBST(TreeNode *root, int V) {
        //initialization
        vector<TreeNode*> splitted;
        splitted.push_back(NULL);
        splitted.push_back(NULL);
        //corner case
        if (!root) return splitted;
        //discuss 2 cases
        if (root->val > V) {
            splitted = splitBST(root->left, V);
            root->left = splitted[1];
            splitted[1] = root;
        } else {
            splitted = splitBST(root->right, V);
            root->right = splitted[0];
            splitted[0] = root;
        }
        //return
        return splitted;
    }
};

int main(){
    TreeNode *root = new TreeNode(4);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node6 = new TreeNode(6);
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node7 = new TreeNode(7);
        
    root->left = node2;
    root->right = node6;
    node2->left = node1;
    node2->right = node3;
    node6->left = node5;
    node6->right = node7;
    Solution *so = new Solution();
    vector<TreeNode*> res = so->splitBST(root, 2);
    for(auto c: res){
        if(c) {
            while(c) {
                printf("%d\n", c->val);
                c = c->left;
            }
            
        }
    }
}
