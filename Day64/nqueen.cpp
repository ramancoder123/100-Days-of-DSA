//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void addSolution(vector<vector<int>> &ans, vector<vector<int>> &board, int n){
        vector<int> temp;
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                temp.push_back(board[i][j]);
            }
        }
        
        ans.push_back(temp);
    }

    bool isSafe(int row, int col, vector<vector<int>> &board, int n){
        int x = row;
        int y = col;
        
        // check for same Row
        while(y >= 0){
            if(board[x][y] == 1){
                return false;
            }
            y--;
        }
        
        x = row;
        y = col;
        
        // check for diagonal
        while(x >= 0 && y >= 0){
            if(board[x][y] == 1){
                return false;
            }
            y--;
            x--;
        }
        
        x = row;
        y = col;
        
        // check for diagonal
        while(x < n && y >= 0){
            if(board[x][y] == 1){
                return false;
            }
            y--;
            x++;
        }
        
        return true;
    }

    void solve(int col, vector<vector<int> > &ans, vector<vector<int> > &board, int n){
        if(col == n){
            addSolution(ans, board, n);
            return;
        }
        
        // solve one case and rest recursion
        for(int row = 0;row < n;row++){
            if(isSafe(row, col, board, n)){
                // if placing queen is safe
                board[row][col] = 1;
                solve(col+1, ans, board, n);
                board[row][col] = 0;
            }
        }    
    }
        
    vector<vector<int>> nQueen(int n) {
        vector<vector<int> > board (n, vector<int> (n, 0));
        vector<vector<int> >ans;
        
        solve(0, ans, board, n);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends