/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on September 17, 2014, 5:26 PM
 */

#include "SIMPLEVECTOR.h"

using namespace std;

int main(int argc, char** argv)
{
    SimpleVector<int> original(10);
    cout<<"Original Size: "<<original.size()<<endl;
    original.pull(original);
    cout<<"Size After Pull: "<<original.size()<<endl;
    original.push(original);
    cout<<"Size After Push: "<<original.size()<<endl;
    
    
    return 0;
}

