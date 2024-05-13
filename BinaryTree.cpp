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



void print(BinaryTree<int>*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" -> ";
    if(root->left){
        cout<<"L :"<<root->left->data;
    }
    if(root->right){
        cout<<"R :"<<root->right->data;
    }
    cout<<endl;
    print(root->left);
    print(root->right);
   
    
}


BinaryTree<int>* takeinputLevelWise(){
    int RootData;
    cout<<"Enter Root Data"<<endl;
    cin>>RootData;
    BinaryTree<int>*root = new BinaryTree<int>(RootData);

    queue<BinaryTree<int>*>PendingNodes;
    PendingNodes.push(root);

    while (PendingNodes.size()!=0){
      BinaryTree<int> *front = PendingNodes.front();
      PendingNodes.pop();
      int leftchild;
      cout<<"Enter left node of "<<front->data<<endl;
      cin>>leftchild;
      if(leftchild!=-1){
        BinaryTree<int>*leftnode = new BinaryTree<int>(leftchild);
        front->left = leftnode;
        PendingNodes.push(leftnode);
      }
      int rightchild;
      cout<<"Enter right node of "<<front->data<<endl;
      cin>>rightchild;
      if(rightchild!=-1){
        BinaryTree<int>*rightnode = new BinaryTree<int>(rightchild);
        front->right = rightnode;
        PendingNodes.push(rightnode);
      }
    }
    return root;
}



BinaryTree<int> * takeinput(){
    int rootdata;
    cout<<"Enter Root Data"<<endl;
    cin>>rootdata;
    if(rootdata==-1){
        return NULL;
    }
    BinaryTree<int>*root = new BinaryTree<int>(rootdata);
    BinaryTree<int>*leftchild = takeinput();
    BinaryTree<int> *rightchild = takeinput() ;
    root->left = leftchild;
    root->right = rightchild;

    return root;
};


//Node with Value X;
bool nodewithValue(BinaryTree<int> *root,int X){
    if(root==NULL){
        return false;
    }
    if(root->data == X){
       return true;
    }
    bool l = nodewithValue(root->left,X);
     bool r = nodewithValue(root->right,X); //save r result 
     return (l||r); //if Key is in tree left or right return true;
}


int heightOfTree(BinaryTree<int> *root){
    if(root==NULL){
        return 0;
    }
    int h = 1;
    int r = heightOfTree(root->right);
    int l = heightOfTree(root->left);
    h = max(r,l);
    return h+1;
    
}


//Question - > mirror image of a Binary Tree!
void mirror(BinaryTree<int>* &root){
    if(root==NULL){
        return;
    }
    swap(root->right,root->left);
    mirror(root->right);
    mirror(root->left);
}


//Question[LeetCode 226 ] -> Invert Binary Tree & return Root [@Catch -> save first of all root which is given by question ]!
BinaryTree<int> *Invert(BinaryTree<int> *root){
  BinaryTree<int> *Root = root;
  if(root==NULL ){
    return 0;
  }
  swap(root->left,root->right);
  Invert(root->left);
  Invert(root->right);
  return Root; 
}


//Inordertraversel
void Inordertraversel(BinaryTree<int> *root){
    if(root==NULL){
        return;
    }
    //Inorder traversel is nothing but Printing From left to right
    // [LEFT] -> [ROOT] -> [RIGHT]
    Inordertraversel(root->left);
    cout<<root->data<<" ";
    Inordertraversel(root->right);
}



//postOrder Traversal
void postorder(BinaryTree<int> *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

};



//Check Two Binary Tree are Identiacal or Not!!
bool identical(BinaryTree<int>* one,BinaryTree<int> *two){
    if(one==NULL &&two==NULL ){
        return true;
    }
    if(one==NULL ||two==NULL||one->data!=two->data){
        return false;
    }
    return identical(one->left,two->left) && identical(one->right,two->right);
    //after all recursive calls if all values inside both of trees are 
    //equal ans Return True Otherwise ans should be false;
    
}

//Diameter of a binary tree ;
int height(BinaryTree<int>*root){
    if(root==NULL){
        return 0;
    }
    int h = 1;
    int rH = height(root->right);
    int lH= height(root->left);
    return h+ max(rH,lH);
}
int diamter(BinaryTree<int> *root){
    if(root==NULL){
        return 0;
    }
    int option1 = height(root->left)+height(root->left);
    int option2 = diamter(root->left);
    int option3 = diamter(root->right);
    return max(option1,max(option2,option3));
}
//Diameter of a Binary Tree [O(n)] improve 

