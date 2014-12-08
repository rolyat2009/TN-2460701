/* 
 * File:   main.cpp
 * Author: Tay
 *
 * Created on November 27, 2014, 12:58 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

void bubblesort(vector<int> &);
void selection(vector<int> &);
void heapSort(vector<int> &);
void createHeap(vector<int> &, int, int);
void shiftRight(vector<int> &, int, int);
void mergeSort(vector<int> &,int,int);
void merge(vector<int> &,int,int,int);
void quickSort(vector<int> &,int,int);
void mainMenu();
void welcomeMessage();
void invalidMessage();
void fillVector(vector<int> &, int);
void printVector(vector<int> v);

int main(int argc, char** argv)
{
    srand(static_cast<unsigned int>(time(0)));
    const int one=1,two=2,three=3,four=4,five=5,size=10;
    int choice;
    welcomeMessage();
    vector<int> vectorToSort;
    do
    {
        mainMenu();
        cin>>choice;
        fillVector(vectorToSort, size);
        switch(choice)
        {
            case one:
                //before sorting
                cout << "\nBefore sorting:\n\n";
                printVector(vectorToSort);
                //sort the vector
                bubblesort(vectorToSort);
                //print the results
                cout << "\nAfter sorting bubble sort (ascending):\n\n";
                printVector(vectorToSort);
                vectorToSort.clear();
                break;
            case two:
                //before sorting
                cout << "\nBefore sorting:\n\n";
                printVector(vectorToSort);
                //sort the vector
                selection(vectorToSort);
                //print the results
                cout << "\nAfter sorting selection sort (descending):\n\n";
                printVector(vectorToSort);
                vectorToSort.clear();
                break;
            case three:
                //before sorting
                cout << "\nBefore sorting:\n\n";
                printVector(vectorToSort);
                //sort the vector
                heapSort(vectorToSort);
                //print the results
                cout << "\nAfter sorting heap sort (ascending):\n\n";
                printVector(vectorToSort);
                vectorToSort.clear();
                break;
            case four:
                //before sorting
                cout << "\nBefore sorting:\n\n";
                printVector(vectorToSort);
                //sort the vector
                mergeSort(vectorToSort,0,vectorToSort.size()-1);
                //print the results
                cout << "\nAfter sorting merge sort (ascending):\n\n";
                printVector(vectorToSort);
                vectorToSort.clear();
                break;
            case five:
                //before sorting
                cout << "\nBefore sorting:\n\n";
                printVector(vectorToSort);
                //sort the vector
                quickSort(vectorToSort,0,vectorToSort.size()-1);
                //print the results
                cout << "\nAfter sorting quicksort (ascending):\n\n";
                printVector(vectorToSort);
                vectorToSort.clear();
                break;
        }
        if(choice<1 || choice>6)
            invalidMessage();
    }while(choice!=6);
    return 0;
}
void welcomeMessage()
{
    cout<<"\t\tSorting Comparisons By Taylor Nesby\n\n";
}
void mainMenu()
{
    
    cout<<"Which would you like to run?\n1. Bubble Sort\n2. Selection Sort\n3. Heap Sort\n4. Merge Sort\n5. QuickSort\n6. Quit\n";
}
void invalidMessage()
{
    cout<<"\nPlease enter a valid choice\n";
}
void fillVector(vector<int> &v, int size)
{
    for(int i=0;i<size;++i){
        v.push_back(rand()%90+10);
    }
    return;
}
void printVector(vector<int> v)
{
    int count=0;
    for (vector<int>::iterator it=v.begin();it!=v.end();++it)
    {
        cout<<"Element "<<count<<" = "<< *it<<endl;
        count++;
    }
}
//n^2
void bubblesort(vector<int> &v)
{
    //sort the array
    int n=v.size()-1;
    //must go through n times    
    for(int i=0;i<n;i++) 
    {
        //must go through n times
        for (int j = 0; j < n; j++ )
        {
            if ( v[j] > v[j+1] )
            {
                int temp = v[j+1];
                v[j+1] = v[j];
                v[j] = temp;
            }
        }
    }
    //therefore bubble sort is an O(n^2) function
    return;
}
//n^2
void selection(vector<int> &v)
{
    int i, j, first, temp;
    int size = v.size( );
    //must go through n times
    for (i= size - 1; i > 0; i--)
    {
        first = 0;
        //must go through n times again
        for (j=1; j<=i; j++) 
        {
            if (v[j] < v[first])
                first = j;
        }
        temp = v[first];   
        v[first] = v[i];
        v[i] = temp;
     }
    //therefore selection sort is an O(n^2) function
     return;
}
void shiftRight(vector<int> &v, int low, int high)
{
    int root = low;
    while ((root*2)+1 <= high)
    {
        int leftChild = (root * 2) + 1;
        int rightChild = leftChild + 1;
        int swapIdx = root;
        if (v[swapIdx] < v[leftChild])
        {
            swapIdx = leftChild;
        }
        if ((rightChild <= high) && (v[swapIdx] < v[rightChild]))
        {
            swapIdx = rightChild;
        }
        if (swapIdx != root)
        {
            int tmp = v[root];
            v[root] = v[swapIdx];
            v[swapIdx] = tmp;
            root = swapIdx;
        }
        else
        {
            break;
        }
    }
    return;
}
//logn
void createHeap(vector<int> &v, int low, int high)
{
    //createHeap is an O(logn) function
    //function halves the number of items each time
    int midIdx = (high - low -1)/2;
    while (midIdx >= 0)
    {
        shiftRight(v, midIdx, high);
        --midIdx;
    }
    return;
}
//n*logn
void heapSort(vector<int> &v)
{
    int n=v.size();
    //createHeap is an O(logn) function
    createHeap(v, 0, n-1);
    int high = n - 1;
    //goes through vector n times
    while (high > 0)
    {
        int tmp = v[high];
        v[high] = v[0];
        v[0] = tmp;
        --high;
        createHeap(v, 0, high);
    }
    //therefore heap sort is an O(nlogn) function)
    return;
}
//n*logn
void mergeSort(vector<int> &v,int low,int high)
{
    int mid;
    //function halves the number of items each time->O(logn))
    if(low<high)
    {
        mid=(low+high)/2;
        mergeSort(v,low,mid);
        mergeSort(v,mid+1,high);
        //merge function is an O(n) function
        merge(v,low,high,mid);
    }
    //therefore merge sort is an O(nlogn) function)
}
void merge(vector<int> &v,int low,int high,int mid)
{
    int i,j,k,c[v.size()];
    i=low;
    k=low;
    j=mid+1;
    //goes through vector n times
    while(i<=mid&&j<=high)
    {
        if(v[i]<v[j])
        {
            c[k]=v[i];
            k++;
            i++;
        }
        else
        {
            c[k]=v[j];
            k++;
            j++;
        }
    }
    while(i<=mid)
    {
        c[k]=v[i];
        k++;
        i++;
    }
    while(j<=high)
    {
        c[k]=v[j];
        k++;
        j++;
    }
    for(i=low;i<k;i++){
        v[i]=c[i];
    }
    //therefore this function is an O(n) function
}
//n*logn
void quickSort(vector<int> &v,int left,int right)
{
    int i=left,j=right;
    int temp;
    //function halves the number of items each time-> O(logn))
    int pivot=v[(left+right)/2];
    //must go through vector n times
    while(i<=j)
    {
        while(v[i]<pivot)i++;
        while(v[j]>pivot)j--;
        if(i<=j)
        {
            temp=v[i];
            v[i]=v[j];
            v[j]=temp;
            i++;
            j--;
        }
    }
    if(left<j)quickSort(v,left,j);
    if(i<right)quickSort(v,i,right);
    //therefore quickSort is an O(nlogn)) function
}