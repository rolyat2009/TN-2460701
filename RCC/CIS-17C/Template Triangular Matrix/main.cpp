/* 
 * File:   main.cpp
 * Author: Taylor Nesby
 * Created on August 27, 2014, 8:06 PM
 * Purpose:  First Data Structure Triangular Array
 */

//System Libraries
#include "Triangle Matrix.h"
//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //declare arrays via class call  
    triMatrix tri(5,10,10);    
    cout<<tri.rows;
    //int **array=triMatrix fillArray(rows,cols);
    //int *colAry=fillArray(cls);
    //int **triAry=fillArray(rows,colAry);
    
    
    //Print the array
    //printArray(array,rows,cols);
    //printArray(colAry,cls,perLine);
    //printArray(triAry,rows,colAry);
    //Delete the array
    //destroy(array,rows);
    //destroy(triAry,rows);
    //destroy(colAry);
    //Exit stage right
    return 0;
}
