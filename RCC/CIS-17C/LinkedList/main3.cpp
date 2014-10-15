/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 18, 2014, 1:55 PM
 * Purpose:  Explore creation of a linked list class Version 3
 */

//System Libraries
#include <iostream>
using namespace std;

//Our Library
#include "LnkdLst.h"

int main(int argc, char** argv)
{
    //Create a linked list
    LnkdLst<int> list(0);
    //Append 3 more chains
    int clinks=3;
    for(int i=1;i<=clinks;i++){
        list.append(i);
    }
    //Prepend 3 more chains
    for(int i=1;i<=clinks;i++){
        list.prepend(i);
    }
    //Print the data
    list.toString();
    //first function
    list.first();
    cout<<endl;
    //last function
    list.last();
    cout<<endl;
    //extract a linked node
    int num=2;
    bool extract=list.extract(num);
    if(extract)
    {
        cout<<"After extraction of link "<<num<<" the new list of nodes are:"<<endl;
        //Print the data
        list.toString();
    }
    else
        cout<<"Extraction could not take place because of the above error."<<endl<<endl;
    //insert a number after a specified node
    int numtoinsert=7, node=4;
    if(list.insertBefore(numtoinsert,node))
    {
        cout<<"After inserting "<< numtoinsert <<" before node "<<node<<" the new list of nodes are:"<<endl;
        //Print the data
        list.toString();
    }
    numtoinsert=12, node=5;
    if(list.insertAfter(numtoinsert,node))
    {
       cout<<"After inserting "<< numtoinsert <<" after node "<<node<<" the new list of nodes are:"<<endl;
       //Print the data
       list.toString();
   }
   LnkdLst<int> copy=list;
   cout<<"After copying constructor has ran the copy has the values: "<<endl;
   copy.toString();
   LnkdLst<int> overloaded(0);
   overloaded=list;
   cout<<"After overloaded operator has ran the new list is as follows: "<<endl;
   overloaded.toString();
   cout<<endl;
   //Exit stage right!
    return 0;
}//make it work for Objects!