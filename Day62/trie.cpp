#include <iostream>
#include <string>
using namespace std;

class TrieNode{
    public: 
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char data){
            this -> data = data;

            for(int i = 0;i<26;i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie{
    public:
        TrieNode* root;

        Trie(){
            root = new TrieNode('\0');
        }

        void insertutil(TrieNode* root, string word){
            if(word.length() == 0){
                root -> isTerminal = true;
                return;
            }

            // excpetion: word will be capital
            int idx = word[0] - 'A';
            TrieNode* child;

            if(root -> children[idx] != NULL){
                child = root->children[idx];
            }
            else{
                child = new TrieNode(word[0]);
                root -> children[idx] = child;
            }

            // Recursion
            insertutil(child, word.substr(1));

        }

        void insertWord(string word){
            insertutil(root, word);
        }

        bool searchUtil(TrieNode* root, string word){
            if(word.length() == 0){
                return root -> isTerminal;
            }

            int idx = word[0] - 'A';
            TrieNode* child;

            if(root -> children[idx] != NULL){
                child = root -> children[idx];
            }
            else{
                return false;
            }

            return searchUtil(child, word.substr(1));
        }

        bool searchWord(string word){
            return searchUtil(root, word);
        }

        bool deleteUtil(TrieNode* root, string word, int depth = 0) {
        if (depth == word.size()) {
            if (!root->isTerminal) {
                return false;  // Word not found
            }
            root->isTerminal = false;
            return true;
        }

        int idx = word[depth] - 'A';
        TrieNode* child = root->children[idx];

        if (child == NULL) {
            return false;  // Word not found
        }

        bool shouldDeleteChild = deleteUtil(child, word, depth + 1);

        if (shouldDeleteChild) {
            delete child;
            root->children[idx] = NULL;

            if (!root->isTerminal) {
                for (int i = 0; i < 26; i++) {
                    if (root->children[i] != NULL) {
                        return false;  // Node is part of another word
                    }
                }
                return true;  // Node can be deleted
            }
        }

        return false;
    }

        void deleteWord(string word) {
            deleteUtil(root, word);
        }     
};

int main(){
    Trie *t = new Trie();

    t -> insertWord("ABCD");
    t -> insertWord("RAMAN");
    t -> insertWord("AJAy");
    t -> insertWord("OM");
    t -> insertWord("LISA");
    t -> insertWord("JISOO");
    t -> insertWord("JENNIE");
    t -> insertWord("ROSE");


    cout<< "Present or not : "<<t -> searchWord("JE")<<endl;

    t -> deleteWord("OM");
    cout<< "Present or not : "<<t -> searchWord("OM")<<endl;
    return 0;
}