#include <stdio.h>
#include <bits/stdc++.h>
#include <chrono>
#include <cstdlib>
#include <string.h>
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

int find_node_end(string str, int start) {
    int count = 1;
    int i = start + 5;
    while (count != 0) {
        if (str[i] == '(') {
            count++;
        }
        else if (str[i] == ')') {
            count--;
        }

        i++;
    }

    return i;
}

Node* deserialize(string str) {
    int val_start = 6;
    int chars = 0;

    for (int i = val_start; i < str.length(); i++) {
        if (str[i] == '\'') {
            chars = i - val_start;
            break;
        }
    }

    string value = str.substr(val_start, chars);

    if (str[val_start + chars + 1] == ')') {
        return new Node(value, NULL, NULL);
    }

    if (str.substr(val_start + chars + 1, 2) == ",,") {
        int node_start = val_start + chars + 4;

        int node_end = find_node_end(str, node_start);

        Node* right = deserialize(str.substr(node_start, node_end - node_start));

        return new Node(value, NULL, right);
    }

    
    int node_start = val_start + chars + 3;
    int node_end = find_node_end(str, node_start);

    Node* left = deserialize(str.substr(node_start, node_end - node_start));

    if (str.length() > node_end + 1 && str[node_end] == ',') {
        node_start = node_end + 2;
        node_end = find_node_end(str, node_start);

        Node* right = deserialize(str.substr(node_start, node_end - node_start));

        return new Node(value, left, right);
    }

    return new Node(value, left, NULL);
}

int main() {
    Node* node = new Node("root", new Node("left", new Node("left.left", NULL, NULL), NULL), new Node("right", NULL, NULL));

    cout << serialize(node) << "\n";
    cout << serialize(deserialize(serialize(node))) << "\n";
    cout << (serialize(node) == serialize(deserialize(serialize(node)))) << "\n";

    cout << "\n" << (deserialize(serialize(node))->left->left->val == "left.left") << "\n";
}
