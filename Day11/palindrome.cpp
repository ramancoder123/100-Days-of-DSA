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

    Node* findMid(Node* head){
        Node* slow = head;
        Node* fast = head -> next;
        
        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
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
    

    bool isPalindrome(Node *head)
    {
        if(head == NULL || head -> next == NULL){
            return true;
        }
        // step1 : find mid of linked list
        Node* mid = findMid(head);
        
        // step2 : reverse linked list
        Node* temp = mid -> next;
        mid -> next = reverse(temp);
        
        // step 3: comapre first and second halves
        Node* head1 = head;
        Node* head2 = mid -> next;
        
        while(head2 != NULL){
            if(head1 -> data != head2 -> data){
                return false;
            }
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
        
        // step4: list to initial state
        temp = mid -> next;
        mid -> next = reverse(temp);
        
        return true;
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

    if(isPalindrome(head)){
        cout<< "True";
    }
    else{
        cout<< "False";
    }
}
