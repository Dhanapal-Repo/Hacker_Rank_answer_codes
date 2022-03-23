int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    vector<int> sort_num; 
    int store_val=0;
    cin>>store_val;

    //allocates memory for sorting
    int* ptr = (int*) malloc(store_val * sizeof(int));
    
    //check for memory allocated or not
    if (!ptr) 
    {
        cout << "Memory Allocation Failed";
        exit(1);
    }
  
  //pushes data into the vector
    for(int i=0;i<store_val;i++)
    {
        cin>>ptr[i];
        sort_num.push_back(ptr[i]);
        //cout << " "<<ptr[i];
        
    }
	
    //vector sort operation
    sort(sort_num.begin(),sort_num.end());
    
	//prints sorted vector
     for(int i=0;i<store_val;i++)
    {
        cout << ""<<sort_num[i];
        cout << " ";
        
    }
    
    //deallocate assigned memory
    free(ptr);
   
    return 0;
}