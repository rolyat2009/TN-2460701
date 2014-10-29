/* 
 * File:   main.cpp
 * Author: Tay
 *
 * Created on October 27, 2014, 12:30 AM
 */
//libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;
//prototypes
void menu(int &);
string* fillArray(int);
void printArray(const string *,int);
void linearSearch(const string *, int, const string *, int);
int binarySearch(string*, int, int, string);
unsigned int hashFunction(const string str);
string* sort(const string *, int);
//main
int main(int argc, char** argv)
{
    srand(static_cast<unsigned int>(time(0)));
    int arraySize=100000;
    //int perLine=10;
    string *arr=fillArray(arraySize);
    string *sorted=sort(arr, arraySize);
    int choice, index;
    const int linear=1, binary=2, hash=3, print=4, quit=5;
    cout<<"\t\tHash Comparison\n";
    cout<<"\t\tTaylor Nesby\n"<<endl;
    const int searchSize=10;
    string *search=new string[searchSize];
    //known to be in array
    search[0]=arr[0];
    search[1]=arr[arraySize-1];
    search[2]=arr[arraySize/2];
    search[3]=arr[arraySize/4];
    search[4]=arr[3*arraySize/4];
    //known to not be in array
    for(int i=5;i<searchSize;i++)
    {
        search[i]=i;
    }
    //time elements
    
    int first, second;
    float total, average;
    do
    {
        menu(choice);
        switch (choice)
        {
            case linear:
                linearSearch(arr, arraySize,search, searchSize);
                break;
            case binary:
                for(int i=0;i<searchSize;i++)
                {
                    first=time(NULL);
                    index=binarySearch(sorted, 1,  arraySize+1 , search[i]);
                    if(index==-1)
                    {
                        second=time(NULL);
                        total+=(second-first);
                    }
                    else
                    {
                        second=time(NULL);
                        total+=(second-first);
                    }
                }
                total=total*pow(10,-9);
                cout<<"Total Time= "<<total<<" seconds."<<endl;
                average=total/searchSize;
                cout<<"Average Time= "<<average<<" seconds.\n"<<endl;
                break;
            case hash:
                first=time(0);
                for(int i=0;i<arraySize;i++)
                {
                    hashFunction(arr[i]);
                }
                second=time(0);
                cout<<"Hash Time Taken = "<<second-first<<" seconds."<<endl;
                break;
            case print:
                printArray(arr, arraySize);
                break;
        }
    }while(choice!=quit);
    delete []arr;
    delete []sorted;
    delete []search;
    return 0;
}
void menu(int &choice)
{
    cout<<"What would you like to do?\n1. Linear Search\n2. Binary Search\n3. Hash\n4. Print\n5. Quit\n";
    cin>>choice;
}
string* fillArray(int size)
{
    char *x=new char[20];
    //string value;
    int random;
    string *arr=new string[size];
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<20;j++)
        {
            x[j] = 97 + rand() % 26;
        }
        string value(x);
        arr[i]=value;
        value="";
    }
    delete []x;
    return arr;
}
void printArray(const string *a,int size)
{
    for(int i=0;i<size;i++)
    {
        //if(i!=0 && i%perLine==0)
          // cout<<endl;
        cout<<a[i]<<"  "<<endl;
        
    }
    cout<<endl;
}
void linearSearch(const string *a, int size, const string *search, int searchSize)
{
    
    //time markers 
    int first, second, total;
    float average;
    for(int i=0;i<size;i++)
    {
        
        for(int j=0;i<searchSize;j++)
        {
            first=time(NULL);
            if(search[j]==a[i])
            {
                second=time(NULL);
                total+=(second-first);
                break;
            }
            else 
            {
                second=time(NULL);
                total+=(second-first);
                break;
            }
        }
    }
    //total=total*pow(10,-9);
    cout<<"Total Time= "<<total<<" seconds."<<endl;
    average=total/searchSize;
    cout<<"Average Time= "<<average<<" seconds.\n"<<endl;
}
string* sort(const string *arr, int size)
{
    string *bArr=new string[size];
    for(int i=0;i<size;i++)
        bArr[i]=arr[i];
    int i,j;
    string tmp;
    for(i=0;i<size;i++)
    {
        j = i;
        while (j > 0 && bArr[j - 1] > bArr[j])
        {
            tmp = bArr[j];
            bArr[j] = bArr[j - 1];
            bArr[j - 1] = tmp;
            j--;
        }
    }
    return bArr;
}
int binarySearch(string*arr, int first, int last, string searchKey)
{
    int index = -1;
    int mid = (first + last)/2;
    if (searchKey == arr[mid])
        index = mid;
    else
    {
        if (searchKey < arr[mid])
            index = binarySearch(arr,first, mid-1, searchKey);
        else
            index = binarySearch(arr, mid+1, last, searchKey);
    }
     return index;
}
unsigned int hashFunction(const string str)
{
    unsigned int b    = 378551;
    unsigned int a    = 63689;
    unsigned int hash = 0;

    for(std::size_t i = 0; i < str.length(); i++)
    {
        hash = hash * a + str[i];
        a    = a * b;
    }

    return (hash & 0x7FFFFFFF);
}

