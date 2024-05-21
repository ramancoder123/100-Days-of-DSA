#include <iostream>
#include <stack>
#include <string>

using namespace std;

string reverse(string str){
    stack<char> st;
    for(int i = 0;i<str.length();i++){
        st.push(str[i]);
    }

    for(int i = 0 ;i<str.length();i++){
        str[i] = st.top();
        st.pop();
    }
    return str;
}

int main(){
    string str;
    cout<< "Enter string : ";
    getline(cin, str);

    string ans = reverse(str);


    cout<< "Reversed string : "<<ans<<endl;
}