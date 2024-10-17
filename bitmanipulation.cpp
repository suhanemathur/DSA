#include <iostream>
#include<vector>
using namespace std;

void OddorEven(int num){ //1 is 0000000001, s
    if(!(num & 1)){   // preserving the rightmost bit and making everthing else 0
        cout<<"Even";
    }
    else{
        cout<<"Odd";
    }
}

void powerofTwo(int num){
    if((num & (num-1))==0){
        cout<<"It is a power of 2";
    }
    else{
        cout<<"Not a power of 2";
    }
}

void UpdateithBit(int n, int pos, int val){
    if(val==1){
        int mask=1<<pos;
        int res=n | mask;
        cout<<res;
    }
    else{
        int mask=~(1<<pos);
        int res=n & mask;
        cout<<res;
    }
}

void countsetBits(int n){
    int count=0;
    while(n>0){
        int lastdig=n&1;
        count+=lastdig;
        n=n>>1;
    }
    cout<<"The number of set bits are: "<<count;
}

void clearrangeofBits(int n, int i, int j){
    int mask=(~0)<<(j+1);
    mask=mask+i;
    int res=n & mask;
    cout<<"Number after updating range i-j is: "<<res;
}

int main(){
    cout<<(~4)<<endl;
    cout<<(8>>1)<<endl;
    OddorEven(8);
    cout<<endl;
    OddorEven(49);
    cout<<endl;

    powerofTwo(8);
    cout<<endl;

    UpdateithBit(7, 3, 1);
    cout<<endl;

    countsetBits(2);
    cout<<endl;

    clearrangeofBits(7, 0, 1);


    return 0;
}