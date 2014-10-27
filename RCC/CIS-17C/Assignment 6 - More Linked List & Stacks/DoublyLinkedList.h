/* 
 * File:   DoublyLinkedList.h
 * Author: Tay
 *
 * Created on October 9, 2014, 4:16 PM
 */

#ifndef DOUBLYLINKEDLIST_H
#define	DOUBLYLINKEDLIST_H

using namespace std;
template <class T>
class DoubLnkdLst {
private:
    struct Node
    {
         T data;
         Node *next;
         Node *previous;
    };
    Node *head;
    Node *worker;    
public:
    //constructor
    DoubLnkdLst()
    {
        head=NULL;
    }
    //destructor
    virtual ~DoubLnkdLst()
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
            cout<<"Head is null";
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
        {
            head=link;
            link->previous=NULL;
        }
        else
        {
            worker=head;
            while(worker->next)
            {
                worker=worker->next;
            }
                
                worker->next=link;
                link->previous=worker;
                
        }
    }
    //adds to the beginning of the list
     void prepend(T n)
    {
        //Create chain link nodes
        Node *link= new Node;
        //insert values
        link->data=n;
        link->previous=NULL;
        if(!head)
        {
            head=link;
            link->next=NULL;
        }
        else
        {
            worker=head;
            head=link;
            link->next=worker;
            worker->previous=link;
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
    void testLink(int c)
    {
        int count=0;
        if(!head)
            cout<<"List is empty"<<endl;
        else
        {
            worker=head;
            while(worker->next)
            {
                worker=worker->next;
                count++;
            }
            count++;
            if(c<=count)
            {
                count=0;
                worker=head;
                while(worker->next)
                {
                    worker=worker->next;
                    count++;
                }
                cout<<"At node "<<count<<" with value '"<<worker->data<<"' whose previous connection is ";
                worker=worker->previous;
                cout<<"'"<<worker->data<<"'"<<endl;
            }
            else
                cout<<"There are not that many nodes.\n";
        }
    }
};

#endif	/* DOUBLYLINKEDLIST_H */

