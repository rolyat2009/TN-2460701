/* 
 * File:   main.cpp
 * Author: Tay
 *
 * Created on November 1, 2014, 7:56 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>
#include "statClass.h"
void menu();
void problem1();
void problem2();
void problem3();
void problem4();
vector<int> *top(vector<int> , int);
void oneMenu();
vector<int> *mode(vector<int>);
statClass *stat(vector<int>);
statClass *stat(list<int>);
float tanFunc(float);

int main(int argc, char** argv) 
{
    //seeds time
    srand(static_cast<unsigned int>(time(0)));
    //menu choices
    const int one=1, two=2, three=3, four=4,five=5, quit=6;
    int choice;
    do
    {
        menu();
        cin>>choice;
        switch(choice)
        {
            case one:
                problem1();
            break;
            case two:
                problem2();
            break;
            case three:
                problem3();
                break;
            case four:
                problem4();
                break;
            case five:
                float x;
                cout<<"For what value of 'x' would you like to pass through? ";
                cin>>x;
                cout<<"tan(2x)= "<<tanFunc(x)<<endl;
                break;
        }
     }while(choice!=quit);
    return 0;
}
void menu()
{
    cout<<"What would you like to do?\n1. Problem 1 (Vector *top) 15 pts \n2. Problem 2 (Vector *mode) 20 pts\n3. Problem 3 (Vector *stat) 25 pts\n4. Problem 6 (List *stat) 25 pts \n5. Problem 8 (Recursion) 15 pts \n6. Quit\t\t\t~ Total=100 pts ~"<<endl;
}
void problem1()
{
    const int back=3;
            int onemenu,p,count;
            //declares vector to be used for top function
            vector<int> *myvector=new vector<int>;
            for (int i=0; i<100; i++)
                myvector->push_back(rand()%90+10);
            do
            {
                oneMenu();
                cin>>onemenu;
                if(onemenu==1)
                {
                    cout<<"Elements are as follows: "<<endl;
                    int perLine=10,i=1;
                    for (vector<int>::iterator it = myvector->begin() ; it != myvector->end(); ++it)
                    {
                        cout<<*it<<" ";
                        if(i%perLine==0)
                            cout<<endl;
                        i++;
                    }
                    cout<<endl;
                }
                if(onemenu==2)
                {
                    cout<<"How many of the top elements would you like to view? ";
                    cin>>p;
                    while(p<=0)
                    {cout<<"Please enter an input greater than or equal to 0."<<endl;
                    cin>>p;
                    }
                    vector<int> *topVector=new vector<int>;
                    topVector=top(*myvector,p);
                    cout<<"The top "<<p<<" elements in the vector are as follows:"<<endl;
                    count=1;
                    for (vector<int>::iterator it = topVector->begin() ; it != topVector->end(); ++it)
                    {
                        cout<<"Element "<<count<<": "<<*it<<endl;
                        count++;
                    }
                    delete topVector;
                }
                if(onemenu!=back && onemenu!=1 && onemenu!=2)
                    cout<<"Please enter a valid choice\n";
               }while(onemenu!=back);
            //cleanup
            myvector->clear();   
            delete myvector;
}
vector<int> *top(vector<int> myvector, int p)
{
    //declares max
    int max;
    //declares a vector for the top p elements
    vector<int> *top=new vector<int>;
    vector<int> *copy=new vector<int>;
    *copy=myvector;
    //initializes max with the first element
    max=*myvector.begin();
    //declares an iterator to hold position
    vector<int>::iterator index;
    for (int i; i<p; i++)
    {
     //   out = myvector.begin();
            for (vector<int>::iterator it = copy->begin() ; it != copy->end(); ++it)
            {
                if(*it>max)
                {
                    max=*it;
                    index=it;
                }
            }
            top->push_back(max);
            copy->erase(index);
            max=0;
    }
    //cleanup
    copy->clear();
    delete copy;
    return top;    
}
void oneMenu()
{
    cout<<"Which of the following would you like to do?\n1. Print the Original Vector Contents\n2. Print the top 'p' Elements of the Vector\n3. Back\n";
            cout<<endl;
}
void problem2()
{
    
            //declares vector to be used for mode function
            vector<int> *myvector=new vector<int>;
            //fill with random numbers
            for (int i=0; i<100; i++)
                myvector->push_back(rand()%90+10);
            vector<int> *modeVector=new vector<int>;
            cout<<"Original Vector: "<<endl;
            int perLine=10,i=1;
            for (vector<int>::iterator it = myvector->begin() ; it != myvector->end(); ++it)
                {
                    cout<<*it<<" ";
                    if(i%perLine==0)
                        cout<<endl;
                    i++;
                }
            cout<<endl;
            modeVector=(mode(*myvector));
            if(modeVector->empty())
                cout<<"No mode."<<endl;
            else
            {
                i=1;
                cout<<endl<<"Mode(s): ";
                vector<int>::iterator it;
                for (it = modeVector->begin() ; it != modeVector->end()-1; ++it)
                    {
                        cout<<*it<<" ";
                        if(i%perLine==0)
                            cout<<endl;
                        i++;
                    }
                it = modeVector->end()-1;
                cout<<"Frequency :"<<*it<<endl<<endl;;
            }
            //cleanup
            modeVector->clear();
            myvector->clear();
            delete modeVector;
            delete myvector;
}
vector<int> *mode(vector<int> x)
{
    vector <int> *modeVector=new vector<int>;
    vector <int> *copy=new vector<int>;
    *copy=x;
    int modeFreq=1;
    for(vector<int>::iterator index=copy->begin();index!=copy->end();++index)
    {
        for(vector<int>::iterator test=copy->begin();test!=copy->end();++test)
        {
            if(*index==*test & test!=index)
            {
                modeFreq++;
                copy->erase(test);
                --test;
            }
        }
        if(modeFreq>1)
        {
            modeVector->push_back(*index);
            modeVector->push_back(modeFreq);
        }
        modeFreq=1;
    }
    if(modeVector->empty())
    {
        return modeVector;
    }
    else 
    {   
        vector<int>::iterator index=modeVector->begin();
        index++;
        //cout<<*index<<endl;
        modeFreq=*index;
        //index+=2;
        //cout<<*index<<endl;
        int perLine=10,i=1;
        for(index;index!=modeVector->end()+1;index+=2)
        {
            if(*index>modeFreq)
                modeFreq=*index;
            
        
        }
        cout<<"Mode/frequency pairs: "<<endl;
        for (vector<int>::iterator it = modeVector->begin() ; it != modeVector->end(); ++it)
                    {
                        cout<<*it<<" ";
                        if(i%perLine==0)
                            cout<<endl;
                        i++;
                    }
                    cout<<endl<<endl;;
        
        vector <int> *trueMode=new vector<int>;
        index=modeVector->begin();
        index++;
        for(index;index!=modeVector->end()+1;index+=2)
        {
             if(*index==modeFreq)
             {
                 index--;
                 trueMode->push_back(*index);
                 index++;
             }
        }
        trueMode->push_back(modeFreq);
        //cleanup
        copy->clear();
        modeVector->clear();
        delete copy;
        delete modeVector;
        return trueMode;
    }
}
void problem3()
{
    //declares vector to be used for stat vector function
            vector<int> *myvector=new vector<int>;
            //fill with random numbers
            for (int i=0; i<100; i++)
                myvector->push_back(rand()%90+10);
            statClass *info=new statClass;
            info=(stat(*myvector));
            cout<<endl<<"Min: "<<info->getMin()<<endl;
            cout<<"Max: "<<info->getMax()<<endl;
            cout<<"Average: "<<info->getAverage()<<endl;
            cout<<"Mode(s): ";
            info->CalcModeInfoVector();
            cout<<"\nFrequency: "<<info->getFrequency()<<endl<<endl;
            
            //cleanup
            myvector->clear();
            delete myvector;
            delete info;
}
void problem4()
{
    //declares vector to be used for stat list function
            list<int> *mylist=new list<int>;
            //fill with random numbers
            for (int i=0; i<100; i++)
                mylist->push_back(rand()%90+10);
            statClass *info=new statClass;
            info=(stat(*mylist));
            cout<<endl<<"Min: "<<info->getMin()<<endl;
            cout<<"Max: "<<info->getMax()<<endl;
            cout<<"Average: "<<info->getAverage()<<endl;
            cout<<"Mode(s): ";
            info->CalcModeInfoList();
            cout<<"\nFrequency: "<<info->getFrequency()<<endl<<endl;
            //cleanup
            mylist->clear();
            delete mylist;
            delete info;
}
statClass *stat(list<int> x)
{
    statClass *info=new statClass(x);
    return info;
}
statClass *stat(vector<int> x)
{
    statClass *info=new statClass(x);
    return info;
}
float tanFunc(float x)
{
    float epsilon=pow(10,-2);
    if(abs(x)<epsilon)
        return x+((x*x*x)/3);
    return (2*tanFunc(x/2))/(1-tanFunc(x/2)*tanFunc(x/2));
}