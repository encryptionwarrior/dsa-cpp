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

void inOrder(Node* root, vector<int>& ans){
    if(root == NULL){
        return;
    }

    inOrder(root->left, ans);
    ans.push_back(root->data);
    inOrder(root->right, ans);
}


bool checktwoSum(Node* root, int target){
    if(root == NULL){
        return false;
    }

    vector<int> arr;
    inOrder(root, arr);

    int i = 0; 
    int j = arr.size() - 1;

    while(i < j){
        int currentSum = arr[i] + arr[j];

        if(currentSum = target){
            return true;
        }

        if(currentSum > target){
            j--;
        } else {
            i++;
        }
    }

    return false;
}


int main(){

    Node* root = NULL;
    int target;

    cout << "Enter data to create BST : ";
    takeInput(root);

    cout << "Enter the target value : ";
    cin >> target;

    cout << endl << "Level Order Traversal : " << endl;
    levelOrderTraversal(root);

    bool isSumPresent = checktwoSum(root, target);

    if(isSumPresent){
        cout << "Sum pair is present in BST!" << endl;
    } else {
        cout << "Sum pair is not present in BST!" << endl;
    }

    return 0;
}