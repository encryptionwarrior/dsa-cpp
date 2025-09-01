#include<iostream>
#include<vector>
using namespace std;

class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

    TrieNode(char ch){
        this->data = ch;
        this->isTerminal = false;

        for(int i = 0; i < 26; i++){
            this->children[i] = NULL;
        }
    }
};


class Trie {
    public: 
        TrieNode* root;

        Trie(){
            root = new TrieNode('\0');
        }

        void insertUtils(TrieNode* root, string word){
            if(word.length() == 0){
                root->isTerminal = true;
                return;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            if(root->children[index]!= NULL){
                child = root->children[index];
            } else {
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }

            insertUtils(child, word.substr(1));
        }

        void insertNode(string word){
            insertUtils(root, word);
        }

        bool searchUtils(TrieNode* root, string word){
            if(word.length() == 0){
                return root->isTerminal;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            if(root->children[index] != NULL){
                child = root->children[index];
            } else {
                return false;
            }

            return searchUtils(child, word.substr(1));
        }

        bool search(string word){
            return searchUtils(root, word);
        }

        bool removeUtil(TrieNode* root, string word){
            if(word.length() == 0){
                if(root->isTerminal){
                    root->isTerminal = false;
                    return true;
                } else {
                    return false;
                }
            } 

            int index = word[0] - 'A';
            TrieNode* child;

            if(root->children[index] != NULL){
                child = root->children[index];
            } else {
                return false;
            }
            return removeUtil(child, word.substr(1));
        }

        bool remove(string word){
            return removeUtil(root, word);
        }

        bool eraseUtil(TrieNode* root, string word){
            if(word.length() == 0){
                if(root->isTerminal){
                    root->isTerminal = false;


                    return true;
                } else {
                    return false;
                }
            }

            int index = word[0] - 'A';
            TrieNode* child;
            

            if(root->children[index] != NULL){
                child = root->children[index];
            } else {
                return false;
            }

            bool word_deleted = eraseUtil(child, word.substr(1));

            return word_deleted;
        }

        bool erase(string word){
            return eraseUtil(root, word);
        }
};

void TrieIntro(){
    Trie* T = new Trie();

    T->insertNode("AKASH");

    bool present = T->search("AKASH");
    if(present){
        cout << "Word is Present!" << endl;
    } else {
        cout << "Word is Absent!" << endl;

    }

    T->remove("AKASH");
    present = T->search("AKSAH");

    if(present){
        cout << "Word is present!" << endl;
    } else {
        cout << "Word id Absent" << endl;
    };

    cout << "Data of first child of root: " << T->root->children[0]->data << endl;

    T->insertNode("AKASH");
    present = T->search("AKSAH");

    if(present){
        cout << "Word is present!" << endl;
    } else {
        cout << "Word id Absent" << endl;
    };
}


string longestCommonPrefix(vector<string> str){
    string ans = "";

    if(str.empty()){
        return ans;
    }

    for(int i = 0; i < str[0].length(); i++){
        char curr = str[0].at(i);

        for(int j = 1; j < str.size(); j++){
            if(i >= str[j].length() || str[j].at(i) != curr){
                return ans;
            }
        }

        ans += ans;
    }
}

void largestCommonFact(){
    vector<string> str;

    cout << "Enter the strings (enter -1 to stop) ; ";

    while(true){
        string temp;
        cin >> temp;

        if(temp == "-1"){
            break;
        }

        str.push_back(temp);
    }

    string ans = longestCommonPrefix(str);

    cout << "Longest common prefix : " << ans << endl;
}

class TrieNode2 {
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        int childCount;
    
    TrieNode2(char data){
        this->data = data;
        this->isTerminal = false;
        this->childCount = 0;

        for(int i = 0; i < 26; i++){
            this->children[i] = NULL;
        }

    }
};

class Trie2 {
    public:
        TrieNode2* root;

        Trie2(){
            root = new TrieNode2('\0');
        }
    
    void insertUtils(TrieNode2* root, string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode2* child;

        if(root->children[index] == NULL){
            child = new TrieNode2(word[0]);
            root->childCount++;
            root->children[index] = child;
        } else {
            child = root->children[index];
        }

        insertUtils(child, word.substr(1));
    }

    void insertNode(string word){
        insertUtils(root, word);
    }
};

string longestCommonPrefix(vector<string> str){
    string ans = "";

    if(str.empty()){
        return ans;
    }

    Trie2* t = new Trie2();
    for(int i = 0; i < str.size(); i++){
        t->insertNode(str[i]);
    }

    TrieNode2* temp = t->root;

    for(int i = 0; i < str[0].length(); i++){
        if(temp->childCount == 1){
            ans.push_back(str[0][i]);

            int index = str[0][i] - 'a';
            temp = temp->children[index];
        } else {
            break;
        }

        if(temp->isTerminal){
            break;
        }
    }

    return ans;
}


void largestCommonPrefixFN(){
    vector<string> str;
    cout << "Enter the strings (enter -1 to stop) : ";

    while(true){
        string temp;
        cin >> temp;

        if(temp == "-1"){
            break;
        }

        str.push_back(temp);
    }

    string ans = longestCommonPrefix(str);

    cout << "Longest common prefix : " << ans << endl;
}

void printSuggestions(TrieNode* curr, vector<string> &temp, string prefix){
    if(curr->isTerminal){
        temp.push_back(prefix);
    }

    for(char ch = 'a'; ch <= 'z'; ch++){
        TrieNode* next = curr->children[ch - 'a'];

        if(next != NULL){
            prefix.push_back(ch);
            printSuggestions(next, temp, prefix);
            prefix.pop_back();
        }
    }
}

vector<vector<string>> getSuggestions(TrieNode* root, string query){
    vector<vector<string>> answer;
    TrieNode* prev = root;
    string prefix = "";

    for(int i = 0; i < query.length(); i++){
        char lastChar = query[i];
        prefix.push_back(lastChar);

        TrieNode* curr = prev->children[lastChar - 'a'];

        if(curr == NULL){
            for(int j = i; j < query.length(); j++){
                answer.push_back({});
            }
            break;
        }

        vector<string> temp;
        printSuggestions(curr, temp, prefix);
        answer.push_back(temp);
        prev = curr;
    }

    return answer;
}

vector<vector<string>> phoneDirectory(vector<string> contactList, string query){
    Trie* T = new Trie();

    for(int i = 0; i < contactList.size(); i++){
        T->insertNode(contactList[i]);
    }

    return getSuggestions(T->root, query);
}

void phoneSuggestions(){
    vector<string> contactList;
    string query;
    vector<vector<string>> suggestions;

    string temp_input_str;
    cout << "Enter the contact strings (enter -1 to stop) : ";
    cin >> temp_input_str;
    while(temp_input_str != "-1"){
        contactList.push_back(temp_input_str);
        cin >> temp_input_str;
    }

    cout << "Enter the query string : ";
    cin >> query;

    suggestions = phoneDirectory(contactList, query);

    cout << "Suggestions : " << endl;

    for(vector<string> x : suggestions){
        if(x.empty()){
            cout << "No suggestions found." << endl;
        } else {
            for(string y : x){
                cout << y << " ";
            }
            cout << endl;
        }
    }

}

int main(){
    // TrieIntro();
    // largestCommonFact();
    // largestCommonPrefixFN();
    phoneSuggestions();
    return 0;
}