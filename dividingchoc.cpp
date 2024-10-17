#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

void dividechoc(vector<int>& arr, int n, int m){
    sort(arr.begin(), arr.end());
    int mindiff=INT_MAX;
    int currdiff=arr[0];
    for(int i=2; i<n; i++){
        currdiff=max(arr[i],arr[i-1,arr[i-2]])-min(arr[i],arr[i-1],arr[i-2]);
        mindiff=min(mindiff, currdiff);

    }
    cout<<mindiff;

}

int main(){
//     Given an array of N integers where each value represents the number of chocolates in a packet. 
//     Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets such that: 
//     Each student gets one packet.
// The difference between the number of chocolates in the packet with maximum chocolates and the 
// packet with minimum chocolates given to the students is minimum.
// Examples:

// Input : arr[] = {7, 3, 2, 4, 9, 12, 56} , m = 3 
// Output: Minimum Difference is 2 
// Explanation:
// We have seven packets of chocolates and we need to pick three packets for 3 students 
// If we pick 2, 3 and 4, we get the minimum difference between maximum and minimum packet sizes.

    vector<int>arr={7, 3, 2, 4, 9, 12, 56};
    int n=arr.size();
    int m=3;

    dividechoc(arr, n, m);



    return 0;
}