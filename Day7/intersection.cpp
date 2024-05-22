#include <iostream>

using namespace std;

class node{
    public:
        int data;
        node* next;

    node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtTail(node* &tail, int d){
    node* temp = new node(d);
    if(tail == NULL){
        tail = temp;
    }
    else{
        tail -> next = temp;
        tail = tail -> next;
    }
}

void display(node* &head){
    node* temp = head;
    int i = 0;

    while(temp != NULL){
        cout<< "Node "<< ++i<< " : "<<endl;
        cout<< "Data : "<<temp -> data<<endl;
        cout<< "Next : "<<temp -> next<<endl;
        cout<<endl;

        temp = temp -> next;
    }
}

node* intersection(node* &head1, node* &head2){
    node *temp = NULL;
    node *head = NULL;
        
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data == head2->data)
        {
            node *newNode = new node(head1->data);
            if(temp==NULL)
            {
                temp = newNode;
                head = temp;
            }
            else
            {
                temp->next =newNode;
                temp = temp->next;
            }
            head1 =head1->next;
            head2 = head2->next;
        }
        else if(head1->data < head2->data)
        {
            head1 = head1->next;
        }
        else if(head1->data > head2->data)
        {
            head2 = head2->next;
        }
    }
        
    return head;
}

int main(){
    node* head1 = NULL;
    node* tail1 = NULL;

    int n;
    cout<< "enter size of first linked list : ";
    cin>>n;

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

    node* head2 = NULL;
    node* tail2 = NULL;

    int m;
    cout<< "enter size of first linked list : ";
    cin>>m;

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

    node* ans = intersection(head1, head2);

    display(ans);

    return 0;
}