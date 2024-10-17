#include<iostream>
#include<vector>
#include<List>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }

};

class List{
    public:
    Node* head;
    Node* tail;

    List(){
        head=NULL;
        tail=NULL;
    }

    void push_front(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            newNode->next=head;
            head=newNode;
        }
    }

    void push_back(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }

    
    void pop_front(){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }

    void pop_back(){
        Node* temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        temp->next=NULL;
        delete tail;
        tail=temp;
    }

    


};

    void printll(Node* head){
        if(head==NULL){
            cout<<"The linked list is empty\n";
        }
        else{
            Node* temp=head;
            while(temp!=NULL){
                cout<<temp->data<<"->";
                temp=temp->next;
            }
            cout<<"NULL\n";
        }
    }

    Node* merge(Node* left, Node* right){
        if(right==NULL){
            return left;
        }
        if(left==NULL){
            return right;
        }
        Node* si=left;
        Node* ei=right;

        if(si->data <= ei->data){
            left->next= merge(left->next, right);
            return left;
        }
        else{
            right->next= merge(left, right->next);
            return right;
        }
    }

    Node* splitAtMid(Node* head){
        Node* slow=head;
        Node* fast=head;
        Node* prev=NULL;

        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL; //split done
        return slow; //head of right linked list
    }

    Node* mergesort(Node* head){
        if(head==NULL || head->next==NULL){
            return head;
        }

        Node* righthead=splitAtMid(head);
        Node* left=mergesort(head);
        Node* right=mergesort(righthead);

        return merge(left, right);
    }

    //zigzag
    //1->2->3->4->5 now output it as 1->5->
    Node* reverse(Node* head){
            Node* prev=NULL;
            Node* curr=head;
            Node* next=NULL;
            while(curr!=NULL){
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            return prev;

    }

    Node* zigzagLL(Node* head){

        Node* righthead=splitAtMid(head); //will give us the head of second half
        Node* rightrevhead=reverse(righthead);//gives us thenew head of right ll after reversal

        Node* left=head;
        Node* right=rightrevhead;
        Node* tail=right;
        while(left!=NULL && right!=NULL){
            Node* nextleft=left->next;
            Node* nextright=right->next;

            left->next=right;
            right->next=nextleft;
            tail=right;

            left=nextleft;
            right=nextright;
        }
        if(right!=NULL){
            tail->next=right;
        }

        return head;
    }



int main(){
    List ll;
    ll.push_back(8);
    ll.push_back(1);
    ll.push_back(0);
    ll.push_front(90);
    ll.push_front(4);
    printll(ll.head);
    ll.head=mergesort(ll.head);
    printll(ll.head);

    ll.head=zigzagLL(ll.head);
    printll(ll.head);

    List ll1;
    ll1.push_back(1);
    ll1.push_back(2);
    ll1.push_back(3);
    ll1.push_back(4);
    ll1.head=zigzagLL(ll1.head);
    printll(ll1.head);


    


    return 0;
}