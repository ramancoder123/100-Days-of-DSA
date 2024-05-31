//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:    
    vector<int> rotation(int n)
    {
        deque<int> deck;
        for (int i = n; i >= 1; --i) {
            deck.push_front(i); // Insert card i at the front
            // Rotate the deck to the right by i positions
            for (int j = 0; j < i; ++j) {
                deck.push_front(deck.back());
                deck.pop_back();
            }
        }
        return vector<int>(deck.begin(), deck.end());
    }
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n; cin >> n;
        vector<int > ans;
        ans = obj.rotation(n);
        for(int i:ans)
            cout<< i << " ";
        cout << endl;
        
    }
    return 0;
}

// } Driver Code Ends