#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Node{
public:
    int data;
    Node* next; //to store the address of next node

    //constructor
    Node(int val){
        data=val;
        next=NULL;//initially when node is made only data is given and not next node add, so initially next is NULL
    }

    ~Node(){
        // cout<<"Node destructor being called for data value: "<<data;
        // cout<<endl;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
    }
};

class List{ //collection of nodes is called ll, so this our ll class
    // Node* head;//using node class we have made a head node of our ll
    // Node* tail;

public:
    //made them also public so that fns outside the list class can also access them
    Node* head;//using node class we have made a head node of our ll
    Node* tail;

    //constructor
    List(){ //initially our ll is empty
        head=NULL;
        tail=NULL;
    }

    ~List(){
        // cout<<"Destructor being called for linked list\n";
        if(head!=NULL){
            delete head;
            head=NULL;
        }
    }

    void push_front(int val){
        Node* newNode=new Node(val); //new keyword to dynamically allocate mem
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

    void print_ll(){
        if(head==NULL){
            cout<<"Linked list is empty";
            return;
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

    void insert(int val, int pos){
        Node* temp=head;
        int index=0;
        for(int i=0; i<pos-1; i++){
            temp=temp->next;
        }
        Node* newNode=new Node(val);
        newNode->next=temp->next;//linking the value of right exisitng node at pos so that we dont lose its add
        temp->next=newNode; //now linking the left tie from temp to new pos element
        //if we do the above line first, the rest of the array will be lost since the address of pos+1 is in curr temp->next
        //which would have been linked to the new ele and would have been lost
    }

    void pop_front(){
        Node* temp=head; //coz we have dynamically allotted mem to head, to explicitly hi delete krna hoga
        //just uska next pointer null krdene se nahi hoga
        head=head->next; //updated our head
        temp->next=NULL;//then updated next of our prev head which is now stored in temp to null,connection break with ll
        delete temp; //then deleted temp to explicitly delete prev head node
    }

    void pop_back(){
        Node* temp=head;
        while(temp->next->next!=NULL){ //curr node ke next node ka next null hai kya we are searching, this condition will 
                                    //give us tail's previous node
            temp=temp->next;
        }
        temp->next=NULL;             //temp rn is tail's previous node
        delete tail;
        tail=temp;
    }

    int searchinLL(int target){
        Node*temp=head;
        int index=0;
        while(temp!=NULL){
            if(temp->data==target){
                return index;
            }
            index++;
            temp=temp->next;
        }
        return -1;
    }

    void reverse(){
        Node* prev=NULL; //static allocation, will delete itself after fn is finished
        Node* curr=head;
        tail=head; //usually tail not given so skipped this line

        while(curr!=NULL){
            Node* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
    }
 
    int size(){ //O(N)-since traversing the whole ll
        Node*temp=head;
        int index=0;
        while(temp!=NULL){
            index++;
            temp=temp->next;
        }
        return index;
    }

    void removefromend(int pos){
        int sz=size();
        Node* temp=head;
        for(int i=1; i<(sz-pos); i++){//will get us prev node of position we want to delete
            temp=temp->next;
        }
        temp->next=temp->next->next;
    }

    int helper(Node* h, int key){//since head is a private member of list class so main fn does not have access
        if(h==NULL){//not found
            return -1;
        }
        if(h->data==key){//found at head of ll
            return 0;//thus returning 0, since head is first ele
        }
        int idx=helper(h->next, key);//not found, find in next node
        if(idx==-1){
            return -1;
        }
        return idx+1;//+! since while coming back the head will change and one by one take values till actual head
        //reached, so idx+1 for everytime a new head comes till actual head is reached to give correct index of key node
    }

    int search(int key){
        return helper(head, key);//head is private, main does noe have access so calling it this way
    }
};

    bool FloydAlgo(Node* head){
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

    Node* merge(Node* left, Node* right){
        Node* start=left;
        Node* end=right;
        List ans; //making a new ans ll
        while(start!=NULL && end!=NULL){
            if(start->data <= end->data){
                ans.push_back(start->data);
                start=start->next;
            }
            else{
                ans.push_back(end->data);
                end=end->next;
            }
        }

        while(start!=NULL){
            ans.push_back(start->data);
            start=start->next;
        }

        while(end!=NULL){
            ans.push_back(end->data);
            end=end->next;
        }

        return ans.head;
    }

    Node* splitAtMid(Node* head){
        Node* slow=head;
        Node* fast=head;
        Node* prev=NULL; //start at position of slow-1
        while(fast->next!=NULL && fast!=NULL){
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

    void removecycle(Node* head){
        Node* slow=head;
        Node* fast =head;
        bool isCycle=false;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                isCycle=true;
                break;
            }
        }

        if(!isCycle){
            return;
        }

        slow=head;

        if(slow==head){
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

int main(){
    //in main we will use our list class only, and list class will internally use Node class
    List ll;
    // List ll1;
    // ll1.print_ll();
    // cout<<endl;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.print_ll();
    cout<<endl;

    ll.push_back(4);
    ll.push_back(5);
    ll.print_ll();
    ll.insert(100, 2);
    cout<<endl;
    ll.print_ll();
    cout<<endl;
    ll.pop_front();
    ll.print_ll();
    cout<<endl;
    cout<<ll.searchinLL(100);
    cout<<endl;
    cout<<ll.search(100);
    ll.reverse();
    cout<<endl;
    ll.print_ll();
    cout<<endl;
    // cout<<ll.size();
    ll.removefromend(2);
    ll.print_ll();
    cout<<endl;
    ll.push_front(100);
    ll.print_ll();
    cout<<endl;

    //lets make cycle first
    ll.tail->next=ll.head;
    //now we cannot print ll since infinite trversal
    //100->5->4->3->2->100 is the ll rn

    cout<<FloydAlgo(ll.head);//to check if cycle exits
    cout<<endl;

    removecycle(ll.head); //cycle being removed
    ll.print_ll();
    cout<<endl;

    ll.head=mergesortLL(ll.head); //since mergesort will give us the hed of new sorted ll, so we give that val to our ll
    ll.print_ll();
    cout<<endl;


    List original;
    original.push_back(6);
    original.push_back(1);
    original.push_back(4);
    original.push_front(70);
    original.print_ll();
    cout<<endl;
    original.head=mergesortLL(original.head);
    original.print_ll();








    
    //1->2->3->null



    return 0;
}