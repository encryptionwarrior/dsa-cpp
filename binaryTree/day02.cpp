#include<iostream>
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

int getHeight(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    int answer = max(leftHeight, rightHeight) + 1;
    return answer;
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

int getDiameter(Node* root){
    if(root == NULL){
        return 0;
    }

    int d1 = getDiameter(root->left);
    int d2 = getDiameter(root->right);

    int d3 = getHeight(root->left) + getHeight(root->right) + 1;

    return max(d1, max(d2, d3));
}

pair<int, int> getDiameterOptimized(Node* root){
    if(root == NULL){
        return {0, 0};
    }

    pair<int, int> leftResult = getDiameterOptimized(root->left);
    pair<int, int> rightResult = getDiameterOptimized(root->right);

    pair<int, int> ans;

    ans.second = max(leftResult.second, rightResult.second) + 1;

    int opt1 = leftResult.first;
    int opt2 = rightResult.first;

    int opt3 = leftResult.second + rightResult.second + 1;

    ans.first = max(opt1, max(opt2, opt3));

    return ans;
}


bool isBalanced(Node* root){
    if(root == NULL){
        return true;
    }

    bool isLeftBalanced = isBalanced(root->left);
    bool isRightBalanced = isBalanced(root->right);

    bool heightDifferenceCheck = abs(getHeight(root->left) - getHeight(root->right)) <= 1;

    return isLeftBalanced && isRightBalanced && heightDifferenceCheck;
}


pair<bool, int> isBalancedOptimized(Node* root){
    if(root == NULL){
        return {true, 0};
    }

    pair<bool, int> leftResult = isBalancedOptimized(root->left);
    pair<bool, int> rightResult = isBalancedOptimized(root->right);

    bool isLeftBalanced = leftResult.first;
    bool isRightResult = rightResult.first;

    bool heightDifferencecheck = abs(leftResult.second - rightResult.second) <= 1;

    pair<bool, int> ans;

    ans.first = isLeftBalanced && isRightResult && heightDifferencecheck;
    ans.second = max(leftResult.second, rightResult.second)+1;

    return ans;
}

 bool isIdentical(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }

    if(root1 == NULL || root2 == NULL){
        return false;
    }

    bool isLeftIdentical = isIdentical(root1->left, root2->left);
    bool isRightIdentical = isIdentical(root1->right, root2->right);

    bool areValueSame = (root1->data == root2->data);


    return isLeftIdentical && isRightIdentical && areValueSame;

 }

 pair<bool, int> isSumTree(Node* root){
    if(root == NULL){
        return {true, 0};
    }

    if(root->left == NULL && root->right == NULL){
        return {true, root->data};
    }

    pair<bool, int> LeftResult = isSumTree(root->left);
    pair<bool, int> RightResult = isSumTree(root->right);

    bool isLeftSumTree = LeftResult.first;
    bool isRightSumTree = RightResult.first;

    bool currentValueSatisfiesSum =( root->data == (LeftResult.second + RightResult.second));

    pair<bool, int> ans;

    ans.first = (isLeftSumTree && isRightSumTree && currentValueSatisfiesSum);

    ans.second = root->data + LeftResult.second + RightResult.second;

    return ans;
 }


int main(){
    Node* root = NULL;
    root = buildTree(root);

    // int height = getHeight(root);

    // cout << "Height / Depth of the tree is : " << height << endl;

    // pair<int, int> DiameterResult = getDiameterOptimized(root);

    // cout << endl << "Diameter of the tree is : " << DiameterResult.first << endl;

    // bool check = isBalanced(root);
    // bool checkOptimized = isBalancedOptimized(root).first;
    
    // if(checkOptimized){
    //     cout << endl << "Balanced Tree!" << endl;
    // } else {
    //     cout << endl << "Not a balanced Tree!" << endl;
    // }

//     Node* root1 = NULL;
//     Node* root2 = NULL;

//     cout << "-- Buld Tree 1--" << endl;

//     root1 = buildTree(root1);
//     cout << "\n-- Buld Tree 1--" << endl;

//     root1 = buildTree(root2);

//     bool check = isIdentical(root1, root2);

//   if(check){
//         cout << endl << "Identical Tree!" << endl;
//     } else {
//         cout << endl << "Non-Identical Tree!" << endl;
//     }
    bool check = isSumTree(root).first;

  if(check){
        cout << endl << "Sum Tree!" << endl;
    } else {
        cout << endl << "Non-Sum Tree!" << endl;
    }
    
    return 0;
}