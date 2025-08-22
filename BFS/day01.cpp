#include<iostream>
#include<queue>
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
                return Q.push(NULL);
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

void preOrderRecursive(Node* root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    preOrderRecursive(root->left);
    preOrderRecursive(root->right);
}
void inOrderRecursive(Node* root){
    if(root == NULL){
        return;
    }

    inOrderRecursive(root->left);
    cout << root->data << " ";
    inOrderRecursive(root->right);
}
void postOrderRecursive(Node* root){
    if(root == NULL){
        return;
    }

    postOrderRecursive(root->left);
    postOrderRecursive(root->right);
    cout << root->data << " ";
}


bool searchBST(Node* root, int key){
    if(root == NULL){
        return false;
    }

    if(root->data == key){
        return true;
    }

    if(root->data > key){
        return searchBST(root->right, key);
    } else {
        return searchBST(root->left, key);
    }
}


int main(){

    Node* root = NULL;

    cout << "--- Creating Binary Search Tree ---" << endl;
    takeInput(root);
    cout << endl;

    // cout << endl << "Level order Traversal of BST: " << endl;
    // levelOrderTraversal(root);
    // cout << endl << "In order Traversal : " << endl;
    // inOrderRecursive(root);


    // cout << endl << "pre order Traversal : " << endl;
    // preOrderRecursive(root);


    // cout << endl << "post order Traversal : " << endl;
    // postOrderRecursive(root);

    int key;

    cout << "Enter the key to search: ";
    cin >> key;

    bool found = searchBST(root, key);

    if(found){
        cout << "Key " << key << " is present in BST!" << endl;
    } else {
        cout << "Key " << key << " is absent in BST!" << endl;
    }
    

    cout << endl;

    return 0;
}