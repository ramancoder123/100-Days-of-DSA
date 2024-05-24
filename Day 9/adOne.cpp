#include <iostream>
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

Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;
        
    while(curr != NULL){
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

Node* addOne(Node *head) { 
    head = reverse(head);
       
    Node* curr = head;
    Node* prev = head;
       
    int sum = curr -> data + 1;
    curr -> data = sum%10;
    int carry = sum/10;
       
    curr = curr -> next;
       
    while(curr != NULL){
        sum = curr -> data + carry;
        curr -> data = sum%10;
        carry = sum/10;
            
        prev = curr;
        curr = curr -> next;
    }
       
    if(carry != 0){
       prev -> next = new Node(carry);
    }
    head = reverse(head);
    return head;
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

    Node* ans = addOne(head);
    display(ans);
}
