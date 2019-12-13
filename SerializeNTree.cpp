#include<vector>
#include<string>
#include<stack>
using namespace std;
/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
//前序遍历生成字符串，栈迭代生成树
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (!root) return "";
        string res = to_string(root->val);
        res += "[";
        if (root->children.size() > 0) {
            for (auto child: root->children) {
                res += serialize(child) + ",";
            }
        }
        res += "]";
        if (res.back() == ',') res.pop_back();
        return res;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        string value;
        stack<Node*> s;
        Node *head = NULL;
        for (int i = 0; i < data.size(); i++) {
            const char& c = data[i];
            if ((c >= '0' && c <= '9') || c == '+' || c == '-') {
                value += c;
            }
            else if (c == '[') {
                Node *node = new Node(stoi(value));
                if (head == NULL) {
                    head = node;
                }
                s.push(node);
                value.clear();
            }
            else if (c == ']') {
                Node *node = s.top();
                s.pop();
                if (!s.empty()) {
                    Node* prev_node = s.top();
                    prev_node->children.push_back(node);
                }
            }
        }
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));