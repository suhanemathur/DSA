#include <iostream>
#include <vector>
using namespace std;

void elementcount(int arr[][4], int row, int column, int target){
    int count=0;
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            if(arr[i][j]==target){
                count++;
            }
        }
    }
    cout<<target<<" appaers "<<count<<" times ";

}

void secondrowsum(int arr[][4], int row, int column){
    int sum=0;
    for(int j=0; j<4; j++){
        sum+=arr[1][j];
    }
    cout<<"The sum of the second row is: "<<sum;
}

void transposemat(int arr[][4], int row, int column){
    int transpose[4][4];
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            transpose[j][i]=arr[i][j];
        }
    }
    
}

void diagonalsum(int arr[][4], int row, int column){
    if(row!=column){
        cout<<"Diagonal sum is not possible";
        return;
    }
    int d1=0;
    //diagonal 1
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            if(i==j){
                d1+=arr[i][j];
            }
        }
    }

    //diagonal 2
    int d2=0;
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            if(i+j==row-1){
                d2+=arr[i][j];
            }
        }
    }

    cout<<"The diagonal sums are: "<<d1<<" & "<<d2;
}

int searchInSortedMatrix(int arr[][4], int row, int column, int target){
    //brute force-nested loop approach O(n*m) n-rows, m-columns

    //better approach- binary search in row/column(either one is fine) //O(nlogm) or O(mlogn)
    for(int i=0; i<row; i++){
        bool flag=false;
        int start=0;
        int end=column-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[i][mid]==target){
                flag=true;
                cout<<i;
                return mid;
            }
            if(arr[i][mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
    }
}

bool searchInsortedMatrix2(int arr[][4], int row, int column, int target){
    int i=0, j=column-1;
    while(i<row && j>=0){
        if(arr[i][j]==target){
            return true;
        }
        if(arr[i][j]>target){ //have to go left
            j--;
        }
        else{
            i++;
        }
    }
    return false;
}





int main(){

    // 4x4 matrix
    // 0,0   0,1  0,2  0,3
    // 1,0   1,1  1,2  1,3
    // 2,0   2,1  2,2  2,3
    // 3,0   3,1  3,2  3,3

    int mat[4][4];
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cin>>mat[i][j];
        }
    }

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    elementcount(mat, 4, 4, 7);
    cout<<endl;
    secondrowsum(mat, 4, 4);
    cout<<endl;

    diagonalsum(mat, 4, 4);
    cout<<endl;
    cout<<endl;

    cout<<"The taget is in row:";
    searchInSortedMatrix(mat, 4, 4, 33);
    cout<<endl;

    cout<<searchInsortedMatrix2(mat, 4, 4, 39);




    return 0;
}