/* 
 * File:   main.cpp
 * Author: Tay
 *
 * Created on October 28, 2014, 9:54 PM
 */

#include <cstdlib>
#include <iostream>
//#include <cmath>
using namespace std;
float futureValue(float pv, float i,int years);
float sumFunction(float pv, float total);
void menu();
int main(int argc, char** argv)
{
    float pv,i,years;
    int end, total=0;
    const int  quit=3, fv=1, sum=2;
    int choice;
    cout<<"\t\tRecursion Assignment"<<endl;
    cout<<"\t\tTaylor Nesby"<<endl;

    do
    {
        menu();
        cin>>choice;
        switch(choice)
        {
            case fv:
                cout<<"Enter present value: ";
                cin>>pv;
                cout<<"Enter interest rate per year in decimal format: ";
                cin>>i;
                cout<<"Enter years: ";
                cin>>years;
                cout<<"Your present balance of "<<pv<<" compounded at "<<i*100<<"% per year for "<<years<<" years will be = $"<<futureValue(pv, i, years)<<endl<<endl;
                //cout<<"Should be the same as $"<<pv*pow((1+i),years)<<endl;
                break;
            case sum:
                cout<<"I can sum from 0 to any integer. Enter the integer you wish to sum through."<<endl;
                cin>>end;
                cout<<"The sum of the integers from 0 to "<< end <<" = "<<sumFunction(end,total)<<endl;
                break;
        }
    }while(choice!=quit);
    return 0;
}
void menu()
{
    cout<<"What would you like to do?\n1. Future Value Calculator\n2. Sum Function\n3. Quit\n\n";
    
}
float futureValue(float pv, float i,int years)
{
    double fv;
    if(years==1)
    {
        fv=pv*(1+i);
        return fv;
    }
    else
    {
        years-=1;
        pv=pv*(1+i);
        futureValue(pv,i,years);
    }
}
float sumFunction(float pv, float total)
{
    float tot;
    if(pv==1)
        return total+1;
    else
    {
        tot=total+pv+(pv-1);
        if(pv==2)
            return tot;
        pv=pv-2;
        sumFunction(pv,tot);
    }
}