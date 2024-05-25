#include <iostream>
#include <cmath>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this -> data = data;
            this -> next = NULL;
        }
};

void insertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    if(tail == NULL){
        tail = temp;
    }
    else{
        tail -> next = temp;
        tail = temp;
    }
}

void display(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp -> data<< " ";
        temp = temp -> next;
    }
}

bool isPrime(int n){
    if(n == 1 || n <= 0){
        return false;
    }
    for(int i = 2;i<=sqrt(n);i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

Node* primeList(Node *head){
    Node* root = head;
        
    while(head != NULL){
        int temp1 = head -> data;
        
        if(isPrime(temp1)){
            head = head -> next;
            continue;
        }
            
        else{
            int temp2 = temp1;
            while(!isPrime(temp1) && !isPrime(temp2)){
                temp1++;
                temp2--;
            }
                
            if(isPrime(temp1) && isPrime(temp2)){
                head -> data = min(temp1, temp2);
            }
            else if(isPrime(temp2)){
                head -> data = temp2;
            }
            else{
                head -> data = temp1;
            }
            head = head -> next;
        }
    }
    return root;
}

int main(){
    int n;
    cout<< "Enter size of linked list : ";
    cin>>n;

    Node* head = NULL;
    Node* tail = NULL;

    int i = 0;
    while(i < n){
        int d;
        cin>>d;

        insertAtTail(tail, d);
        if(head == NULL){
            head = tail;
        }
        i++;
    }

    Node* ans = primeList(head);

    display(ans);
}
