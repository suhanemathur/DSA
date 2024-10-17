#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int>ll; //syntax similar to declaring a vector

    ll.push_back(3);
    ll.push_back(4);
    ll.push_front(2);
    ll.push_front(1);
    cout<<ll.size();
    cout<<endl;
    cout<<ll.front();
    cout<<endl; 
    cout<<ll.back();


    return 0;
}
