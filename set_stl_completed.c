#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
 
    set<int>set_list; //Creates a set of integers.  
    int element_num=0,i=0,query[2];
    set<int>::iterator itr;
    
    cin>>element_num;//gets number of set element queries
    
    for(i=0;i<element_num;i++)
    {
        cin>>query[0];
        cin>>query[1];
        switch(query[0])
        {
            case 1:
            set_list.insert(query[1]); //Inserts an integer query[1]to set.
            break;
            case 2:
                itr=set_list.find(query[1]);
                if(itr==set_list.end())
                {
                    //do nothing
                }
                else
                set_list.erase(query[1]); //Erases an integer val from the set.
            break;
            case 3:
                itr=set_list.find(query[1]);
                if(itr==set_list.end())
                cout<<"No"<<endl;
                else
                cout<<"Yes"<<endl;
            
            break;
            default:
            break;
        }
    }
        
        
        
    return 0;
}



