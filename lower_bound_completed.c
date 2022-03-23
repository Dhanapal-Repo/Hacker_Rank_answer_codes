#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    vector<int> sort_num; 
    int store_val=0;
    int num_query=0;
    // get how many number of integers to be sorted
    cin>>store_val;
    //allocates memory for sorting
    int* ptr = (int*) malloc(store_val * sizeof(int));

  //pushes data into the vector
    for(int i=0;i<store_val;i++)
    {
        cin>>ptr[i];
        sort_num.push_back(ptr[i]);
    }
    //vector sort operation
   // sort(sort_num.begin(),sort_num.end());
    //get how many number of queries
    cin>>num_query;
    //allocates memory for sorting
    int* ptr1 = (int*) malloc(num_query * sizeof(int));
    
    vector<int>::iterator low,up;
    for(int i=0;i<num_query;i++)
    {
        cin>>ptr1[i];
    }
    
    for(int i=0;i<num_query;i++)
    {
        low = lower_bound(sort_num.begin(), sort_num.end(), ptr1[i]);
        if (*(low + 1) == ptr1[i] || *low == ptr1[i])
        cout <<"Yes "<<(low-sort_num.begin()+1)<<endl;
        else
        cout <<"No "<<(low-sort_num.begin()+1)<<endl;
    }
    
    free(ptr);
    free(ptr1);
   
    return 0;
}
