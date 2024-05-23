#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findFloor(long long v[], long long n, long long x){
    int result = -1;
    
    if(v[n-1] < x )
        return n-1;
    for(int i=0; i<n; ++i) {
        if(v[i]>x)
            if((i-1) >= 0)
                return (int)(i-1);
            else
                break;
        else if(v[i]==x)
            return (int)i;
    }
    return result;
}


int main(){
    int n;
    cout<< "Enter size : ";
    cin>>n;

    long long arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    int x;
    cout<< "Enter x value : ";
    cin>>x;

    cout<<findFloor(arr, n, x)<<endl;
}