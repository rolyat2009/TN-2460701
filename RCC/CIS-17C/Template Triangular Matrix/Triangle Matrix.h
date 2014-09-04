/* 
 * File:   Triangle Matrix.h
 * Author: Taylor Nesby
 * Created: September 3, 2014, 8:12 PM
 * Purpose: Template Class for Trianglular Matrix
 */

#ifndef TRIANGLE_MATRIX_H
#define	TRIANGLE_MATRIX_H

using namespace std;

//template <class T>
class triMatrix
{
public:
    int rows,cols,perLine;
    //cls=rows
private:
    triMatrix()
    {
        rows=0, cols=0, perLine=0;
    }
    triMatrix(int r, int c, int p)
    {
        rows=r, cols=c, perLine=p;
    }
    ~triMatrix()
    {}
    int** fillArray(int,int);
    int** fillArray(int,int*);
    int*  fillArray(int);
    void printArray(int*,int,int) const;
    void printArray(int**,int,int) const;
    void printArray(int**,int,int *) const;
    void destroy(int *);
    void destroy(int **,int);
};
#endif	/* TRIANGLE_MATRIX_H */