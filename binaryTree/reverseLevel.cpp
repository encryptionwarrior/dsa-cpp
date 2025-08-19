#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
    
    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
    
};

Node* buildTree(Node* root){
    int data;
    cout << "Enter the data (-1 for NULL) : ";
    cin >> data;

    if(data == -1){
        return NULL;
    }

    root = new Node(data);

    cout << "Enter LEFT child of " << data << " : ";
    root->left = buildTree(root->left);


    cout << "Enter RIGHT child of " << data << " : ";
    root->right = buildTree(root->right);

    return root;
}

void reverseLevelOrder(Node* root){
    if(root == NULL){
        return;
    }

    queue<Node*> q;
    stack<Node*> s;

    q.push(root);

    while(!q.empty()){
        Node* current = q.front();
        q.pop();

        s.push(current);

        if(current->right){
            q.push(current->right);
        }
        if(current->left){
            q.push(current->left);
        }
    }

    cout << "Reverse level order Traversal: ";
    while(!s.empty()){
        cout << s.top()->data << " ";
        s.pop();
    }

    cout << endl;

}   

int main(){
    Node* root = NULL;

    root = buildTree(root);
    cout << "\n--- Traversals ---" << endl;

    reverseLevelOrder(root);

    return 0;
}