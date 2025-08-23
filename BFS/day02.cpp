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

int kthSmallest(Node* root, int &index, int k){
    if(root == NULL){
        return -1;
    }

    int leftResult = kthSmallest(root->left, index, k);

    if(leftResult != -1){
        return leftResult;
    }

    index++;

    if(index == k){
        return root->data;
    }

    return kthSmallest(root->right, index, k);

}

int kthLargest(Node* root, int &index, int k){
    if(root == NULL){
        return -1;
    }

    int rightResult = kthLargest(root->right, index, k);

    if(rightResult != -1){
        return rightResult;
    }

    index++;

    if(index == k){
        return root->data;
    }

    return kthLargest(root->left, index, k);

}

pair<int, int> predecessorSuccessor(Node* root, int key){
    int pred = -1;
    int succ = -1;

    Node* keyNode = root;

    while(keyNode != NULL && keyNode->data != key){
        if(keyNode->data > key){
            succ = keyNode->data;
            keyNode = keyNode->left;
        } else {
            pred = keyNode->data;
            keyNode = keyNode->right;
        }
    }

    if(keyNode == NULL){
        return {pred, succ};
    }

    Node* leftTree = keyNode->left;

    while(leftTree != NULL){
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    Node* rightTree = keyNode->right;

    while(rightTree != NULL){
        succ = rightTree->data;
        rightTree = rightTree->left;
    }

    return {pred, succ};
}

int main(){

    Node* root = NULL;

    cout << "Enter data to create BSt (use -1 for NULL, this function builds a BST by default if BST.h is from previous example): ";

    takeInput(root);

    // cout << endl << "Level order Traversal of the created tree : " << endl;
    

    // levelOrderTraversal(root);

    // if(ValidateBST(root, INT_MIN, INT_MAX)){
    //     cout << "YES ! It is a Binary search tree." << endl;
    // } else { 
    //     cout << "NO ! It is not a binary search tree." << endl;
    // }


    // int k, ans;

    // cout << "Enter the value of K (eg: 1, for smallest, 2 for second smallest): ";

    // cin >> k;

    // cout << endl << "Level order Traversal of the created tree : " << endl;

    // levelOrderTraversal(root);

    // int index = 0;

    // // ans = kthSmallest(root, index, k);
    // ans = kthLargest(root, index, k);

    // if(ans != -1){
    //     cout << endl << "The " << k << "th smallest element is = " << ans << endl;
    // } else { 
    //     cout << "Could not find the " << k << "th smalles element(K might be too large or tree empty) " << endl;
    // }
    // if(ans != -1){
    //     cout << endl << "The " << k << "th largest element is = " << ans << endl;
    // } else { 
    //     cout << "Could not find the " << k << "th largest element(K might be too large or tree empty) " << endl;
    // }

    int key;

    cout << "Enter the value of key element : ";
    cin >> key;

    cout << endl;

    cout << endl << "Level Order Traversal : " << endl;
    levelOrderTraversal(root);

    pair<int, int> ans = predecessorSuccessor(root, key);

    cout << "Predecessor : " << ans.first << endl;
    cout << "Successor : " << ans.second << endl;


    return 0;
}