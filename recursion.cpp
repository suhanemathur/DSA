#include <iostream>
#include <vector>
using namespace std;

int factorial(int n){
    if(n==0){
        return 1;
    }
    return n*factorial(n-1);
}

void printNtoOne(int n){
    if(n==0){
        return;
    }
    cout<<n<<" ";
    printNtoOne(n-1);
    
}

int sumofnaturalnums(int n){
    if(n==0){
        return 0;
    }
    return n+sumofnaturalnums(n-1);
}

int fib(int n){
    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    return fib(n-1)+fib(n-2);
    

}

bool isSorted(int arr[], int n, int i){
    if(i==n-1){ //till n-1 coz last element by itself is always sorted
        return true;
    }
    if(arr[i]>arr[i+1]){
        return false;
    }
    return isSorted(arr, n, i+1);
}

int firstOccureence(string arr[], int n, string target, int i){
    if(i==n){ // here we need till last element
        return -1;
    }
    if(arr[i]==target){
        return i;
    }
    return firstOccureence(arr, n, target, i+1);
}

int lastOccurence(string arr[], int n, string target){
    if(n<=0){
        return -1;
    }
    if(arr[n]==target){
        return n;
    }
    return lastOccurence(arr, n-1, target);
}

int printXtoPowerofN(int x, int n){ //O(n)
    if(n==1){
        return x;
    }
    return x*printXtoPowerofN(x, n-1);
}

int pow(int x, int n){ //O(logn)
    if(n==0){
        return 1;
    }
    int half=pow(x, n/2);
    int halfsquare=half*half;
    if(n%2!=0){
        return x*halfsquare;
    }
    return halfsquare;
}

void removeduplicate(string s, string& res, int i, bool letters[]){ //to pass a string by ref add &
    if(i==s.size()){
        return;
    }
    int index=s[i]-'a';
    if(letters[index]==false){
        res+=s[i];
        letters[index]=true;
    }
    removeduplicate(s, res, i+1, letters);
    
}

int pairfriends


int main(){
    cout<<factorial(4)<<endl;
    printNtoOne(5);
    cout<<endl;
    cout<<sumofnaturalnums(5);
    cout<<endl;
    cout<<fib(5);
    cout<<endl;

    int arr[10]={1,54,0,2,4,98,45,101,6,2};
    int arr1[5]={1,2,3,4,5};
    cout<<isSorted(arr, 10, 0);
    cout<<endl;
    cout<<isSorted(arr1, 5, 0);
    cout<<endl;
    string words[5]={"hello","namaste","hello","namaste","suhani"};
    cout<<firstOccureence(words, 5, "namaste", 0);
    cout<<endl;
    cout<<lastOccurence(words, 5, "suhani");
    cout<<endl;
    cout<<printXtoPowerofN(2,5);
    cout<<endl;
    cout<<pow(2,10);
    string word="appnsscoolleg";
    cout<<endl;
    cout<<endl;

    string res="";
    bool letters[26]={false};
    removeduplicate(word, res, 0, letters);
    cout<<"New word without duplicates is: "<<res;
  





    return 0;
}