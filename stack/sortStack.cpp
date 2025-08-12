#include<iostream>
#include<stack>
#include<string>
using namespace std;

void inputStack(stack<int>&st){
    int size;
    cout << "Enter the size : ";
    cin >> size;

    cout << "Enter the stack elements : ";
    for(int i = 0; i < size; i++){
        int temp;
        cin >> temp;
        st.push(temp);
    }
}

void printStack(stack<int> st){
    cout << "Stack : ";
    while(!st.empty()){
        cout << st.top() << " ";
        st.top();
    }
    cout << endl;
}

void insertSorted(stack<int> &st, int data){
    if(st.empty() || st.top() <= data){
        st.push(data);
        return;
    }

    int top = st.top();
    st.pop();

    insertSorted(st, data);

    st.push(top);
}

void sortStack(stack<int> &st){
    if(st.empty()){
        return;
    }

    int top = st.top();
    st.pop();

    sortStack(st);
    insertSorted(st, top);


}

bool redundantBracket(string str){
    stack<char> st;

    for(int i = 0; i < str.length(); i++){
        char ch = str[i];

        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        } else {
            if(ch ==')'){
                bool isReduntant = true;

                while(st.top() != '('){
                    char topElement = st.top();
                    if(topElement == '+' || topElement == '-' || topElement == '*' || topElement == '/' ){
                        isReduntant  = false;
                    }
                    st.top();
                }
                if(isReduntant == true){
                    return true;
                }
                st.top();
            }
        }
    }

    return false;
}

void checkReduntantBracket(){

    string str;

    cout << "Enter the expression: ";
    getline(cin, str);

    if(redundantBracket(str)){
        cout << "TRUE (Reduntant bracket found)" << endl;
    } else {
        cout << "FALSE (No reduntant bracket)" << endl;
    }

}

int minimumCOst(string str){
    if(str.length() % 2 != 0){
        return -1;
    }

    stack<char> st;

    for(char ch: str){
        if(ch == '{'){
            st.push(ch);
        } else {
            if(!st.empty() && st.top() == '{'){
                st.pop();
            } else {
                st.push(ch);
            }
        }
    }

    int openCount = 0;
    int closeCount = 0;

    while(!st.empty()){
        if(st.top() == '{'){
            openCount++;
        } else {
            closeCount++;
        }
        st.pop();
    }

    int ans = (openCount + 1) / 2 + (closeCount + 1)/2;
    return ans;
}

void checkMimimumCost(){
    string str;
    cout << "Enter the string : ";
    getline(cin, str);

    cout << "Required minimum cost : " << minimumCOst(str) << endl;
}

int main(){
    // stack<int> st;
    // inputStack(st);

    // cout << "Before sorting : " ;
    // printStack(st);
    // sortStack(st);

    // cout << "After sorting : ";
    // printStack(st);

    checkReduntantBracket();
    checkMimimumCost();


    return 0;
}