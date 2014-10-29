/* 
 * File:   Triangle Matrix.h
 * Author: Taylor Nesby
 * Created: September 3, 2014, 8:12 PM
 * Purpose: Template Class for Trianglular Matrix
 */

#ifndef TRIANGLE_MATRIX_H
#define	TRIANGLE_MATRIX_H
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;
template <class T>
class triMatrix
{
private:
    int rows, cols, perLine;
    T *colAry;
    T **array;
    T **triAry;
public:
    triMatrix(int r, int c, int p)
    {
       rows=r;
       cols=c;
       perLine=p;
       colAry=fillArray(cols);
       printArray(colAry, cols, perLine);

       array=fillArray(rows,cols);
       printArray(array,rows,cols);

       triAry=fillArray(rows,colAry);
       printArray(triAry,rows,colAry);    
    }
    ~triMatrix()
    {
        destroy(array,rows);
        destroy(triAry,rows);
        destroy(colAry);
    }
    void setRows(int r)
    {
        rows=r;
    }
    void setCols(int r)
    {
        cols=r;
    }
    void setPerLine(int r)
    {
        perLine=r;
    }
    T** fillArray(int,int)
    {
    //Initialize the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Declare the 2-D Array
    T **array=new T*[rows];
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
    T** fillArray(int,T *)
    {
    //Initialize the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Declare the 2-D Array
    T **array=new T*[rows];
    for(int row=0;row<rows;row++){
        //cout<<"Number of Cols = "<<colAry[row]<<endl;
        array[row]=new T[colAry[row]];
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
    T* fillArray(int)
    {
    //Initialize the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Declare the 1-D Array
    T *array=new T[cols];
    //Fill the array with random 2 digit numbers
    for(int col=0;col<cols;col++){
        array[col]=rand()%9+2;
    }
    return array;
}
    void destroy(T *array)
    {
    //Destroy row pointers
    delete []array;
    }
    void destroy(T **array,int rows){
    //Destroy cols
    for(int row=0;row<rows;row++){
        delete []array[row];
    }
    //Destroy row pointers
    delete []array;
}
    void printArray(T*array,int cols,int perLine)const
{
    //Print the Array
    cout<<endl;
    for(int col=0;col<cols;col++){
       cout<<array[col]<<" ";
       if(col%perLine==(perLine-1))cout<<endl; 
    }
    cout<<endl;
}
    void printArray(T **array,int rows,T *colAry)const
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
    void printArray(T **array,int rows,int cols)const
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
};
#endif	/* TRIANGLE_MATRIX_H */