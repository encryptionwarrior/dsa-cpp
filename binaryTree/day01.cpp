#include<iostream>
#include<queue>
using namespace std;

class Node {
    // make node l, r, d
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
    // take input data -> l, r
    int data;
    cout << "Enter the data (-1 for NULL) : ";
    cin >> data;

    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout << "Enter LEFT child of " << data << " : ";
    root->left = buildTree(root->left);

    cout << "Enter RIGHT child of " << data << " : ";
    root->right = buildTree(root->right);

    return root;

};

void levelOrderTraversal(Node* root){
    // empty case
    // create queue
    // loop queue -> front, pop 
    // temp - null - new line
    // push null - !empty

    // data, left push, right push
    if(root == NULL){
        return;
    }

    queue<Node*> Q;
    Q.push(root);
    Q.push(NULL);

    while(!Q.empty()){
        Node* temp = Q.front();
        Q.pop();

        if(temp == NULL){
            cout << endl;


            if(!Q.empty()){
                Q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if(temp->left){
                Q.push(temp->left);
            }
            if(temp->right){
                Q.push(temp->right);
            }
        }

    }

};

void inOrderTraversal(Node* root){
    // empty case
    // left traverse, print data, right traverse
    if(root == NULL){
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
};

void preOrderTraversal(Node* root){
    // empty case
    // print data, left traverse, right traverse
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
};

void postOrderTraversla(Node* root){
    // empty case
    // left tarverse, right traverse, print data
    if(root == NULL){
        return;
    }

    postOrderTraversla(root->left);
    postOrderTraversla(root->right);
    cout << root->data <<  " ";
};

Node* BuildLevelOrder(Node* root){
    // Q node
    // data input, root node data, push root queue

    // loop !q.empty
    // temp front, pop Q 
    // left node input, push left Q
    // right node input, push right Q
    queue<Node*> Q;

    int data;
    cout << "Enter root data : ";
    cin >> data;
    root = new Node(data);
    Q.push(root);

    while(!Q.empty()){
        Node* temp = Q.front();
        Q.pop();

        cout << "Enter left node of " << temp->data << " (-1 for NULL) : ";
        int leftData;
        cin >> leftData;

        if(leftData != -1){
            temp->left = new Node(leftData);
            Q.push(temp->left);
        }

        cout << "Enter right Node of " << temp->data << " (-1 for NULL) : ";

        int rightData;
        cin >> rightData;

        if(rightData != -1){
            temp->right = new Node(rightData);
            Q.push(temp->right);
        }
    }

    return root;


};




int main(){

    Node* root = NULL;

    root = BuildLevelOrder(root);

    cout << "\nLevel order Traversal : " << endl;
    levelOrderTraversal(root);

    return 0;
}