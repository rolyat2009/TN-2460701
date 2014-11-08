/* 
 * File:   statClass.h
 * Author: Tay
 *
 * Created on November 6, 2014, 2:17 AM
 */

#ifndef STATCLASS_H
#define	STATCLASS_H
#include <vector>
#include <map>
#include <list>
//#include <string>
using namespace std;
//template <class T>
class statClass
{
private:
    float min,max,total,size,frequency,modeCount;
    float average;
    vector<int> myvector;
    map<int, int> ModeInfo;
    list<int> mylist;
public:
    statClass(){}
    //default constructor that sets all of the basic stats. I realize I could've made individual functions for each stat but I prefer to calculate it at run time. If this project was created in the "working world" it is best practice to make such functions as setMin,setMax, etc
    statClass(vector<int> x)
    {
        myvector=x;
        size=x.size();
        vector<int>::iterator it=x.begin();
        min=*it;
        max=*it;
        modeCount=0;
        for(it;it!=x.end();++it)
        {
            total+=*it;
            if(*it>max)
                max=*it;
            if(*it<min)
                min=*it;
        }
        average=total/size;
    }
    statClass(list<int> x)
    {
        mylist=x;
        size=x.size();
        list<int>::iterator it=x.begin();
        min=*it;
        max=*it;
        for(it;it!=x.end();++it)
        {
            total+=*it;
            if(*it>max)
                max=*it;
            if(*it<min)
                min=*it;
        }
        average=total/size;
    }
    ~statClass()
    {
        myvector.clear();
        ModeInfo.clear();
        mylist.clear();
    }
    const int getMin()
    {return min;}
    const int getMax(){return max;}
    const float getAverage()
    {
        return average;
    }
    const int getTotal()
    {
        return total;
    }
    void setSize()
    {
        if(!myvector.empty())
            size=myvector.size();
        if(!mylist.empty())
            size=mylist.size();
    }
     void CalcModeInfoVector()
    {
        frequency=1;
        //vector <int> *modeVector=new vector<int>;
        vector<int> *copy=new vector<int>;
        *copy=myvector;
        for(vector<int>::iterator index=copy->begin();index!=copy->end();++index)
        {
            //finds possible modes and their respective frequencies
            for(vector<int>::iterator test=copy->begin();test!=copy->end();++test)
            {
                if(*index==*test & test!=index)
                {
                    frequency++;
                    copy->erase(test);
                    --test;
                }
            }
            if(frequency>1)
            {
                //pairs a possible mode with its frequency
                ModeInfo[*index]=frequency;
            }
            frequency=1;
        }
        if(!ModeInfo.empty())//if there is a mode then..
        {   
            //find the highest frequency
            //after setting default frequency at the first frequency location
            map<int, int>::iterator index=ModeInfo.begin();
            frequency=(*index).second;
            for(map<int, int>::iterator index=ModeInfo.begin();index!=ModeInfo.end();++index)
            {
                if((*index).second>frequency)
                    frequency=(*index).second;
            }
            //prints out all possible modes and their frequencies for proofing purposes
            /*cout<<"Mode/frequency pairs: "<<endl;
            for (map<int, int>::iterator it = ModeInfo.begin() ; it != ModeInfo.end(); ++it)
            {
                cout<<"Mode: "<<(*it).first<<" Frequency: "<<(*it).second<<endl;
            }
            cout<<endl<<endl;;
            */
            //finds mode
            for(index=ModeInfo.begin();index!=ModeInfo.end();++index)
            {
                 if((*index).second==frequency)
                 {
                     modeCount++;
                     cout<<(*index).first<<" ";
                 }
            }
        }
        else
        {
            cout<<"There is no mode with a frequency higher than 1."<<endl;
        }
        //cleanup
        copy->clear();
        delete copy;
    }
     void CalcModeInfoList()
    {
        list<int> *copy=new list<int>;
        *copy=mylist;
        int perLine=10,i=1;
        frequency=1;
        i=1;
        for(list<int>::iterator outside=copy->begin();outside!=copy->end();++outside)
        {
            //finds possible modes and their respective frequencies
            for(list<int>::iterator inside=copy->begin();inside!=copy->end();++inside)
            {
                if(*outside==*inside & inside!=outside)
                {
                    frequency++;
                    //copy->erase(inside);
                    //--inside;
                }
            }
            if(frequency>1)
            {
                //pairs a possible mode with its frequency
                ModeInfo[*outside]=frequency;
            }
            //resets frequency
            frequency=1;
        }
        if(!ModeInfo.empty())//if there is a mode then..
        {   
            //find the highest frequency
            //after setting default frequency at the first frequency location
            map<int, int>::iterator index=ModeInfo.begin();
            frequency=(*index).second;
            for(map<int, int>::iterator index=ModeInfo.begin();index!=ModeInfo.end();++index)
            {
                if((*index).second>frequency)
                    frequency=(*index).second;
            }
            //prints out all possible modes and their frequencies for proofing purposes
            /*cout<<"Mode/frequency pairs: "<<endl;
            for (map<int, int>::iterator it = ModeInfo.begin() ; it != ModeInfo.end(); ++it)
            {
                cout<<"Mode: "<<(*it).first<<" Frequency: "<<(*it).second<<endl;
            }
            cout<<endl<<endl;;
            */
            //finds mode
            for(index=ModeInfo.begin();index!=ModeInfo.end();++index)
            {
                 if((*index).second==frequency)
                 {
                     modeCount++;
                     cout<<(*index).first<<" ";
                 }
            }
        }
        else
        {
            cout<<"There is no mode with a frequency higher than 1."<<endl;
        }
        //cleanup
        copy->clear();
        delete copy;
    }
     int getFrequency()
     {
         return frequency;
     }
     int getModeCount()
     {return modeCount;}
};
#endif	/* STATCLASS_H */