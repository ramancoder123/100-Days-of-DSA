#include <iostream>
#include <string> 
#include <algorithm>
using namespace std;

bool isAnagram(string str1, string str2){
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    return str1 == str2 ? 1 : 0;
}

int main(){
    string str1;
    cout<< "Enter string : ";
    getline(cin, str1);

    string str2;
    cout<< "Enter second string : ";
    getline(cin, str2);

    if(isAnagram(str1, str2)){
        cout<< "True"<<endl;
    }
    else{
        cout<< "False"<<endl;
    }
}