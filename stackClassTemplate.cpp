#include<iostream>
#include<vector>
using namespace std;

template <class T> //gives us freedom of making anykind of stack
class Stack{
    public:
    vector<T> vec; //now this T type can be anything which the main fn will tell us

    void push(T val){  //value will be T type too
        vec.push_back(val);
    }

    void pop(){
        vec.pop_back();
    }

    T top(){
        int lastidx=vec.size()-1;
        return vec[lastidx];
    }

    bool isEmpty(){
        if(vec.size()==0){
            cout<<"Stack is empty\n";
            return true;
        }
        else{
            return false;
        }
    }

};

int main(){

    Stack<string> s; //we will declare type of stack like this
    s.push("suhani");
    s.push("dad");
    s.push("mom");

    while(!s.isEmpty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}