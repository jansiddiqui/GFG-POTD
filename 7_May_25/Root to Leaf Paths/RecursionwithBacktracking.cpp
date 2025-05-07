#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

void collectPaths(Node *node, vector<int> &path, vector<vector<int>> &paths){
    if(node == NULL){
        return;
    }
    path.push_back(node->data);
    if(node->left == NULL && node->right == NULL){
        paths.push_back(path);
    }
    else{
        collectPaths(node->left, path, paths);
        collectPaths(node->right, path, paths);
    }
    path.pop_back();
}

vector<vector<int>> Paths(Node *root){
    vector<vector<int>> paths;
    vector<int> path;
    collectPaths(root, path, paths);
    return paths;
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<vector<int>> res = Paths(root);
    for(auto &row : res){
        for(int val : row){
            cout << val << " ";
        }
        cout<<endl;
    }
    return 0;
}