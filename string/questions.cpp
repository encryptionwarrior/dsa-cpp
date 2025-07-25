#include<iostream>
using namespace std;

char toLowerCase(char ch){
        if(ch >= 'a' && ch <= 'z'){
            return ch;
        } else {
            char temp = ch - 'A' + 'a';
            return temp;
        }
}

char getLength(char ch[]){
    int count = 0;
    for(int i = 0; ch[i] != '\0'; i++){
        count++;
    }
    return count;

}

void reverseStr(char name[], int n){
    int s = 0;
    int e = n - 1;
    while(s < e){
        swap(name[s++], name[e--]);
    }
}

bool checkPalindrome(char ch[], int n){
    int s = 0;
    int e = n-1;
    while(s <= e){
        if(toLowerCase(ch[s]) != toLowerCase(ch[e])){
            return 0;
        } else {
            s++;
            e--;
        }
    }
    return 1;
}

char getMaxOccCharacters(string s){
    int arr[26] = {0};
    for(int i = 0; i < s.length(); i++){
        char ch = s[i];
        int num = ch - 'a';
        arr[num]++;
    }

    int maxi = -1;
    int ans = 0;
    for(int i = 0 ; i < 26; i++){
        if(maxi < arr[i]){
            ans = i;
            maxi = arr[i];
        }
    }

    return 'a' + ans;
}

int main(){
    char ch = 'P';
    char lowerCh = toLowerCase(ch);
    cout << "lowercase of P is => " << lowerCh << endl;

    char chars[] = "Hello";
    int charcount = getLength(chars);
    cout << "Here is char length => " << charcount << endl;

    reverseStr(chars, 5);
    cout << "reverse str => " << chars << endl;

    char testChar[] = "Madam";
    bool ispalindrome = checkPalindrome(testChar, 5);

    cout << "Is Madam palindrome => " << ispalindrome << endl;

    string s = "character";
    char result = getMaxOccCharacters(s);
    cout << "Max occurance in character is => " << result << endl;

    return 0;
}