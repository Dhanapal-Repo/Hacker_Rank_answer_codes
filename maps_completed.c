#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    map<string,int>my_map;
    int query_num=0,task=0,marks=0,pre_marks;
    string get_str; 
    map<string,int>::iterator itr; 
    
    cin>>query_num;//get total number of queries
    
    for(int i=0;i<query_num;i++)
    {
        cin>>task;
        switch(task)
        {
            case 1:
            cin>>get_str;
            cin>>marks;
            
            itr=my_map.find(get_str);
            
            if(itr==my_map.end())
            {
                my_map.insert(make_pair(get_str,marks));
            }
            else 
            {
               pre_marks = itr->second;
               marks=marks+pre_marks;
                itr->second=marks;
            }
           
            break;
            
            case 2:
            cin>>get_str;
            itr=my_map.find(get_str);
            itr->second=0;
            //my_map.erase(get_str);
            break;
            
            case 3:
            cin>>get_str;
            itr=my_map.find(get_str);
            
            if(itr==my_map.end())
            {
                cout<<"0"<<endl;
            }
            else
            {
                cout<<itr->second<<endl;
            }
            
            break;
            
            default:
            break;
        }
    }
    return 0;
}



