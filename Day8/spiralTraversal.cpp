#include <iostream>
#include <vector>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int> > arr, int r, int c) {
    vector<int> ans;
    int row = 0, col = 0, k;
        
    while(row < r && col < c){
        // Traversals : 
        for(k = col;k < c;k++){
            ans.push_back(arr[row][k]);
        }
        row++;
        
        for(k = row;k<r;k++){
            ans.push_back(arr[k][c-1]);
        }
        c--;
            
        if(row == r || col == c){
            break;
        }
            
        for(k = c-1;k >= col;k--){
            ans.push_back(arr[r-1][k]);
        }
        r--;
            
        for(k = r-1;k >= row;k--){
            ans.push_back(arr[k][col]);
        }
        col++;
    }    
    return ans;
}

int main(){
    int r;
    cout<< "Enter row number : ";
    cin>>r;

    int c;
    cout<< "Enter columns number : ";
    cin>>c;

    vector<vector<int> > arr(r, vector<int> (c, 0));
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cin>>arr[i][j];
        }
    }

    vector<int> ans = spirallyTraverse(arr, r, c);

    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<< " ";
    }

    return 0;
}