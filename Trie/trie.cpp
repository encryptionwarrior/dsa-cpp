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



int main(){
    // TrieIntro();
    largestCommonFact();
    return 0;
}