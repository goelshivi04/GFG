#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

void insert_b(Node **head, int x)
{
    Node *newnode=new Node();
    newnode->data=x;
    newnode->next=*head;
    *head=newnode;
}

void insert_p(Node **head,int key,int x)
{
    Node *newnode=new Node();
    newnode->data=x;
    Node *prevnode=*head;
    if(key==prevnode->data)
    {newnode->next=prevnode->next;
    prevnode->next=newnode;
    return;}
    
   
    while(prevnode->data!=key)
    {
        prevnode=prevnode->next;
    }
    newnode->next=prevnode->next;
    prevnode->next=newnode;
}

void insert_e(Node **head,int x)
{
    Node *newnode=new Node();
    
    newnode->data=x;
    newnode->next=NULL;
    Node *temp=*head;
    if(temp==NULL)
    {*head=newnode; return;}
    while(temp->next!=NULL)
    temp=temp->next;
    
    temp->next=newnode;
    
}

void printl(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" -> ";
        head=head->next;
    }
}



int main()
{
    Node *head=NULL;
    insert_e(&head,4);
    insert_b(&head,5);
    insert_b(&head,6);
    insert_e(&head,1);
    insert_p(&head,1,3);
    
    printl(head);
    
    
    return 0;
}