pair<int,int> diameterBT(BinaryTree<int> *root){
   if(root==NULL){
    pair<int,int>p;
    p.first = 0;
    p.second = 0;
    return p;
   }

   pair<int,int> leftans = diameterBT(root->left);
   pair<int,int> rightans = diameterBT(root->right);

   int lD = leftans.second;
   int lH = leftans.first;
   int rH = rightans.first;
   int rD = rightans.second;

   pair<int,int> ans;
   ans.first = 1+max(lH,rH);
   ans.second = max(lH+rH,max(lD,rD));
   return ans;

};
//minimum & maximum of a Binary Tree;

int maxx(BinaryTree<int>*root){
    if(root==NULL){
        return 0;
    }
     int Lmax = maxx(root->left);
     int Rmax= maxx(root->right);

     return max(Lmax,max(Rmax,root->data));
}
int minn(BinaryTree<int> *root){
    if(root==NULL){
        return 0;
    }

    int Lmin = minn(root->left);
    int Rmin = minn(root->right);
    return min(Lmin,min(Rmin,root->data));
}
pair<int,int> minMax(BinaryTree<int>*root){
    if(root==NULL){
        pair<int,int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int,int> ans;
    ans.first  = minn(root);
    ans.second = maxx(root);
    return ans;
};


//Number of Nodes
int noOfNode(BinaryTree<int>*root){
    if(root==NULL){
        return 0;
    }
    int cnt = 1;
    int cntR = noOfNode(root->right);
    int cntL = noOfNode(root->left);
    cnt = cnt + cntL + cntR;
    return cnt;
    //return 1+noOfNode(root->right)+noOfNode(root->left); !![Shortcut]
}

//[ Construction Of a Binary Tree using Inorder[],and Postorder[] traversal]

BinaryTree<int>* treeHelper(int *in,int *pre,int inS,int inE,int PreS,int PreE){
  if (inS > inE || PreS > PreE) {
        return NULL;
    }
int rootData = pre[PreS];
int rootIndex = -1;
for(int i = inS;i<=inE;i++){
    if(in[i]==rootData){
        rootIndex = i;
        break;
    }
}
int LinS = inS;          //IN = left -> root-> right
int LinE =rootIndex-1;    // Pre = root->left->right
int LpreS = PreS+1;
int LpreE = LinE-LinS+LpreS;
int RinS =rootIndex+1;
int RinE = inE;
int RpreS = LpreE+1;
int RpreE = PreE;


BinaryTree<int> *root = new BinaryTree<int>(rootData);
root->left = treeHelper(in,pre,LinS,LinE,LpreS,LpreE);
root->right = treeHelper(in,pre,RinS,RinE,RpreS,RpreE);
return root;

};

BinaryTree<int> *BuildTree(int *in,int *pre,int size){
    return treeHelper(in,pre,0,size-1,0,size-1);
}


 //just copy this thing & entire tree is created automatically,what we need to do?
 //1 2 3 4 5 6 7 -1 -1 8 -1 -1 -1 -1 -1 
int main(){

int in[] = {4,2,5,1,8,6,9,3,7};
int pre[] = {1,2,4,5,3,6,8,9,7};

BinaryTree<int> *root = takeinputLevelWise();
print(root);
cout<<endl;
cout<<"No of Node in tree  : "<<noOfNode(root)<<endl;
cout<<"Present Or Not : ";
cout<<nodewithValue(root,9);
cout<<endl<<"hieght of Binary Tree :-> ";
cout<<heightOfTree(root)<<endl;
cout<<"Mirror Image of Binary Tree "<<endl;
mirror(root);
print(root);
cout<<"Post Order : -> ";
postorder(root); cout<<endl;
cout<<"Diameter : ";
cout<<diamter(root)<<endl;
cout<<"improved->";
  pair<int,int> ans =diameterBT(root);
  int height = ans.first;
  int dia = ans.second;
  cout<<"diameter: "<<dia<<" "<<"height: "<<height<<endl;
  pair<int,int> anss = minMax(root);
  cout<<"Min: "<<anss.first<<" "<<"Max: "<<anss.second;



    return 0;
}