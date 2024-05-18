#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> unionArray(vector<int> arr1, vector<int> arr2, int n, int m){
    int i = 0, j = 0;
    vector<int> ans;

    while(i < n && j < m){
        if(arr1[i] < arr2[j]){
            if(ans.empty() || ans.back() != arr1[i]){
                ans.push_back(arr1[i]);
            }
            i++;
        }

        else if(arr1[i] > arr2[j]){
            if(ans.empty() || ans.back() != arr2[j]){
                ans.push_back(arr2[j]);
            }
            j++;
        }
        else{
            if(ans.empty() || ans.back() != arr1[i]){
                ans.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }

    while(i < n){
        if(ans.empty() || ans.back() != arr1[i]){
            ans.push_back(arr1[i]);
        }
        i++;
    }
    while(j < m){
        if(ans.empty() || ans.back() != arr2[j]){
            ans.push_back(arr2[j]);
        }
        j++;
    }

    return ans;
}

int main(){
    int n;
    cout<< "Enter size of first array : ";
    cin>>n;

    vector<int> arr1;
    for(int i = 0;i<n;i++){
        int d;
        cin>>d;

        arr1.push_back(d);
    }

    int m;
    cout<< "Enter size of secodn array : ";
    cin>>m;
    vector<int> arr2;
    for(int i =0;i<m;i++){
        int d;
        cin>>d;

        arr2.push_back(d);
    }

    vector<int> ans = unionArray(arr1, arr2, n, m);

    cout<< "Union : ";
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<< " ";
    }

    return 0;
}