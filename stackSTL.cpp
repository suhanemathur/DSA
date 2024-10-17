#include<iostream>
#include<stack>
using namespace std;

void pushAtBottom(stack <int>&s, int val){
    if(s.empty()){
        s.push(val); //for empty stack, oush at top=push at bottom
        return;
    }
    int temp=s.top();
    s.pop();
    pushAtBottom(s, val);
    s.push(temp);
}

string reverse_string(string str){
    stack<char>s;
    string ans;

    for(int i=0; i<str.length(); i++){
        s.push(str[i]);
    }

    while(!s.empty()){
        ans+=s.top();
        s.pop();
    }
    return ans;
}

// stack<int> reverse_stack(stack<int>s){ //with extra space
//     stack<int>ans;

//     while(!s.empty()){
//         ans.push(s.top());
//         s.pop();
//     }
//     return ans;
// }

void reverseStack(stack<int>&s){ //using recursion and no other space
    if(s.empty()){
        return;
    }
    int temp=s.top();
    s.pop();
    reverseStack(s);
    pushAtBottom(s, temp);
}

int main(){
    //STL stack written with small s-> stack
    stack<int>s;

    s.push(3);
    s.push(2);
    s.push(1);
    int val=4;

    pushAtBottom(s, val);

    // while(!s.empty()){
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }
    // cout<<endl;

    string word="hello";
    stack<char>str;
    cout<<reverse_string(word)<<endl;

    reverseStack(s);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}