/* 
 * File:   main.cpp
 * Author: Taylor Nesby
 * Created on August 27, 2014, 8:06 PM
 * Purpose:  First Data Structure Triangular Array
 */

//System Libraries
#include <iostream>
#include "Triangle Matrix.h"

using namespace std;

//Execution Begins Here
int main(int argc, char** argv)
{
    int rows=5, columns=10, perLine=5;
    //declare arrays via class call 
    triMatrix<int> arrays(rows, columns, perLine);
    //Exit stage right
    return 0;
}
