#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

    Node* currNode=new Node(nodes[idx]);
    currNode->left=buildTree(nodes);
    currNode->right=buildTree(nodes);
    return currNode;
}

void topView(Node* root){
    queue<pair<Node*, int>>q; //(node*, Horizontal Distance)
    map<int, int>m; //(HD, node->data)

    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<Node*, int> curr=q.front();
        q.pop();

        if(m.count(curr.second)==0){ //this hd is unique
            m[curr.second]=curr.first->data;
        }

        if(curr.first->left!=NULL){
            q.push(make_pair(curr.first->left, curr.second-1));
        }

        if(curr.first->right!=NULL){
            q.push(make_pair(curr.first->right, curr.second+1));
        }
    }
    for(auto it: m){
        cout<<it.second<<" ";
    }
}


int main(){
    vector<int>nodes={1,2 ,4 ,-1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root=buildTree(nodes);
    topView(root);

    return 0;
}