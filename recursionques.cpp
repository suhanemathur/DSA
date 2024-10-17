#include<iostream>
#include<vector>
using namespace std;

int binarysearch(vector<int>nums, int target, int start, int end){
    if(start>end){
        return -1;
    }
    int mid=start+(end-start)/2;
    if(nums[mid]==target){
        return mid;
    }
    else if(nums[mid]<target){
        return binarysearch(nums, target, mid+1, end);
    }
    else{
        return binarysearch(nums, target, start, mid-1);
    }
}

void countOccurences(vector<int>nums1, int target, int index, int n){
    if(index>n-1){
        return;
    }
    if(nums1[index]==target){
        cout<<index<<",";
        return countOccurences(nums1, target, index+1, n);
    }
    else{
        return countOccurences(nums1, target, index+1, n);
    }
}

int countsubstrings(string word, int count, int i, int j) {
    if (i >= word.length()) {  // Base case: if i is out of bounds
        return count;
    }
    if (j >= word.length()) {  // If j goes out of bounds, move i to the next start position
        return countsubstrings(word, count, i + 1, i + 1);
    }
    if (word[i] == word[j]) {
        count++;  // Increment count for the substring word[i...j]
        // Recur for the next substring starting from i and ending at j+1
        return countsubstrings(word, count, i, j + 1);
    }
    // If word[i] != word[j], move j to the next position
    return countsubstrings(word, count, i, j + 1);
}

string stringreverse(string letters, int s, int e){
    if(s>e){
        return letters;
    }
    char temp=letters[s];
    letters[s]=letters[e];
    letters[e]=temp;
    return stringreverse(letters, s+1, e-1);
}

void firstandLastOccurence(vector<int>nums1, int target, int left, int right, bool found_left, bool found_right){
    if(left>right){
        cout<<"element not in array";
        return;
    }
    if(nums1[left]==target){
        found_left=true;
        cout<<"First occurence at: "<<left;
        if(!found_right){
            return firstandLastOccurence(nums1, target, left, right-1, found_left, found_right);
        }
    }
    else if(nums1[right]==target){
        cout<<"The last occurence is at: "<<right;
        return firstandLastOccurence(nums1, target, left+1, right);
    }
    return firstandLastOccurence(nums1, target, left+1, right-1);

}



int main(){
    vector<int>nums={1,2,3,4,5,6,7,8,9,10};
    vector<int>nums1={3,2,4,5,6,2,7,2,2};  //target=2
    cout<<binarysearch(nums, 10, 0, nums.size()-1);
    cout<<endl;
    cout<<"The target appears at indices: ";
    countOccurences(nums1, 2, 0, nums.size()-1);
    string word="aba";
    cout<<endl;
    cout<<countsubstrings(word, 0, 0, 0);
    cout<<endl;
    string letters="placement";
    cout<<stringreverse(letters, 0, letters.length()-1);
    cout<<endl;
    bool found_right=false;
    bool found_left=false;
    firstandLastOccurence(nums1, 2, 0, nums.size()-1, found_left, found_right);



    return 0;
}