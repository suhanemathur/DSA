#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }

    ~Node(){
        if(next!=NULL){
            delete next;
            next=NULL;
        }
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

    ~List(){
        if(head!=NULL){
            delete head;
            head=NULL;
        }
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

    void insert(int val, int pos){
        Node* newNode=new Node(val);
        Node*temp=head;
        for(int i=0; i<pos-1; i++){//goes til pos-1 since just at start of the loop the index updates, 
                                    //if we start from 1 then till i<pos
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
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

    int search(int target){
        Node* temp=head;
        int index=0;
        while(temp!=NULL){
            if(temp->data==target){
                return index;
            }
            temp=temp->next;
            index++;
        }
        return -1;

    }

};
    bool isCycle(Node* head){
        Node* slow=head;
        Node* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                cout<<"Cycle exists\n";
                return true;
            }
        }
        cout<<"Cycle does not exist\n";
        return false;

    }

    void removeCycle(Node* head){
        Node* slow=head;
        Node* fast=head;
        bool cycle=false;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                cycle=true;
                break;
            }
        }

        if(!cycle){
            return; //no cycles to remove
        }

        slow=head;

        if(slow==head){//when slow and fast meet at head itself (tail connected to head)
            while(fast->next!=slow){
                fast=fast->next;
            }
            cout<<"Cycle being removed\n";
            fast->next=NULL;
        }
        else{
            Node* prev=fast;
            while(slow!=fast){
                slow=slow->next;
                prev=fast;
                fast=fast->next;
            }
            cout<<"Cycle being removed\n";
            prev->next=NULL;
        }
    }

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
            cout<<"NULL";
        }
    }

    //  Node* merge(Node* left, Node* right){
    //     Node* start=left;
    //     Node* end=right;
    //     List ans; //making a new ans ll
    //     while(start!=NULL && end!=NULL){
    //         if(start->data <= end->data){
    //             ans.push_back(start->data);
    //             start=start->next;
    //         }
    //         else{
    //             ans.push_back(end->data);
    //             end=end->next;
    //         }
    //     }

    //     while(start!=NULL){
    //         ans.push_back(start->data);
    //         start=start->next;
    //     }

    //     while(end!=NULL){
    //         ans.push_back(end->data);
    //         end=end->next;
    //     }

    //     return ans.head;
    // }

    Node* merge(Node* left, Node* right) {
        if (!left) return right;
        if (!right) return left;

        if (left->data <= right->data) {
            left->next = merge(left->next, right);
            return left;
        }
        else {
            right->next = merge(left, right->next);
            return right;
        }
    }

    Node* splitAtMid(Node* head){
        Node* slow=head;
        Node* fast=head;
        Node* prev=NULL; //start at position of slow-1
        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(prev!=NULL){
            prev->next=NULL; //split done
        }
        return slow; //returning righthead of right ll
    }

    Node* mergesortLL(Node* head){
        if(head->next==NULL || head==NULL){
            return head;
        }

        Node* righthead=splitAtMid(head);
        Node* left=mergesortLL(head);
        Node* right= mergesortLL(righthead);

        return merge(left, right);//will head of new sorted ll
    }


int main(){
    List ll;
    printll(ll.head);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(100);
    ll.push_front(5);
    ll.push_back(2);
    ll.push_back(1);
    printll(ll.head);
    cout<<endl;
    ll.insert(50, 2);
    printll(ll.head);
    ll.pop_back();
    ll.pop_front();
    cout<<endl;
    printll(ll.head);
    cout<<endl;
    // cout<<ll.recursivesearch(head,50,0);

    //we will make a cycle first
    ll.tail->next=ll.head; //now we cannot print this ll since will print for infinity
    //100->50>4->3->2->100 is the new ll

    cout<<isCycle(ll.head);
    cout<<endl;
    removeCycle(ll.head); //cycle being removed

    printll(ll.head);
    cout<<endl;
    ll.head=mergesortLL(ll.head);
    printll(ll.head);


    


    


    return 0;
}