#include <bits/stdc++.h>

using namespace std;

struct tree{
    int data;
    struct tree *left, *right;
};

struct tree *create()
{
    int d;
    tree *t=new tree();
    cout<<"\n Enter value to insert or -1 for termination: ";
    cin>>d;
    if(d==0)
    return 0;
    
    
    t->data=d;
    cout<<"Enter left child of "<<d<<" : ";
    t->left=create();
    cout<<"Enter right child of "<<d<<" : ";
    t->right=create();
    return t;
}


void inorder( struct tree *root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->data<<" -> ";
        inorder(root->right);
    }
}
void preorder( struct tree *root)
{
    if(root)
    {
        cout<<root->data<<" -> ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder( struct tree *root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" -> ";
    }
}

void levelorder(struct tree *root)
{
    if(root==NULL)
    return;
    
    queue<tree*>q;
    q.push(root);
    cout<<root->data<<" -> ";
    while(!q.empty())
    {
        root=q.front();
        q.pop();
        if(root->left)
        {
            cout<<root->left->data<<" -> ";
            q.push(root->left);
        }
        if(root->right)
        {
            cout<<root->right->data<<" -> ";
            q.push(root->right);
        }
    }
}

int maximum(struct tree *root)
{
    if(root==NULL)
    return -1;
    int max1=-1;
    
    queue<tree*>q;
    q.push(root);
    while(!q.empty())
    {
        root=q.front();
        q.pop();
        if(root->data > max1)
        max1=root->data;
        
        if(root->left)
        q.push(root->left);
        
        if(root->right)
        q.push(root->right);
    }
    return max1;
}

int search(struct tree *root,int x)
{
    if(root==NULL)
    return false;
    
    queue<tree*>q;
    q.push(root);
    while(!q.empty())
    {
        root=q.front();
        q.pop();
        if(root->data == x)
        return true;
        
        if(root->left)
        q.push(root->left);
        
        if(root->right)
        q.push(root->right);
    }
    return false;
}


int main()
{
    struct tree *root=NULL;
    root=create();
    cout<<"Inorder: ";
    inorder(root);
    cout<<"\nPostorder: ";
    postorder(root);
    cout<<"\nPreorder: ";
    preorder(root);
    cout<<"\nLevelorder: ";
    levelorder(root);
    int x;
    cout<<"\n Maximum Element: "<<maximum(root);
    cout<<"\n\nEnter element to be searched: ";
    cin>>x;
    if(search(root,x))
    cout<<"YES";
    else
    cout<<"NO";

    return 0;
}
