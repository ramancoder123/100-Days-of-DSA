//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
private:
    int findMaxPathSum(Node* root, int &mx, Node* curr){
        if(root == NULL){
            return 0;
        }
        if(root -> left == NULL && root -> right == NULL){
            return root -> data;
        }
        
        int l = findMaxPathSum(root -> left, mx ,curr);
        if(root -> left != NULL && root -> right == NULL){
            if(root == curr){
                mx = max(mx, root -> data + l);
            }
            return root -> data + l;
        }
        
        int r = findMaxPathSum(root -> right, mx, curr);
        if(root -> left == NULL && root -> right != NULL){
            if(root == curr){
                mx = max(mx, root -> data + r);
            }
            return root -> data + r;
        }
        
        mx = max(root -> data + l + r, mx);
        return max(root -> data + l, root -> data + r);
    }
public:
    int maxPathSum(Node* root){
        int mx = INT_MIN;
        Node* curr = root;
        findMaxPathSum(root, mx, curr);
        return mx;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution ob;
        cout << ob.maxPathSum(root) << "\n";
    }
    return 0;
}
// } Driver Code Ends