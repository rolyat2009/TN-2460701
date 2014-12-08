/* 
 * File:   main.cpp
 * Author: Tay
 *
 * Created on November 28, 2014, 9:02 PM
 */

#include <cstdlib>
#include <ctime>
#include<vector>
#include "Tree.h"

int main(int argc, char** argv) {

    srand(static_cast<unsigned int>(time(0)));
    Tree myTree;
    int choice,n,size=10;
    for(int i=0;i<size;i++)
        myTree.insertLeaf(rand() % 90 +10);
    vector<int
    cout<<"\t\tTrees by Taylor Nesby\n\n";
    do
    {
        cout<<"Which would you like to do?\n1. Pre Order Transversal\n2. Post Order Transversal\n3. In Order Transversal\n4. Delete Node\n5. Quit\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
                 myTree.print(choice);
                break;
            case 2:
                 myTree.print(choice);
                break;
            case 3:
                 myTree.print(choice);
                break;
            case 4:
                cout<<"Which value would you like to delete? ";
                cin>>n;
                myTree.removeNode(n);
                break;
        }
        if(choice<1 || choice>5)
            cout<<"Please enter a valid menu option\n";
    }while(choice!=5);
    return 0;
}