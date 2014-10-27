/* 
 * File:   Sorted.h
 * Author: Tay
 *
 * Created on October 9, 2014, 8:41 PM
 */

#ifndef SORTED_H
#define	SORTED_H
using namespace std;
class Sorted
{
private:
        
        struct Node
        {
            int data;
            Node *next;
        };
        Node *head;
        Node *worker;
public:
    Sorted()
    {head=NULL;}
    ~Sorted()
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
            cout<<"Head is null.";
    }
    void print()
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
    void insert (int value)
    {
        Node *link=new Node;
        link->data=value;
        /* Special case for the head end */
        if (head == NULL || (head)->data >= link->data)
        {
            link->next = head;
            head = link;
        }
        else
        {
            /* Locate the node before the point of insertion */
            worker = head;
            while (worker->next!=NULL && worker->next->data < link->data)
            {
                worker = worker->next;
            }
            link->next = worker->next;
            worker->next = link;
        }
    }
};
#endif	/* SORTED_H */