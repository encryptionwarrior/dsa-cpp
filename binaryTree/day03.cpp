#include<iostream>
#include<vector>
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

    cout << "Enter the LEFT Child of " << data << " : ";
    root->left = buildTree(root->left);


    cout << "Enter the RIGHT Child of " << data << " : ";
    root->right = buildTree(root->right);

    return root;

}


vector<int> ZigZag(Node* root){
    if(root == NULL){
        return {};
    }

    queue<Node*> Q;
    vector<int> answer;

    Q.push(root);

    bool L2R = true;

    while(!Q.empty()){
        int levelSize = Q.size();
        vector<int> currentLevelNodes(levelSize);

        for(int i = 0; i < levelSize; i++){
            Node* frontNode = Q.front();
            Q.pop();

            int index = L2R ? i : levelSize - i - 1;
            currentLevelNodes[index] = frontNode->data;

            if(frontNode->left){
                Q.push(frontNode->left);
            }

            if(frontNode->right){
                Q.push(frontNode->right);
            }

           
        }
         L2R = !L2R;

            for(int data: currentLevelNodes){
                answer.push_back(data);
            }

        }
        return answer;
}

int main(){
    Node* root = NULL;

    root = buildTree(root);

    vector<int> result = ZigZag(root);

    cout << endl << "Zigzag Traversal : ";

    for(int data: result){
        cout << data << " ";
    }

    cout << endl;

    return 0;
}