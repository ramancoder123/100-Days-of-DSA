#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double median(vector<int>& arr1, vector<int>& arr2, int n, int m){
    int i = 0;
    int j = 0;
    vector<int> ans;

    while(i < n && j < m){
        if(arr1[i] <= arr2[j]){
            ans.push_back(arr1[i]);
            i++;
        }
        else{
            ans.push_back(arr2[j]);
            j++;
        }
    }

    while(i < n){
        ans.push_back(arr1[i]);
        i++;
    }
    while(j < m){
        ans.push_back(arr2[j]);
        j++;
    }

    int s = ans.size();
    if(s%2 != 0){
        return ans[s/2];
    }
    else{
        return (ans[(s/2)-1] + ans[s/2])/2.0;
    }
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


    cout<< "Merged median : "<<median(arr1, arr2, n, m);
    return 0;
}