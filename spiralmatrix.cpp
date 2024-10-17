#include<iostream>
#include<vector>
using namespace std;

int main(){
    int mat[4][4]={0};
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cin>>mat[i][j];
        }
    }

    int n=4;
    // int temp=n;

    // 1   2  3 4
    // 5   6  7 8
    // 9   10 11 12
    // 13  14 15 16

    int srow=0;
    int scol=0;
    int ecol=n-1;
    int erow=n-1;

    while(srow<=erow && scol<=ecol){ //<= and not < so that in odd matrices the middle row/middle col does get left
        //top
        for(int j=scol; j<=ecol; j++){
            cout<<mat[srow][j]<<" ";
        }

        //right
        for(int i=srow+1; i<=erow; i++){
            cout<<mat[i][ecol]<<" ";
        }

        //bottom
        for(int j=ecol-1; j>=scol; j--){
            if(srow==erow){ //no duplicates being printed in case of odd matrices when top loop has already 
                            //traversed them
                break;
            }
            cout<<mat[erow][j]<<" ";
        }

        //left
        for(int i=erow-1; i>=srow+1; i--){
            if(scol==ecol){//no duplicates being printed in case of odd matrices when right loop has already 
                            //traversed them
                break;
            }
            cout<<mat[i][scol]<<" ";
        }
        srow++;
        ecol--;
        erow--;
        scol++;
    }




    return 0;
}