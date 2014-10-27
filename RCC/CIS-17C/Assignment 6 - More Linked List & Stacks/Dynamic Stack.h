/* 
 * File:   Dynamic Stack.h
 * Author: Tay
 *
 * Created on October 8, 2014, 4:42 PM
 */

#ifndef DYNAMIC_STACK_H
#define	DYNAMIC_STACK_H

#include <string>
using namespace std;
template <class T>
class DynamicStack
{
    private:
        struct StackNode
        {
            T  value;
            StackNode *next;
        };
        
        StackNode *top;
        
    public:
        //constructor
        DynamicStack()
        {top=NULL;}
        //destructor
        ~DynamicStack()
        {
            StackNode *worker, *nextNode;
            worker=top;
            while(worker!=NULL)
            {
                nextNode=worker->next;
                delete worker;
                worker=nextNode;
            }
        }
        //stack functions
        void push(T item)
        {
            StackNode *newNode=new StackNode;
            newNode->value=item;
            //if no more nodes then make the new node the first node
            if(isEmpty())
            {
                top=newNode;
                newNode->next=NULL;
            }
            else
            {
                newNode->next=top;
                top=newNode;
            }
        }
        void pop (T &item)
        {
            StackNode *temp;
            if(isEmpty())
            {
                cout<<"The stack is empty.\n";
            }
            else
            {
                item=top->value;
                temp=top->next;
                delete top;
                top=temp;
            }
        }
        bool isEmpty()
        {
            bool status;
            if(!top)
                status=true;
            if(top)
                status=false;
            return status;
        }
};
#endif	/* DYNAMIC_STACK_H */       