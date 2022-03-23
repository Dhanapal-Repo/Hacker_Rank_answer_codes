#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    vector<int> sort_num; 
    int store_val=0;
    int query_arr[2];
    cin>>store_val;

    //allocates memory for sorting
    int* ptr = (int*) malloc(store_val * sizeof(int));
    
    //check for memory allocated or not
    if (!ptr) 
    {
        cout << "Memory Allocation Failed";
        exit(1);
    }
  
  //prints sorted vector
    for(int i=0;i<store_val;i++)
    {
        cin>>ptr[i];
        sort_num.push_back(ptr[i]);
    }
    
    //first query input
    cin>>query_arr[0];

    sort_num.erase(sort_num.begin()+(query_arr[0])-1);
    cin>>query_arr[0];
    cin>>query_arr[1];

    sort_num.erase((sort_num.begin()+(query_arr[0])-1),(sort_num.begin()+(query_arr[1])-1));
    
    cout <<sort_num.size()<<endl;
    //prints erased vector
     for(int i=0;i<sort_num.size();i++)
    {
        cout << ""<<sort_num[i];
        cout << " ";
        
    }
    //deallocate assigned memory
    free(ptr);
   
    return 0;
}
