#include<iostream>
#include <vector>
#include<string.h>
#include <map>
using namespace std;

// 97-122 a-z
// 65-90  A-Z

bool AlmostEqual(string str1, string str2){
    int n1=str1.length();
    int n2=str2.length();
    vector<int>indices;
    if(n1!=n2){
        return false;
    }

    int count=0;
    for(int i=0; i<n1; i++){
        if(str1[i]!=str2[i]){
            count++;
            indices.push_back(i);
        }
    }

    if(count==2){
        int a=indices[0];
        int b=indices[1];
        if(str1[a]==str2[b] && str1[b]==str2[a]){
            return true;
        }
    }
    return false;
}




bool validAnagram(string str1, string str2){
    int n1=str1.length();
    int n2=str2.length();
    if(n1!=n2){
        return false;
    }

    int freqarr[26]={0};
    for(int i=0; i<n1; i++){
        freqarr[str1[i]-'a']++; //finding pos of alphabet and updating it in alphabets arr
    }

    for(int i=0; i<n2; i++){
        if(freqarr[str2[i]-'a']>0){
            freqarr[str2[i]-'a']--;
        }
        else{
            return false;
        }
    }
    return true;

}

void validpalindrome(char*word){
    int start=0;
    int end=strlen(word)-1;
    bool flag=true;
    while(start<end){
        if(word[start]!=word[end]){
            flag=false;
            break;
        }
        start++;
        end--;
    }
    cout<<"Is the word a valid palindrome:"<<flag;
}

void reversechararr(char*word){  //O(n/2)->O(n)
    int start=0;
    int end=strlen(word)-1;
    while(start<end){
        char temp;
        temp=word[start];
        word[start]=word[end];
        word[end]=temp;
        start++;
        end--;
    }
    cout<<"Reversed char arr:"<<word;
}

void ToLower(char*word){
    int n=strlen(word);
    for(int i=0; i<n; i++){
        if(word[i]>='A' && word[i]<='Z'){
            word[i]=word[i]-'A'+'a';
        }
    }
    cout<<"The word in lowercase is:"<<word;
}

void ToUpper(char*word){
    int n=strlen(word);
    string uppercase="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i=0; i<n; i++){
        if(int(word[i])>=97 && int(word[i])<=122){// can simply check (word[i]>='a' && ch<='z)

            int pos=word[i]-'a'; //will find the position of the letter in the alpahbets(starts from 0)
            word[i]=uppercase[pos];
            //OR SIMPLY
            //word[i]='A'+pos; //adding the same position to A to get the uppercase letter
            //simply- word[i]-'a'+'A'; //pos+uppercase
        }
    }
    cout<<"The word in uppercase is:"<<word;

}

int main(){
    char word[]="ApPle";
    ToUpper(word);
    cout<<endl;
    ToLower(word);
    cout<<endl;
    reversechararr(word);
    cout<<endl;
    validpalindrome(word);
    cout<<endl;
    cout<<validAnagram("racecar","xyzd");
    cout<<endl;
    cout<<AlmostEqual("bank", "kanb");




    return 0;
}