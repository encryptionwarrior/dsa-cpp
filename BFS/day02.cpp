#include<iostream>
#include<queue>
#include<limits.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
    
        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* insertIntoBST(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data > root->data){
        root->right = insertIntoBST(root->right, data);
    } else {
        root->left = insertIntoBST(root->left, data);
    }

    return root;

}

void takeInput(Node* &root){
    int data;
    cout << "Enter data for node (enter -1 to stop): ";
    cin >> data;

    while(data != -1){
        root = insertIntoBST(root, data);
        cout << "Enter data for node (enter -1 to stop): ";
        cin >> data;
    }
}

void levelOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }

    queue<Node*> Q;
    Q.push(root);
    Q.push(NULL);

    while(!Q.empty()){
        Node* FrontNode = Q.front();
        Q.pop();

        if(FrontNode == NULL){
            cout << endl;

            if(!Q.empty()){
                Q.push(NULL);
            }
        } else {
            cout << FrontNode->data << " ";
            

            if(FrontNode->left){
                Q.push(FrontNode->left);
            }

            if(FrontNode->right){
                Q.push(FrontNode->right);
            }
        }
    }

}

bool ValidateBST(Node* root, int min, int max){
    if(root == NULL){
        return true;
    }

    if(root->data >= min && root->data <= max){
        bool LeftValid = ValidateBST(root->left, min, root->data);
        bool RightValid = ValidateBST(root->right, root->data, max);

        return (LeftValid && RightValid);

    }

    return false;
}

int main(){

    Node* root = NULL;

    cout << "Enter data to create BSt (use -1 for NULL, this function builds a BST by default if BST.h is from previous example): ";

    takeInput(root);

    cout << endl << "Level order Traversal of the created tree : " << endl;
    

    levelOrderTraversal(root);

    if(ValidateBST(root, INT_MIN, INT_MAX)){
        cout << "YES ! It is a Binary search tree." << endl;
    } else { 
        cout << "NO ! It is not a binary search tree." << endl;
    }

    return 0;
}