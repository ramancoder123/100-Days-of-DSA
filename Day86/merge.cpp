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

Node* findMid(Node* head){
    Node* slow = head;
    Node* fast = head -> next;
    
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
        
    return slow;
}
    
Node* merge(Node* left, Node* right){
    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }
        
    Node* ans = new Node(-1);
    Node* temp = ans;
        
    // mereg 2 sorted linked list
    while(left != NULL && right != NULL){
        if(left -> data < right -> data){
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        else{
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }
        
    while(left != NULL){
        temp -> next = left;
        temp = left;
        left = left -> next;
    }
        
    while(right != NULL){
        temp -> next = right;
        temp = right;
        right = right -> next;
    }
        
    ans = ans -> next;
        
    return ans;
}

Node* mergeSort(Node* head) {
    // base case
    if(head == NULL || head -> next == NULL){
        return head;
    }
        
    Node* mid = findMid(head);
        
    Node* left = head;
    Node* right = mid -> next;
        
    mid -> next = NULL;
        
    // recursive calls to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);
        
    // merge left and right
    Node* result = merge(left, right);
        
    return result;
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

    Node* result = mergeSort(head);
    display(result);
}