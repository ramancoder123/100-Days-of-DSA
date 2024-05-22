#include <iostream>
#include <vector>
using namespace std;

vector<int> boundary(vector<vector<int> >&arr, int n, int m){
    vector<int> ans;
    
    for(int i = 0;i<n;i++){
        ans.push_back(arr[0][i]);
    }
    for(int i = 1;i<n;i++){
        ans.push_back(arr[i][m-1]);
    }
    for(int i = m - 2;i >= 0 && n > 1;i--){
        ans.push_back(arr[n-1][i]);
    }
    for(int i = n-2;i >= 1 && m > 1;i--){
        ans.push_back(arr[i][0]);
    }
    return ans;
}

int main(){
    int n;
    cout<< "Enter rows number : ";
    cin>>n;

    int m;
    cout<< "Enter columns number : ";
    cin>>m;

    vector<vector<int> > arr(n, vector<int> (m, 0));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    vector<int> ans = boundary(arr, n, m);
    cout<< "Boundary Traversal : ";
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<  " ";
    }
    
}