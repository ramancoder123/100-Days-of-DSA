#include <iostream>
#include <vector>
using namespace std;

vector<int> snakePattern(vector<vector<int> >& arr){
    vector<int> ans;
        int n = arr.size();
        
        bool flag = false;
        
        for(int i = 0;i<n;i++){
            if(!flag){
                for(int j = 0;j<n;j++){
                    ans.push_back(arr[i][j]);
                }
                flag = !flag;
            }
            else{
                for(int j = n-1;j>=0;j--){
                    ans.push_back(arr[i][j]);
                }
                flag = !flag;
            }
        }
        return ans;
}

int main(){
    int n;
    cout << "Enter the size of the square matrix: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    vector<int> ans = snakePattern(matrix);
    int x = ans.size();
    for(int i = 0;i<x;i++){
        cout<<ans[i]<< " ";
    }

    return 0;
}