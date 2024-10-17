#include <iostream>
#include<vector>
using namespace std;

class Stack{   //using vector data structure
    vector<int>vec;
    public:

    void push(int val){   //O(1)
        vec.push_back(val);
    }

    void pop(){
        if(isEmpty()){
            cout<<"Stack is empty\n";
            return;
        }
        vec.pop_back();
    }

    int top(){
        if(isEmpty()){
            cout<<"Stack is empty\n";
            return -1;
        }
        int lastidx=vec.size()-1;
        return vec[lastidx];
    }

    bool isEmpty(){
        if(vec.size()==0){
            return true;
        }
        else{
            return false;
        }
    }


    
};

int main(){

    Stack s;
    s.push(3);
    s.push(2);
    s.push(1);
    cout<<s.top();
    cout<<endl;

    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }




    return 0;
}