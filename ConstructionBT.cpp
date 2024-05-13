#include<bits/stdc++.h>

using namespace std;
template<typename T>

class BinaryTree{
    public:
    T data;
    BinaryTree* left;
    BinaryTree* right;
    BinaryTree(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTree(){
        delete right;
        delete left;
    }
};
BinaryTree<int> *helper(int in[],int pre[],int inS,int inE,int preS,int preE){
      if (inS > inE || preS > preE) {
        return NULL;
    }
   
    int rootData = pre[preS];
    int rootIndex = -1;
    for(int i=inS;i<=inE;i++){
        if(rootData==in[i]){
            rootIndex = i;
            break;
        }
    }

int LinS = inS;          //IN = left -> root-> right
int LinE =rootIndex-1;    // Pre = root->left->right
int LpreS = preS+1;
int LpreE = LinE-LinS+LpreS;
int RinS =rootIndex+1;
int RinE = inE;
int RpreS = LpreE+1;
int RpreE = preE;

    BinaryTree<int> *root = new BinaryTree<int> (rootData);
    root->left = helper(in,pre,LinS,LinE,LpreS,LpreE);
    root->right = helper(in,pre,RinS,RinE,RpreS,RpreE);


    return root;
}

BinaryTree<int>* buildTree(int in[],int pre[],int size){
    return helper(in,pre,0,size-1,0,size-1);
}

void print(BinaryTree<int> *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" -> ";
    if(root->left){
        cout<<"L: "<<root->left->data;
    }
    if(root->right){
        cout<<"R: "<<root->right->data;
    }
    cout<<endl;
    print(root->left);
    print(root->right);
}

int main(){

int in[] = {4,2,5,1,8,6,9,3,7};
int pre[] = {1,2,4,5,3,6,8,9,7};

BinaryTree<int> *root = buildTree(in,pre,9);
print(root);


    return 0;
}