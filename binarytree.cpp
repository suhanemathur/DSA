#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
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

int preorder(Node* root){
    if(root==NULL){
        cout<<"-1 ";
        return -1;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int inorder(Node* root){
    if(root==NULL){
        // cout<<"-1 ";
        return -1;
    }
    
    //left 
    inorder(root->left);
    //root
    cout<<root->data<<" ";
    //right
    inorder(root->right);
}

int postorder(Node* root){
    if(root==NULL){
        return -1;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelorder(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* curr=q.front();
        q.pop();

        if(curr==NULL){
            cout<<endl;
            if(q.empty()){
                break;
            }
            q.push(NULL);
        }
        else{
            cout<<curr->data<<" ";

            if(curr->left!=NULL){
                q.push(curr->left);
            }
        
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
    }
}

int heightofTree(Node* root){
    if(root==NULL){
        return 0;
    }
    int left_height=heightofTree(root->left);
    int right_height=heightofTree(root->right);
    int curr_height=max(left_height, right_height)+1;
    return curr_height;
}

int countofNodes(Node* root){
    if(root==NULL){
        return 0;
    }
    int left_nodes=countofNodes(root->left);
    int right_nodes=countofNodes(root->right);
    int curr_count=left_nodes+right_nodes+1;
}

int sumofNodes(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftsum=sumofNodes(root->left);
    int rightsum=sumofNodes(root->right);
    int curr_sum=rightsum+leftsum+root->data;
    return curr_sum;
}

int main(){
    vector<int>nodes={1,2 ,4 ,-1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root=buildTree(nodes);

    cout<<root->data<<endl;
    cout<<root->left->data<<endl;
    cout<<root->right->data<<endl;

    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    levelorder(root);
    //cout<<endl;
    cout<<"height of tree: "<<heightofTree(root);
    cout<<endl;
    cout<<"The total number of nodes in the tree is: "<<countofNodes(root);
    cout<<endl;
    cout<<"The sum of all nodes is: "<<sumofNodes(root)<<endl;

    vector<int>nodes2={1,2,4,-1,-1,5,-1,6,-1, 7,-1,-1,3,-1,-1};
    idx=-1;
    Node* root2=buildTree(nodes2);
    levelorder(root2);
    cout<<"height of tree: "<<heightofTree(root2);
    cout<<endl;

    cout<<"The sum of all nodes is: "<<sumofNodes(root)<<endl;




    return 0;
}