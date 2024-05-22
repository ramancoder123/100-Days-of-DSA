#include <iostream>
#include <vector>
using namespace std;

vector<int> upperLower(vector<vector<int> >& arr, int n, int m){
    int sum1 = 0;
    int sum2 = 0;

    vector<int> ans(2, 0);

    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(i >= j){
                sum1 += arr[i][j];
            }
            else if(i <= j){
                sum2 += arr[i][j];
            }
        }
    }

    ans[0] = sum1;
    ans[1] = sum2;

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

    cout<< "Sum : ";
    vector<int> ans = upperLower(arr, n, m);
    for(int i =0;i<ans.size();i++){
        cout<<ans[i]<< " ";
    }

    return 0;
}