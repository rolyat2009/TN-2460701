/* 
 * File:   main.cpp
 * Author: Tay
 *
 * Created on October 8, 2014, 4:42 PM
 */

#include <cstdlib>
#include <iostream>
#include "Dynamic Stack.h"
#include "DoublyLinkedList.h"
#include "Circle.h"
#include "PriorityQueue.h"
#include "Sorted.h"
using namespace std;
//globals
const int STACK=1, DOUBLE=2, CIRCLE=3, PRIORITY=4, SORTED=5, QUIT=6;
//prototypes
void MainMenu(int &);
void StackMenu(DynamicStack<string> &);
void pushItem(DynamicStack<string> &);
void popItem(DynamicStack<string> &);
void doubly();
void appendItem(DoubLnkdLst<string> &);
void prependItem(DoubLnkdLst<string> &);
void appendItem(Circle<string> &);
void prependItem(Circle<string> &);
void priority();
void circle();
void priority();
void addItem(Priority_Queue &);
void sorted ();
void insertValue(Sorted &list);
//main menu
int main(int argc, char** argv)
{
    cout<<"\t\tAssignment 6\n\t\tTaylor Nesby\n";
    int choice;
    DynamicStack<string> stack;
    do
    {
        MainMenu(choice);
        if(choice!=QUIT)
        {
            switch (choice)
            {
                case STACK:
                    StackMenu(stack);
                    break;
                case DOUBLE:
                    doubly();
                    break;
                case CIRCLE:
                    circle();
                    break;
                case PRIORITY:
                    priority();
                    break;
                case SORTED:
                    sorted();
                    break;
            }
        }
    }
    while(choice!=QUIT);
    return 0;
}
void MainMenu(int &choice)
{
    cout<<"\nWhat do you want to do?\n";
    cout<<"1. Run Stack\n2. Run Doubly Linked List\n3. Run Circularly Linked List\n4. Run Priority Queue\n5. Run Sorted Linked List\n6. Quit\n";
    cin>>choice;
    while(choice< STACK || choice> QUIT)
    {
        cout<<"Please enter a valid choice: ";
        cin>>choice;
    }
}
void StackMenu(DynamicStack<string> &stack)
{
    const int push=1, pop=2, q=3;
    int c;
    do
    {
        cout<<"\nWhat would you like to do?\n";
        cout<<"1. Push\n2. Pop\n3. Main Menu\n";
        cin>>c;
        while(c< push || c> q)
        {
            cout<<"Please enter a valid choice: ";
            cin>>c;
        }
        switch (c)
        {
            case push:
                pushItem(stack);
                break;
            case pop:
                popItem(stack);
                break;
        }
    }while(c!=q);

}
void pushItem(DynamicStack<string> &stack)
{
    string item;
    cin.ignore();
    cout<<"\nEnter an item ";
    getline(cin,item);
    stack.push(item);
}
void popItem(DynamicStack<string> &stack)
{
    string item="";
    stack.pop(item);

    if(item!="")
        cout<<item<<" was popped.\n";
}
void doubly()
{
    const int append=1, prepend=2, print=3, test=4, q=5;
    int c;
    DoubLnkdLst<string> list;
    do
    {
        cout<<"\nWhat would you like to do?\n";
        cout<<"1. Append Node\n2. Prepend Node\n3. Print List\n4. Test Linkage\n5. Main Menu\n";
        cin>>c;
        while(c< append || c> q)
        {
            cout<<"Please enter a valid choice: ";
            cin>>c;
        }
        switch (c)
        {
            case append:
                appendItem(list);
                break;
            case prepend:
                prependItem(list);
                break;
            case print:
                list.toString();
                break;
            case test:
                int nodeNum;
                cout<<"Enter node number you'd like to test.\n";
                cin>>nodeNum;
                list.testLink(nodeNum);
                break;
        }
    }while(c!=q);
}
void appendItem(DoubLnkdLst<string> &list)
{
    string item;
    cin.ignore();
    cout<<"Enter a string to append"<<endl;
    getline(cin,item);
    list.append(item);
}
void prependItem(DoubLnkdLst<string> &list)
{
    string item;
    cin.ignore();
    cout<<"Enter a string to prepend"<<endl;
    getline(cin,item);
    list.prepend(item);
}
void circle()
{
    const int append=1, print=2, q=3;
    int c;
    Circle<string> list;
    do
    {
        cout<<"\nWhat would you like to do?\n";
        cout<<"1. Add Node\n2. Print List\n3. Main Menu\n";
        cin>>c;
        while(c< append || c> q)
        {
            cout<<"Please enter a valid choice: ";
            cin>>c;
        }
        switch (c)
        {
            case append:
                appendItem(list);
                break;
            case print:
                list.toString();
                break;
        }
    }while(c!=q);
}
void appendItem(Circle<string> &list)
{
    string item;
    cin.ignore();
    cout<<"Enter a string to add to list."<<endl;
    getline(cin,item);
    list.add(item);
}
void priority()
{
   const int push=1, pop=2, display=3, q=4;
    int c;
    Priority_Queue que;
    do
    {
        cout<<"\nWhat would you like to do?\n";
        cout<<"1. Add Item\n2. Pop\n3. Print\n4. Main Menu\n";
        cin>>c;
        while(c< push || c> q)
        {
            cout<<"Please enter a valid choice: ";
            cin>>c;
        }
        switch (c)
        {
            case push:
                addItem(que);
                break;
            case pop:
                que.del();
                break;
            case display:
                que.display();
                break;
        }
    }while(c!=q); 
}
void addItem(Priority_Queue &list)
{
    int item;
    int pri;
    cin.ignore();
    cout<<"\nEnter an item ";
    cin>>item;
    cin.ignore();
    cout<<"\nEnter its priority ";
    cin>>item;
    list.insert(item,pri);
}
void sorted ()
{
    const int insert=1, display=2, q=3;
    int c;
    Sorted list;
    do
    {
        cout<<"\nWhat would you like to do?\n";
        cout<<"1. Add Item\n2. Print\n3. Main Menu\n";
        cin>>c;
        while(c< insert || c> q)
        {
            cout<<"Please enter a valid choice: ";
            cin>>c;
        }
        switch (c)
        {
            case insert:
                insertValue(list);
                break;
            case display:
                list.print();
                break;
        }
    }while(c!=q); 
}
void insertValue(Sorted &list)
{
    int item;
    cout<<"Enter a value to insert"<<endl;
    cin>>item;
    list.insert(item);
}