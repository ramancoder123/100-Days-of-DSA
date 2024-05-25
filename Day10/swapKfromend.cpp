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

Node *swapkthnode(Node* head, int num, int K){
    if(K > num){
        return head;
    }
    if(K == (num - K + 1)){
        return head;
    }
    
    Node* start = head;
    Node* startPrev = NULL;
    
    for(int i = 1;i<K;i++){
        startPrev = start;
        start = start -> next;
    }
    
    Node* end = head;
    Node* endPrev = NULL;
    
    for(int i = 1;i<num-K+1;i++){
        endPrev = end;
        end = end -> next;
    }
    
    if(startPrev != NULL){
        startPrev -> next = end;
    }
    if(endPrev != NULL){
        endPrev -> next = start;
    }
    
    Node* temp = start -> next;
    start -> next = end -> next;
    end -> next = temp;
    
    if(K == 1){
        head = end;
    }
    if(K == num){
        head = start;
    }

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
    int k;
    cout<< "Enter k value : ";
    cin>>k;

    Node* ans = swapkthnode(head, n, k);
    display(ans);

    return 0;
}
