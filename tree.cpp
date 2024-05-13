#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class treeNode
{
public:
    T data;
    vector<treeNode<T>*> children;
    treeNode(T data)
    {
        this->data = data;
    }
     ~treeNode(){
        for(int i=0;i<children.size();i++){
            delete children[i];
        }
     }
};
treeNode<char> *takeinput()
{
    char RootData;
    cout << "Enter data" << endl;
    cin >> RootData;
    treeNode<char> *root = new treeNode<char>(RootData);
    int n;
    cout << "enter number of child of " << RootData << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        treeNode<char> *child = takeinput();
        root->children.push_back(child);
    }
    return root;
};
treeNode<int> *input()
{
    //Using Queue->
    int rootdata;
    cout << "Enter root data : ";
    cin >> rootdata;
    treeNode<int> *root = new treeNode<int>(rootdata);

    queue<treeNode<int> *> pendingNode;
    pendingNode.push(root);
    while (pendingNode.size() != 0)
    {
        treeNode<int> *front = pendingNode.front();
        pendingNode.pop();
        int numChild;
        cout << "enter no of child of " << front->data << endl;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "enter " << i << " th child data : ";
            cin >> childData;
            treeNode<int> *child = new treeNode<int>(childData);
            front->children.push_back(child);
            pendingNode.push(child);
        }
    }
    return root;
};
int noOfnode(treeNode<int> *root)
{
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans = ans + noOfnode(root->children[i]);
    }
    return ans;
}

void printtree(treeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ": ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printtree(root->children[i]);
    }
}
int sumofNode(treeNode<int> *root)
{
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        int sum1 = sumofNode(root->children[i]);
        sum = sum + sum1;
    }
    return sum;
}
int maxx(treeNode<int> *root)
{
    int maxi = INT16_MIN;
    for (int i = 0; i < root->children.size(); i++)
    {
        int cm = maxx(root->children[i]);
        maxi = max(cm, maxi);
    }
    return max(maxi, root->data);
}
int hieght(treeNode<int> *root)
{
    int hi = -1;

    for (int i = 0; i < root->children.size(); i++)
    {
        int ch = hieght(root->children[i]);
        hi = max(ch, hi);
    }
    return {hi + 1};
}

void PrintatLevelK(treeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ";
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        PrintatLevelK(root->children[i], k - 1);
    }
};
int noOfleaf(treeNode<int> *root)
{
    int cnt = 0;
    if (root == NULL)
    {
        return 0;
    }
    if (root->children.size() == 0)
    {
        cnt++;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        int lfnode = noOfleaf(root->children[i]);
        cnt = cnt + lfnode;
    }

    return cnt;
}

void PreOreder(treeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        PreOreder(root->children[i]);
    }
};
void PostOrder(treeNode<int> *root){
    if(root==NULL){
        return;
    }
   
    for(int i=0;i<root->children.size();i++){
        PostOrder(root->children[i]);
    }
    cout<<root->data<<" ";

}
int maximumSubtreeWithNode(treeNode<int> *root){
    int sum = 0;
    for(int i=0;i<root->children.size();i++){
        int csum = maximumSubtreeWithNode(root->children[i]);
        sum = sum + csum;
    }
    sum+=root->data;
    

}
int main()
{

    // 1 2 3
    treeNode<int> *Root = input();
    printtree(Root);
    cout << endl;
    cout << endl;
    cout << sumofNode(Root);
    cout << endl;
    cout << "max: " << maxx(Root) << endl;
    cout << "hieght : " << hieght(Root) << endl;
    PrintatLevelK(Root, 3);
    cout << endl
         << "No of leaf Node" << noOfleaf(Root);
    cout << endl<<"PreOrder: ";
    PreOreder(Root);
    cout<<"PostOrder: "<<endl;
    PostOrder(Root);
    //deleteTree;
    delete Root;

    
    return 0;
}