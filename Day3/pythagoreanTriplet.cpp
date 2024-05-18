#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Given an array arr of n integers, write a function that 
// returns true if there is a triplet (a, b, c) 
// from the array (where a, b, and c are on different indexes)
// that satisfies a2 + b2 = c2, otherwise return false.

bool isTriplet(vector<int>& arr, int n){
    int max_el = arr[0];

    for(int i =0;i<n;i++){
        max_el = max(arr[i], max_el);
    }

    int a, b, c, d;
    int ans = 0;

    int count[max_el + 1];

    for(int i = 0;i<=max_el;i++){
        count[i] = 0;
    }
    for(int i = 0;i<n;i++){
        count[arr[i]]++;
    }

    for(int i = 0;i<=max_el;i++){
        for(int j = i+1;j<=max_el;j++){
            if(count[i] > 0 && count[j] > 0){
                a = i*i;
                b = j*j;
                c = a + b;
                d = sqrt(c);

                if((d*d) == c && count[d] > 0 && d <= max_el){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    int n;
    cout<< "Enter size : ";
    cin>>n;

    vector<int> arr;
    for(int i = 0;i<n;i++){
        int d;
        cin>>d;
        arr.push_back(d);
    }

    if(isTriplet(arr, n)){
        cout<< "Yes";
    }
    else{
        cout<< "No";
    }

    return 0;
}
