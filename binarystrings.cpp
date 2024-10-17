#include<iostream>
#include<vector>
using namespace std;

void binarystring(string res, int n, char lastplace){
    if(n==0){
        cout<<res<<endl;
        return;
    }
    if(lastplace!='1'){
        binarystring(res+'0', n-1, 0);
        binarystring(res+'1', n-1, 1);
    }
    else{
        binarystring(res+'0', n-1, 0);
    }
}

int main(){
    string res=" ";
    binarystring(res, 1, 0);



    return 0;
}