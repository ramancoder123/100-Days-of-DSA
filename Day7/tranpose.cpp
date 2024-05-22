#include <iostream>
#include <vector>
using namespace std;

void transpose(vector<vector<int>>& arr, int n ,int m){
    for(int i= 0;i<n;i++){
        for(int j = i + 1;j<m;j++){
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
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

    transpose(arr, n, m);

    cout<< "Transpose : \n";
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cout<<arr[i][j]<< " ";
        }
        cout<<endl;
    }
}