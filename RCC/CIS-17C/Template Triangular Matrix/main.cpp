/* 
 * File:   main.cpp
 * Author: Taylor Nesby
 * Created on August 27, 2014, 8:06 PM
 * Purpose:  First Data Structure Triangular Array
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//Global Constants

//Functions Prototypes
int*  fillArray(int);
int** fillArray(int,int);
int** fillArray(int,int*);
void printArray(int*,int,int);
void printArray(int**,int,int);
void printArray(int**,int,int *);
void destroy(int *);
void destroy(int **,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Declare the 2-D Array
    int rows=5,cols=10;
    int cls=rows,perLine=10;
    int **array=fillArray(rows,cols);
    int *colAry=fillArray(cls);
    int **triAry=fillArray(rows,colAry);
    //Print the array
    printArray(array,rows,cols);
    printArray(colAry,cls,perLine);
    printArray(triAry,rows,colAry);
    //Delete the array
    destroy(array,rows);
    destroy(triAry,rows);
    destroy(colAry);
    //Exit stage right
    return 0;
}

void destroy(int *array){
    //Destroy row pointers
    delete []array;
}


void destroy(int **array,int rows){
    //Destroy cols
    for(int row=0;row<rows;row++){
        delete []array[row];
    }
    //Destroy row pointers
    delete []array;
}

void printArray(int*array,int cols,int perLine){
    //Print the Array
    cout<<endl;
    for(int col=0;col<cols;col++){
       cout<<array[col]<<" ";
       if(col%perLine==(perLine-1))cout<<endl; 
    }
    cout<<endl;
}

void printArray(int**array,int rows,int *colAry){
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

void printArray(int**array,int rows,int cols){
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

int* fillArray(int cols){
    //Declare the 1-D Array
    int * array=new int[cols];
    //Fill the array with random 2 digit numbers
    for(int col=0;col<cols;col++){
        array[col]=rand()%9+2;
    }
    return array;
}

int** fillArray(int rows,int *colAry){
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

int** fillArray(int rows,int cols){
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