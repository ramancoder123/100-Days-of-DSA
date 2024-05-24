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

Node* sortedMerge(Node* head1, Node* head2)  
{  
    if(head1 == NULL && head2 != NULL){
        return head2;
    }
    
    if(head1 != NULL && head2 == NULL){
        return head1;
    }
    
    Node* ansHead = NULL;
    Node* ansTail = NULL;
    
    Node* curr1 = head1;
    Node* curr2 = head2;
    
    while(curr1 != NULL && curr2 != NULL){
        if(curr1 -> data <= curr2 -> data){
            if(ansHead == NULL){
                ansHead = curr1;
                ansTail = curr1;
            }
            else{
                ansTail -> next = curr1;
                ansTail = curr1;
            }
            curr1 = curr1 -> next;
        }
        else if(curr2 -> data <= curr1 -> data){
            if(ansHead == NULL){
                ansHead = curr2;
                ansTail = curr2;
            }
            else{
                ansTail -> next = curr2;
                ansTail = curr2;
            }
            curr2 = curr2 -> next;
        }
    }
    
    while(curr1 != NULL){
        ansTail -> next = curr1;
        ansTail = curr1;
        curr1 = curr1 -> next;
    }
    
    while(curr2 != NULL){
        ansTail -> next = curr2;
        ansTail = curr2;
        curr2 = curr2 -> next;
    }
    
    return ansHead;
} 

int main(){
    int n;
    cout<< "Enter size of list 1 : ";
    cin>>n;

    Node* head1 = NULL;
    Node* tail1 = NULL;

    int i = 0;
    while(i < n){
        int data;
        cin>>data;

        insertAtTail(tail1, data);
        if(head1 == NULL){
            head1 = tail1;
        }
        i++;
    }

    int m;
    cout<< "Enter size of list 2 : ";
    cin>>m;

    Node* head2 = NULL;
    Node* tail2 = NULL;

    i = 0;
    while(i < m){
        int data;
        cin>>data;

        insertAtTail(tail2, data);
        if(head2 == NULL){
            head2 = tail2;
        }
        i++;
    }

    Node* ans = sortedMerge(head1, head2);

    display(ans);

    return 0;
}
