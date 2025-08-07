#include <iostream>
#include <stack>
#include <string>
using namespace std;

void reverseStr() {
    string str, answer;
    stack<char> s;

    cout << "Enter the String : ";
    getline(cin, str); // Will work properly if no cin >> was used before

    for (char ch : str) {
        s.push(ch);
    }

    while (!s.empty()) {
        answer.push_back(s.top());
        s.pop();
    }

    cout << "Original string : " << str << endl;
    cout << "Reversed string : " << answer << endl;
}
int main(){
    reverseStr();
    return 0;
}