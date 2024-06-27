//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
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
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution{
    public:
    
    vector<int> singleTree(Node* root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        
        vector<int> leftAns = singleTree(root->left);
        ans.insert(ans.end(), leftAns.begin(), leftAns.end());
        
        ans.push_back(root->data);
        
        vector<int> rightAns = singleTree(root->right);
        ans.insert(ans.end(), rightAns.begin(), rightAns.end());
        
        return ans;
    }
    vector<int> merge(Node *root1, Node *root2){
        vector<int> ans;
        if(root1 == NULL && root2 == NULL){
            return ans;
        }
        
        if(root1 != NULL && root2 == NULL){
            vector<int> rootAns = singleTree(root1);
            return rootAns;
        }
        
        if(root2 != NULL && root1 == NULL){
            vector<int> rootAns = singleTree(root2);
            return rootAns;
        }
        
        vector<int> tree1 = singleTree(root1);
        vector<int> tree2 = singleTree(root2);
        
        int i = 0, j = 0;
        int n = tree1.size();
        int m = tree2.size();
        
        while(i < n && j < m){
            if(tree1[i] < tree2[j]){
                ans.push_back(tree1[i]);
                i++;
            }
            
            else if(tree1[i] > tree2[j]){
                ans.push_back(tree2[j]);
                j++;
            }
            else if(tree1[i] == tree2[j]){
                ans.push_back(tree1[i]);
                ans.push_back(tree2[j]);
                j++;
                i++;
            }
        }
        
        while(i < n){
            ans.push_back(tree1[i]);
            i++;
        }
        
        while(j < m){
            ans.push_back(tree2[j]);
            j++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);
       Solution obj;
       vector<int> vec = obj.merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends