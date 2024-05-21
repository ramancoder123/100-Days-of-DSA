#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Given an expression string x. Examine whether the pairs and the orders of {,},(,),[,] are correct in exp.
// For example, the function should return 'true' for exp = [()]{}{[()()]()} and 'false' for exp = [(]).

// Note: The drive code prints "balanced" if function return true, otherwise it prints "not balanced".

bool isValid(string str) {
    stack<char> st;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '{' || str[i] == '[' || str[i] == '(') {
            st.push(str[i]);
        } else if (str[i] == '}' || str[i] == ')' || str[i] == ']') {
            if (st.empty()) {
                return false;
            } else {
                char top = st.top();
                if ((top == '{' && str[i] == '}') ||
                    (top == '[' && str[i] == ']') ||
                    (top == '(' && str[i] == ')')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
    }

    return st.empty();
}

int main(){
    string str;
    cout<< "Enter string : ";
    getline(cin, str);

    if(isValid(str)){
        cout<< "Balanced"<<endl;
    }
    else{
        cout<< "Not balanced"<<endl;
    }

}