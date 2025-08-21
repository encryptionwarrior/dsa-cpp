#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

void traverseLeft(Node* root, vector<int> &answer){
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        return;
    }

    answer.push_back(root->data);
    
    if(root->left){
        traverseLeft(root->left, answer);
    } else {
        traverseLeft(root->right, answer);
    }
}

void traverseLeaf(Node* root, vector<int> &answer){
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        answer.push_back(root->data);
        return;
    }

    traverseLeaf(root->left, answer);
    traverseLeaf(root->right, answer);
}

void traverseRight(Node* root, vector<int> & answer){
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        return;
    }

    if(root->right){
        traverseRight(root->right, answer);
    } else {
        traverseRight(root->left, answer);

    }

    answer.push_back(root->data);
}

vector<int> Boundary(Node* root){
    if(root == NULL){
        return {};
    }

    vector<int> answer;

    answer.push_back(root->data);
    
    traverseLeft(root->left, answer);
    traverseLeaf(root->left, answer);
    traverseLeaf(root->right, answer);
    traverseRight(root->right, answer);

    return answer;
}


vector<int> VerticalOrder(Node* root){
    if(root == NULL){
        return {};
    }

    vector<int> answer;

    map<int, map<int, vector<int>>> NodeMap;

    queue<pair<Node*, pair<int, int>>> Q;

    Q.push(make_pair(root, make_pair(0, 0)));

    while(!Q.empty()){
        pair<Node*, pair<int, int>> temp = Q.front();
        Q.pop();

        Node* FrontNode = temp.first;
        int HorizDist = temp.second.first;
        int Lvl = temp.second.second;

        NodeMap[HorizDist][Lvl].push_back(FrontNode->data);

        if(FrontNode->left){
            Q.push(make_pair(FrontNode->left, make_pair(HorizDist+1, Lvl+1)));
        }
    }

    for(auto const& hd_entry: NodeMap){
        for(auto const& level_entry: hd_entry.second){
            for(int node_data: level_entry.second){
                answer.push_back(node_data);
            }
        }
    }

    return answer;

}

void TraverseLeft(Node* root, vector<int>& answer){
    if(root == NULL){
        return;
    }

    TraverseLeft(root->left, answer);
    answer.push_back(root->data);
}
void TraverseRight(Node* root, vector<int>& answer){
    if(root == NULL){
        return;
    }

    answer.push_back(root->data);
    TraverseRight(root->right, answer);
}

vector<int> TopView(Node* root){
    if(root == NULL){
        return {};
    }

    vector<int> answer;

    TraverseLeft(root->left, answer);
    answer.push_back(root->data);
    TraverseRight(root->right, answer);

    return answer;
}

vector<int> TopView2(Node* root){
    if(root == NULL){
        return {};
    }

    vector<int> answer;

    map<int, int> TopNode;

    queue<pair<Node*, int>> Q;

    Q.push(make_pair(root, 0));

    while(!Q.empty()){
        pair<Node*, int> temp = Q.front();
        Q.pop();

        Node* FrontNode = temp.first;
        int HorizDist = temp.second;

        if(TopNode.find(HorizDist) == TopNode.end()){
            TopNode[HorizDist] = FrontNode->data;
        }

        if(FrontNode->left){
            Q.push(make_pair(FrontNode->left, HorizDist - 1));
        }
        if(FrontNode->right){
            Q.push(make_pair(FrontNode->right, HorizDist + 1));
        }
    }

    for(auto const& entry: TopNode){
        answer.push_back(entry.second);
    }

    return answer;

}

vector<int> BottomView(Node* root){
    if(root == NULL){
        return {};
    }

    vector<int> answer;

    map<int, int> BottomNode;

    queue<pair<Node*, int>> Q;

    Q.push(make_pair(root, 0));

    while(!Q.empty()){
        pair<Node*, int> temp = Q.front();
        Q.pop();

        Node* FrontNode = temp.first;
        int HorizDist = temp.second;

        BottomNode[HorizDist] = FrontNode->data;

        if(FrontNode->left){
            Q.push(make_pair(FrontNode->left, HorizDist - 1));
        }
        if(FrontNode->right){
            Q.push(make_pair(FrontNode->right, HorizDist + 1));
        }
    }

    for(auto const& entry: BottomNode){
        answer.push_back(entry.second);
    }

    return answer;
}

void LeftView(Node* root, vector<int>& answer, int lvl){
    if(root == NULL){
        return;
    }

    if(lvl == answer.size()){
        answer.push_back(root->data);
    }

    LeftView(root->left, answer, lvl+1);
    LeftView(root->right, answer, lvl+1);
}


void RightView(Node* root, vector<int>& answer, int lvl){
    if(root == NULL){
        return;
    }

    if(lvl == answer.size()){
        answer.push_back(root->data);
    }

    RightView(root->right, answer, lvl+1);
    RightView(root->left, answer, lvl+1);
}

int main(){
    Node* root = NULL;

    root = buildTree(root);

    // vector<int> result = ZigZag(root);

    // cout << endl << "Zigzag Traversal : ";

    // for(int data: result){
    //     cout << data << " ";
    // }

    // cout << endl;
    // vector<int> result = Boundary(root);

    // cout << endl << "Boundary Traversal : ";

    // for(int data: result){
    //     cout << data << " ";
    // }

    // cout << endl;
    // vector<int> result = VerticalOrder(root);

    // cout << endl << "Vertical Order Traversal : ";

    // for(int data: result){
    //     cout << data << " ";
    // }

    // cout << endl;
    // vector<int> result = TopView(root);
    // vector<int> result = TopView2(root);

    // cout << endl << "Top View : ";

    // for(int data: result){
    //     cout << data << " ";
    // }

    // cout << endl;
    // vector<int> result = BottomView(root);

    // cout << endl << "Bottom View : ";

    // for(int data: result){
    //     cout << data << " ";
    // }

    // cout << endl;
    // vector<int> answer;
    //  LeftView(root, answer, 0);

    // cout << endl << "Left View : ";

    // for(int data: answer){
    //     cout << data << " ";
    // }

    // cout << endl;
    vector<int> answer;
     RightView(root, answer, 0);

    cout << endl << "Right View : ";

    for(int data: answer){
        cout << data << " ";
    }

    cout << endl;

    return 0;
}