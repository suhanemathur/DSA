#include<iostream>
using namespace std;

template<class T>
class Node{
    public:
    T data;
    Node* next;

    Node(T val){
        data=val;
        next=NULL;
    }
};

template<class T>
class List{
    public:
    Node<T>* head;
    Node<T>* tail;

    List(){
        head=NULL;
        tail=NULL;
    }

    void push(T val){ //push_back of linked list
        Node<T>* newNode=new Node<T>(val);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }

    void pop(){   //pop_front of linke dlist
        if(head!=NULL){
            Node<T>* temp=head;
            head=head->next;
            delete temp;
        }
        else{
            tail=NULL;
        }
    }

    T front(){
        return head->data;
    }

    void printQueue(){
        Node<T>* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

};


template <class T>
class Queue{
    public:
    List<T> q;

    void push(T val){
        q.push(val);
    }

    void pop(){
        q.pop();
    }

    T front(){
        return q.front();
    }

    void printqueue(){
        q.printQueue();
    }

};


int main(){
    Queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    q.printqueue();


    return 0;
}