#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data=val;
        next=prev=NULL;
    }
};

class DLL{
    public:
    Node* head;
    Node* tail;

    DLL(){
        head=tail=NULL;
    }

    void push_front(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
    }

    void pop_front(){
        Node* temp=head;
        head=head->next;
        if(head!=NULL){//case of one node dll, since then now head wil be null
            head->prev=NULL; //since prev of head always points to NULL
        }
        temp->next=NULL;
        delete temp;
    }
};

void printdll(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"<->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}

int main(){
    DLL ll;
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    printdll(ll.head);

    ll.pop_front();
    ll.pop_front();
    printdll(ll.head);

    return 0;
}