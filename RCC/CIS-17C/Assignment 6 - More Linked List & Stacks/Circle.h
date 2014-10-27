/* 
 * File:   Circle.h
 * Author: Tay
 *
 * Created on October 9, 2014, 5:29 PM
 */

#ifndef CIRCLE_H
#define	CIRCLE_H
using namespace std;
template <class T>
class Circle {
private:
    struct Node
    {
         T data;
         Node *next;
    };
    int count;
    Node *head;
    Node *worker;
public:
    //constructor
    Circle()
    {
        head=NULL;
        worker=NULL;
        count=0;
    }
    //destructor
    virtual ~Circle()
    {
        if (head)
        {
            Node *tmp = head;
            while (tmp->next != head)
              {
                Node * t = tmp;
                tmp = tmp->next;
                delete(t);
              }
            delete tmp;
            head = NULL;
        }
    }
     //adds to the end of the list
    void add(T n)
    {
        count=0;
        //Create chain link nodes
        Node *link= new Node;
        //insert values
        link->data=n;
        //add it to the chain
        if(head==NULL)
        {
            head=link;
            head->next=head;
        }
        else
        {
            worker=head;
            while(worker->next!=head)
            {
                worker=worker->next;
                count++;
            }
                worker->next=link;
                link->next=head;
                count++;
                count++;
        }
    }
    //prints out the linked list data
    void toString()
    {
        int c=0;
        cout<<"count "<<count<<endl;
        if(!head)
        {
             cout<<"There are no elements in the linked list\n";
        }
        else 
        {
            worker=head;
            cout<<"Node "<<c<<"--"<<worker->data<<endl;
            c++;
            while(worker->next!=head)
            {
                worker=worker->next;
                cout<<"Node "<<c<<"--"<<worker->data<<endl;
                c++;
            }
         }
    }
};
#endif	/* CIRCLE_H */