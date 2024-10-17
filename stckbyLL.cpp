#include<iostream>
#include<vector>
#include<list>
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


template <class T>
class Stack{
    // list<T> ll;
// public:
    Node<T>* head; //will have to tell that node is of type T, same with everytime we are making new node

    public:
    Stack(){
        head=NULL;
    }

    // void push(T val){
    //     ll.push_front(val);
    // }
    void push(T val){  //linked list's push_front fn
        Node<T>* newNode=new Node<T>(val);
        if(head==NULL){
            head=newNode;
        }
        else{
            newNode->next=head;
            head=newNode;
        }
    }

    // void pop(){
    //     ll.pop_front();
    // }

    void pop(){ //linked lists's pop_front fn
        if(head==NULL){
            return;
        }
        else{
            Node<T>* temp=head;
            head=head->next;
            delete temp;
        }
    }

    // T top(){
    //     if (!isEmpty()) {
    //         return ll.front();
    //     }
    //     cout<<ll.front(); //will give the dats of head/top
    // }

    T top(){
        if(head!=NULL){
            return head->data;
        }
    }

    // bool isEmpty(){
    //     if(ll.size()==0){
    //         return true;
    //     }
    //     else{
    //         return false;
    //     }
    // }

    bool isEmpty(){
        return (head==NULL);
    }

};

int main(){
    Stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);

    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }



    return 0;
}