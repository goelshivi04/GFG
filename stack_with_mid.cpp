#include <iostream>

using namespace std;

class Stack{
    struct Node{
        int data;
        Node *next, *prev;
    };
    
    Node *top=NULL;
    Node *mid=NULL;
    int size=0;
    
    public:
    void push(int x){
        Node *newnode= new Node();
        newnode->data=x;
        newnode->prev=NULL;
        newnode->next=NULL;
        if(size==0)
        {
            top=newnode;
            mid=newnode;
            size=1;
            return;
        }
        
        top->next=newnode;
        newnode->prev=top;
        top=top->next;
        
        if(size%2==1)
        mid=mid->next;
        
        size++;
        cout<<"Inserted"<<endl;
    }
    
    int pop(){
        if(size==0)
        return -1;
        int x=top->data;
        if(size==1)
        {
            top=NULL;
            mid=NULL;
            size=0;
            return x;
        }
        else
        {
            top=top->prev;
            top->next=NULL;
            
            if(size%2==0)
            mid=mid->prev;
        }
        size--;
        return x;
    }
    
    int find_mid()
    {
        if(size==0)
        return -1;
        
        return mid->data;
    }
    
    
    void del_mid()
    {
        if(size!=0){
            if(size==1)
            {
                mid=NULL;
                top=NULL;
            }
            else if(size==2)
            {
                top=top->prev;
                mid=mid->prev;
                top->next=NULL;
            }   
            else{
                mid->next->prev=mid->prev;
                mid->prev->next=mid->next;
                if(size%2==0)
                mid=mid->prev;
                else
                mid=mid->next;
            }
            size--;
        }
    }
};



int main()
{
    Stack st;
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);
    st.push(55);
    st.push(66);
    st.push(77);
    st.push(88);
    st.push(99);
    cout <<"Popped : "<< st.pop() << endl;
    cout <<"Popped : "<< st.pop() << endl;
    cout <<"Middle Element : "<< st.find_mid() << endl;
    st.del_mid();
    cout <<"New Middle Element : "<< st.find_mid() << endl;
    return 0;
}
