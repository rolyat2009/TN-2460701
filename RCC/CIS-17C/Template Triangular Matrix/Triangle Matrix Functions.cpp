#include "Triangle Matrix.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

//template<class T>
int** triMatrix:: fillArray(int rows,int cols)
{
    //Declare the 2-D Array
    int ** array=new int*[rows];
    for(int row=0;row<rows;row++){
        array[row]=new int[cols];
    }
    //Fill the array with random 2 digit numbers
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            array[row][col]=rand()%90+10;
        }
    }
    return array;
}
//template<class T>
int** triMatrix:: fillArray(int rows,int *colAry){
    //Declare the 2-D Array
    int ** array=new int*[rows];
    for(int row=0;row<rows;row++){
        //cout<<"Number of Cols = "<<colAry[row]<<endl;
        array[row]=new int[colAry[row]];
    }
    //Fill the array with random 2 digit numbers
    for(int row=0;row<rows;row++){
        for(int col=0;col<colAry[row];col++){
            array[row][col]=rand()%90+10;
            //cout<<"Row Col"<<row<<" "<<col<<endl;
        }
    }
    return array;
}
//template <class T>
void triMatrix::destroy(int *array)
{
    //Destroy row pointers
    delete []array;
}

//template <class T>
void triMatrix::destroy(int **array,int rows){
    //Destroy cols
    for(int row=0;row<rows;row++){
        delete []array[row];
    }
    //Destroy row pointers
    delete []array;
}
//template <class T>
void triMatrix::printArray(int*array,int cols,int perLine)const
{
    //Print the Array
    cout<<endl;
    for(int col=0;col<cols;col++){
       cout<<array[col]<<" ";
       if(col%perLine==(perLine-1))cout<<endl; 
    }
    cout<<endl;
}
//template <class T>
void triMatrix::printArray(int**array,int rows,int *colAry)const
{
    //Print the Array
    cout<<endl;
    for(int row=0;row<rows;row++){
        for(int col=0;col<colAry[row];col++){
            cout<<array[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
//template <class T>
void triMatrix::printArray(int**array,int rows,int cols)const
{
    //Print the Array
    cout<<endl;
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            cout<<array[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
//template <class T>
int* triMatrix::fillArray(int cols){
    //Declare the 1-D Array
    int * array=new int[cols];
    //Fill the array with random 2 digit numbers
    for(int col=0;col<cols;col++){
        array[col]=rand()%9+2;
    }
    return array;
}
