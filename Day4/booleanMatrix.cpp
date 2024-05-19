#include <iostream>
#include <vector>
using namespace std;

// Given a boolean matrix of size RxC where each cell contains either 0 or 1, 
// modify it such that if a matrix cell matrix[i][j] is 1 then all 
// the cells in its ith row and jth column will become 1.

void booleanMatrix(vector<vector<int> > &arr)
    {
        int n = arr.size();
        int m = arr[0].size();
        
        vector<int> row(n,1);
        vector<int> col(m,1);
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(arr[i][j] == 1){
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        }
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(row[i] == 0 || col[j] == 0){
                    arr[i][j] = 1;
                }
            }
        }
    }

int main() {
    int n, m;
    cout << "Enter number of rows: ";
    cin >> n;
    cout << "Enter number of columns: ";
    cin >> m;

    vector<vector<int>> arr(n, vector<int>(m));
    cout << "Enter the matrix elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    booleanMatrix(arr);

    cout << "Modified matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
