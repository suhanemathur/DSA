#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=right=NULL;
    }
};

static int idx=-1;
Node* buildTree(vector<int>nodes){
    idx++;
    if(nodes[idx]==-1){
        return NULL;
    }

    Node* currnode=new Node(nodes[idx]);
    currnode->left=buildTree(nodes);
    currnode->right=buildTree(nodes);
    return currnode;
}

bool isIdentical(Node* root, Node* subroot){
    if(root==NULL && subroot==NULL){
        return true;
    }
    if (root==NULL || subroot==NULL){
        return false;
    }
    
    if(root->data!=subroot->data){
        return false;
    }

    return isIdentical(root->left, subroot->left) 
            && isIdentical(root->right, subroot->right);
}

bool isSubtree(Node* root, Node* subroot){
    if(root==NULL && subroot==NULL){
        return true;
    }
    else if (root==NULL || subroot==NULL){
        return false;
    }

    if(root->data==subroot->data){ //we have found our subroot now we have to check for rest subroot tree
        //check for identical
        if(isIdentical(root, subroot)){
            return true;
        }
    }
    int isLeftsusbtree=isSubtree(root->left, subroot);
    if(!isLeftsusbtree){ //if not found in left subtree then we only call for right, else why call it unnecessarily
        return isSubtree(root->right, subroot);
    }

    return true;

}

int main(){
    vector<int>nodes={1,2 ,4 ,-1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root=buildTree(nodes);

    Node* subroot=new Node(2);
    subroot->left=new Node(4);
    //subroot->right=new Node(7);

    cout<<isSubtree(root, subroot)<<endl;



    return 0;
}
