/* 
 * File:   Employee.h
 * Author: Tay
 *
 * Created on October 15, 2014, 2:34 PM
 */

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H
using namespace std;
class Employee
{
private:
    string name;
    int empNum;
public:
     Employee ()
    {
        setName("name");
        setEmpNum(0);
    }
    void setName(string n)
    {name=n;}
    void setEmpNum(int n)
    {empNum=n;}
    const string getName()
    {return name;}
    const int getEmpNum()
    {return empNum;}
};
#endif	/* EMPLOYEE_H */