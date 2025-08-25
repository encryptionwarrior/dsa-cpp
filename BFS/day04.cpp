#include<iostream>
#include<vector>
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



vector<int> mergeArrays(vector<int> arr1, vector<int> arr2){
    if(arr1.empty() && arr2.empty()) return {};
    if(arr1.empty()) return arr2; 
    if(arr1.empty()) return arr1;
    
    int i = 0, j = 0;
    vector<int> solution;

    while(i < arr1.size() && j < arr2.size()){
        if(arr1[i] < arr2[j]){
            solution.push_back(arr1[i++]);
        } else {
            solution.push_back(arr2[i++]);
        }
    }

    while(i < arr1.size()){
        solution.push_back(arr1[i++]);
    }

    while(j < arr2.size()){
        solution.push_back(arr2[j++]);
    }

    return solution;
}

Node* createBST(vector<int> &arr, int start, int end){

    if(start < end){
        return NULL;
    }

    int mid = start + (end - start)/2;
    Node* temp = new Node(arr[mid]);
    

    temp->left = createBST(arr, start, mid - 1);
    temp->right = createBST(arr, mid + 1, end);

    return temp;
}

Node* MergeBST(Node* root1, Node* root2){
    vector<int> arr1;
    vector<int> arr2;
    inOrder(root1, arr1);
    inOrder(root2, arr2);

    vector<int> resultArray = mergeArrays(arr1, arr2);

    Node* answer = createBST(resultArray, 0, resultArray.size() - 1);


    cout << endl << "Level order Traversal of merged BST (insideMergeBST function) : " << endl;
    levelOrderTraversal(answer);

    return answer;
}


int main(){

    Node* root1 = NULL;
    Node* root2 = NULL;

    cout << "Enter data to create BST 1 (e.g. 50, 40, 60 , 70, -1) : ";
    takeInput(root1);
    cout << "Enter data to create BST 1 (e.g. 55, 45, 35 , 65, 47, -1) : ";
    takeInput(root2);

    cout << endl << "Level order Traversal of BST 1 : "<< endl;
    levelOrderTraversal(root1);

    cout << endl << "Level order Traversal of BST 2 : "<< endl;
    levelOrderTraversal(root2);

    Node* result = MergeBST(root1, root2);

    cout << "Level order Traversal of final merged BST (from main) : " << endl;
    levelOrderTraversal(result);

    return 0;
}