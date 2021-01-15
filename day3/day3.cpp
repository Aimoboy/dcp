#include <stdio.h>
#include <bits/stdc++.h>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace chrono;

class Node {
    public:
        string val;
        Node* left;
        Node* right;

        Node(string _val, Node* _left, Node* _right) {
            val = _val;
            left = _left;
            right = _right;
        }
};

string serialize(Node* node) {
    string str = "Node('" + node->val + "'";

    if (node->left != NULL) {
        str += ", " + serialize(node->left);
    }

    if (node->right != NULL) {
        if (node->left == NULL) {
            str += ",";
        }
        str += ", " + serialize(node->right);
    }

    str += ")";

    return str;
}

Node* deserialize(string str) {
    
}

int main() {
    Node node("test", new Node("test2", NULL, new Node("test4", NULL, NULL)), new Node("test3", NULL, NULL));

    cout << serialize(&node) << "\n";
}
