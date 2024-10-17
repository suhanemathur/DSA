#include<iostream>
#include<vector>
#include<string>
using namespace std;

void reversestring(string word, string res, int i){
    if(i<0){
        cout<<res;
        return;
    }
    res+=word[i];
    return reversestring(word, res, i-1);
}

int firstoccurence(int arr[], int n, int target, int i){
    if(i>n){
        return -1;
    }
    if(arr[i]==target){
        return i;
    }
    firstoccurence(arr, n, target, i+1);
}

int lastoccurence(int arr[], int n, int target, int i){
    if(i<0){
        return -1;
    }
    if(arr[i]==target){
        return i;
    }
    lastoccurence(arr, n, target, i-1);
}

bool isSorted(int arr[], int n, int i){
    if(i>=n){
        return true;
    }
    if(arr[i-1]>arr[i]){
        return false;
    }
    return isSorted(arr, n, i+1);
}

vector<int> moveAllZeroes(vector<int>&nums, int i , int j){
    if(i>=j){
        return nums;
    }
    if(nums[j]==0){
        return moveAllZeroes(nums, i, j-1);
    }
    if(nums[i]==0){
        swap(nums[i], nums[j]);
        return moveAllZeroes(nums, i+1, j-1);
    }
    return moveAllZeroes(nums, i+1, j);

}

void removeduplicate(string letters, string res1, int i, bool freq[26]){
    if(i>=letters.length()){
        cout<<res1;
        return;
    }
    if(!freq[letters[i]-'a']){
        res1+=letters[i];
        freq[letters[i]-'a']=true;
    }
    removeduplicate(letters, res1, i+1, freq);
}

void printallSubsequences(string word, int i, int j){
    if(i>=word.length()){
        return;
    }
    
}

void printarr(vector<int>nums, int n){
    for(int i=0; i<n; i++){
        cout<<nums[i]<<" ";
    }
}

int main(){
    string word="suhani";
    string res="";
    int arr[6]={2,3,3,1,7,8};
    reversestring(word, res, word.length()-1);
    cout<<endl;
    cout<<firstoccurence(arr, 6, 3, 0);
    cout<<endl;
    cout<<lastoccurence(arr, 6, 3, 6);
    cout<<endl;
    int arr1[6]={1,2,3,4,5,6};
    cout<<isSorted(arr1, 6, 1);
    cout<<endl;
    vector<int>nums={1,0,3,0,6,7,0};
    moveAllZeroes(nums, 0, nums.size()-1);
    printarr(nums, nums.size());
    bool freq[26]={false};
    string res1="";
    string letters="abbccda";
    cout<<endl;
    removeduplicate(letters, res1, 0, freq);




    return 0;
}