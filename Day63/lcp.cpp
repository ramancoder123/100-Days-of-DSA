//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class TrieNode {
public: 
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie {
public:     
    TrieNode* root;

    Trie(char data) {
        root = new TrieNode(data);
    }

    void insertUtil(TrieNode* root, const std::string& word) {
        if(word.length() == 0) {
            root->isTerminal = true; // Marking the end of a valid word
            return;
        }

        int idx = word[0] - 'a';
        TrieNode* child;

        if(root->children[idx] != NULL) {
            child = root->children[idx];
        } else {
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[idx] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(const std::string& word) {
        insertUtil(root, word);
    }

    void lcp(TrieNode* node, const std::string& str, std::string& ans) {
        for(int i = 0; i < str.length(); i++) {
            char ch = str[i];
            
            if(node->childCount == 1) {
                ans.push_back(ch);
                
                int idx = ch - 'a';
                node = node->children[idx];
            } else {
                break;
            }
            
            if(node->isTerminal) {
                break;
            }
        }
    }

};  

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        int n = arr.size();
        Trie *t = new Trie('\0');
        
        for(int i = 0; i < n; i++) {
            t->insertWord(arr[i]);
        }
        
        string first = arr[0];
        string ans = "";
        
        t->lcp(t->root, first, ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends