#include<iostream>
#include<vector>
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

void flattenBST(Node* root, Node* &head){
    if(root == NULL){
        return;
    }

    flattenBST(root->right, head);

    root->right = head;

    if(head != NULL){
        head->left = root;
    }

    head = root;

    flattenBST(root->left, head);
}

Node* mergeLinkedhead(Node* head1, Node* head2){
    Node* head = NULL;
    Node* tail = NULL;

    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            if(head == NULL){
                head = tail = head1;
            } else {
                tail->right = head1;
                tail->left = tail;
                tail = head1;
            }
            head1 = head1->right;
        } else {
            if(head == NULL){
                head = tail = head2;
            } else {
                tail->right = head2;
                tail->left = tail;
                tail = head2;
            }
            head2 = head2->right;
        }
    }

    while(head1 != NULL){
        tail->right = head1;
        tail->left = tail;
        tail = head;
        head1 = head1->right;
    }

    while(head2 != NULL){
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

int countNodes(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

Node* LL_2_BST(Node* &head, int n){
    if(n <= 0 || head == NULL){
        return NULL;
    }

    Node* leftChild = LL_2_BST(head, n/2);

    Node* root = head;
    root->left = leftChild;

    head = head->right;

    root->right = LL_2_BST(head, n - n/2 - 1);

    return root;
}


Node* MergeBST2(Node* root1, Node* root2){
    Node* head1 = NULL;
    Node* head2 = NULL;

    flattenBST(root1, head1);
    flattenBST(root2, head2);

    if(head1 != NULL) head1->left = NULL;
    if(head1 != NULL) head2->left = NULL;

    Node* mergeListHead = mergeLinkedhead(head1, head2);

    int totalNodes = countNodes(mergeListHead);

    Node* result = LL_2_BST(mergeListHead, totalNodes);

    return result;
}

class Info{
    public:
        int maxi;
        int mini;
        int isBST;
        int size;

        Info(){
            this->maxi = INT_MIN;
            this->mini = INT_MAX;
            this->isBST = true;
            this->size = 0;
        }
        Info(int min, int max, bool isBST, int size){
            this->maxi = max;
            this->mini = min;
            this->isBST = isBST;
            this->size = size;
        }
};

Info* MaxBST(Node* root, int &answer){
    if(root == NULL){
        Info* temp = new Info();
        return temp;
    }

    Info* left = MaxBST(root->left, answer);
    Info* right = MaxBST(root->right, answer);

    Info* currNode = new Info();

    currNode->size = left->size + right->size + 1;
    currNode->maxi = max(root->data, right->maxi);
    currNode->mini = max(root->data, right->mini);

    if(left->isBST && right->isBST && (root->data > left->maxi) && (root->data < right->mini)){
        currNode->isBST = true;
    } else {
        currNode->isBST = false;
    }

    if(currNode->isBST){
        answer = max(answer, currNode->size);
    }

    return currNode;

}

Node* buildTree(Node* root){
    int data;
    cout << "Enter the data (-1 for NULL) : ";
    cin >> data;

    if(data == -1){
        return NULL;
    }

    root = new Node(data);

    cout << "Enter the LEFT Child of " << data << " : ";
    root->left = buildTree(root->left);


    cout << "Enter the RIGHT Child of " << data << " : ";
    root->right = buildTree(root->right);

    return root;

}



int main(){

    // Node* root1 = NULL;
    // Node* root2 = NULL;

    // cout << "Enter data to create BST 1 (e.g. 50, 40, 60 , 70, -1) : ";
    // takeInput(root1);
    // cout << "Enter data to create BST 1 (e.g. 55, 45, 35 , 65, 47, -1) : ";
    // takeInput(root2);

    // cout << endl << "Level order Traversal of BST 1 : "<< endl;
    // levelOrderTraversal(root1);

    // cout << endl << "Level order Traversal of BST 2 : "<< endl;
    // levelOrderTraversal(root2);

    // Node* result = MergeBST(root1, root2);

    // cout << "Level order Traversal of final merged BST (from main) : " << endl;
    // levelOrderTraversal(result);
    // Node* result = MergeBST2(root1, root2);

    // cout << "Level order Traversal of final merged BST (from main) : " << endl;
    // levelOrderTraversal(result);

    Node* root = NULL;
    cout << "Enter data to create a tree (use -1 for NULL children) : ";

    root = buildTree(root);


    int answer = 0;

    Info* solve = MaxBST(root, answer);

    cout << endl << "Size of the largest BST in the given Binary Tree : " << answer << endl;



    return 0;
}