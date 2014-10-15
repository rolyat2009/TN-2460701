/* 
 * File:   LnkdLst.h
 * Author: Dr. Mark E. Lehr
 * Created on September 18, 2014, 3:09 PM
 */

#ifndef LNKDLST_H
#define	LNKDLST_H

#include <string>
using namespace std;
template <class T>
class LnkdLst {
public:
    //constructor
    LnkdLst(int v)
    {
        head=NULL;
    }
    //copy constructor
    LnkdLst(LnkdLst &obj)
    {
        head=NULL;
        //new link
        Node *link= new Node;
        //assign data to new node
        obj.worker=obj.head;
        link->data=obj.worker->data;
        link->next=NULL;
        //cout<<"Old :"<<obj.worker->data<<endl;
        //if head is null
        if(!head)
        {
            head=link;
            worker=head;
            worker->data=obj.worker->data;
           // cout<<"New :"<<worker->data<<endl;
            //at this point the first node is initialized with data and a pointer to NULL
            
            //copy the data to the new list
            while(obj.worker->next)
            {
               obj.worker=obj.worker->next;
               append(obj.worker->data);
               worker=worker->next;
               worker->data=obj.worker->data;
               //cout<<"Old :"<<obj.worker->data<<endl;
               //cout<<"New :"<<worker->data<<endl;
            }
        }
    }
    //adds to the end of the list
    void append(T n)
    {
        //Create chain link nodes
        Node *link= new Node;
        //insert values
        link->data=n;
        link->next=NULL;
        //add it to the chain
        if(!head)
            head=link;
        else
        {
            worker=head;
            while(worker->next)
            {
                worker=worker->next;
            }
                worker->next=link;
        }
    }
    //adds to the beginning of the list
     void prepend(T n)
    {
        //Create chain link nodes
        Node *link= new Node;
        //insert values
        link->data=n;
        if(head)
        {
            worker=head;
            head=link;
            link->next=worker;
        }
    }
     //prints out the linked list data
    void toString()
    {
        if(head)
        {
            worker=head;
            do
            {
                 cout<<"Data element in the list ->"<<worker->data<<endl;
            }while(worker=worker->next);
        }
        cout<<endl;
    }
    //goes to the first element of the list and prints it 
    void first()
    {
        if(head)
        {
            cout<<"Data in the first link: ";
            cout<<head->data<<endl;
        }
        else
            cout<<"The beginning of the list is null"<<endl;
    }
    //goes to the last element of the list and prints it 
    void last()
    {
     if(head)
        {
            worker=head;
            while(worker->next)
            {
                worker=worker->next;
            }
            cout<<"Data in the last link: ";
            cout<<worker->data<<endl;
        }
    }
    bool extract(int n)
    {
        int i=0;
        int count=0;
        if(head && n>=0)
        {
            //if starting at node 0
            if(n==0)
            {
                worker=head;
                head=head->next;
                delete worker;
                return true;
            }
            //get count of # of links
            worker=head;
            while(worker->next)
            {
                worker=worker->next;
                count++;
            }
            if(n>count)
            {
                cout<<"ERROR: Linked List does not have that many nodes."<<endl;
                return false;
            }
            //cout<<"count: "<<count<<endl;
            worker=head;
            while(worker->next)
            {
                //if removing node 1 (the second node)
                if(n==1)
                {
                    Node *temp1=new Node;
                    temp1=worker;
                    temp1=temp1->next;
                    //cout<<"Data of worker: "<<worker->data<<endl;
                    //cout<<"Data of temp1: "<<temp1->data<<endl;
                    temp1=temp1->next;
                    //cout<<"Data of temp1 after moving: "<<temp1->data<<endl;
                    worker->next=temp1;
                    while(worker->next)
                    {
                        worker=worker->next;
                    }
                    return true;
                }
                worker=worker->next;
                i++;
   //if removing the last node
                if(i==count-1)
                {
                    //cout<<"test "<< i<<endl;
                    Node *temp=new Node;
                    //so now we are on the 2nd to the last node
                    //assign temporary as worker and move onto the next node as temporary
                    temp=worker;
                    temp=temp->next;
                    //cout<<"value of node :"<<temp->data<<endl;
                    //delete temp
                    delete temp;
                    //make the newly last link point to NULL
                    worker->next=NULL;
                    return true;
                }
    //if removing any other node
                else if(i==n-1)
                {
                    Node *temp1=new Node;
                    temp1=worker;
                    temp1=temp1->next;
                    //cout<<"Data of worker: "<<worker->data<<endl;
                    //cout<<"Data of temp1: "<<temp1->data<<endl;
                    temp1=temp1->next;
                    //cout<<"Data of temp1 after moving: "<<temp1->data<<endl;
                    worker->next=temp1;
                    while(worker->next)
                    {
                        worker=worker->next;
                    }
                    return true;
                }
            }
            
        }
        else
        {
                cout<<"ERROR: Linked List is either NULL or a negative number was used as input."<<endl;
                return false;
        }
    }
    //insert a number after node n
    bool insertAfter(T NumToInsert, int node)
    {
        int i=0;
        if(head)
        {
            worker=head;
            while(worker->next && i<node)
            {
                worker=worker->next;
                i++;
            }
            //if not at the end of the list
            if(worker->next)
            {
                //cout<<"At :"<<node<<endl;
                //cout<<"Value :"<<worker->data<<endl;
                //hold worker pointer
                Node *temp=new Node;
                temp=worker;
                worker=worker->next;
                //new value
                Node *NewValue=new Node;
                NewValue->data=NumToInsert;
                temp->next=NewValue;
                NewValue->next=worker;
                while(worker->next)
                {
                    worker=worker->next;
                }
                return true;
            }
            //if at the end of list
            else
            {
            
                //cout<<"end"<<endl;
                //new value
                Node *NewValue=new Node;
                NewValue->data=NumToInsert;
                NewValue->next=NULL;
                worker->next=NewValue;
                return true;
            }
                
        }
        else {
            cout<<"ERROR: Head is NULL"<<endl;
            return false;}
    }
    bool insertBefore(T NumToInsert, int node)
    {
        int count=0;
        //input error checking
        worker=head;
            while(worker->next)
            {
                worker=worker->next;
                count++;
            }
            if(node>count)
            {
                cout<<"ERROR: Cannot insert new value because the Linked List does not have that many nodes."<<endl;
                return false;
            }
        
        int i=0;
        worker=head;
            while(worker->next)
            {
                worker=worker->next;
                i++;
                if(i==node-1)
                {
                    //we are at the node before "node"
                    Node *link=new Node;
                    Node *temp=new Node;
                    //cout<<"at node- "<<worker->data<<endl;
                    link->data=NumToInsert;
                    //cout<<"new node value- "<<link->data<<endl;
                    temp=worker;
                    worker=worker->next;
                    //cout<<"node value ahead- "<<worker->data<<endl;
                    temp->next=link;
                    link->next=worker;
                    return true; 
                }
            }
    }
    //Overloaded = operator
    void operator=(LnkdLst &right)
    {
        delete head;
        //delete worker;
        head=NULL;
        //new link
        Node *link= new Node;
        //assign data to new node
        right.worker=right.head;
        link->data=right.worker->data;
        link->next=NULL;
        //cout<<"Old :"<<obj.worker->data<<endl;
        //if head is null
        if(!head)
        {
            head=link;
            worker=head;
            worker->data=right.worker->data;
           // cout<<"New :"<<worker->data<<endl;
            //at this point the first node is initialized with data and a pointer to NULL
            
            //copy the data to the new list
            while(right.worker->next)
            {
               right.worker=right.worker->next;
               append(right.worker->data);
               worker=worker->next;
               worker->data=right.worker->data;
               //cout<<"Old :"<<obj.worker->data<<endl;
               //cout<<"New :"<<worker->data<<endl;
            }
        }
    }
    //deletes the memory and data of the list
    virtual ~LnkdLst()
    {
        int c=0;
        if(head)
        {
            do{
                worker=head;
                head=head->next;
                delete worker;
                cout<<"Destroying Link "<<c++<<endl;
                }while(head);
         }
        else
            cout<<"head is null";
    }
private:
    struct Node
    {
         T data;
         Node *next;
    };
    Node *head;
    Node *worker;
};
#endif	/* LNKDLST_H */