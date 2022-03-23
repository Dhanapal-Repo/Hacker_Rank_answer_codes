/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

string layerType1="layer_name";
int kernelHeight1=0;
int kernelWidth1=0;

void disp_krnl_val(void);

// base class
class layer{
    public:
    
    string layerType; // layer types eg.convolution,pooling..etc
    int kernelHeight=0; //kernal height of an image
    int kernelWidth=0;  //kernal weight of an image
    
     layer(string layerType,int kernelHeight,int kernelWidth)//constructor
     {
          layerType1= layerType;
          kernelHeight1= kernelHeight;
          kernelWidth1= kernelWidth; 
     }
    
    void UpdateWeights(int h1,int w1)//update weight func
    {
        
    }
    
    void displayParams(int h1,int w1)//display all parameters func
    {
        
    }
};

//devired class 1
class conv:public layer
{
    public:
    string layerName;
    vector<float> weights;
    
    conv(string layerName1):layer(layerType1, kernelHeight1, kernelWidth1)//constructor
    {
      layerName= layerName1;
    }
    
    void UpdateWeights(int h1,int w1)
    {
        for (int i = 0; i < (h1*w1); i++)
        weights.push_back(1);
    }
    
    void displayParams(int h1,int w1)
    {
        int temp=0;
        cout<<endl<<"**********conv_layer**********"<<endl;
        disp_krnl_val();
        
        for(int i=0;i<h1;i++)
        {
            for(int j=temp;j<(w1+temp);j++)
            {
                cout<<weights[j]<<" ";
            }
            cout<<endl;
            temp+=w1;
        }
       
    }
    
    
};
//devired class 2
class pool:public layer
{
    public:
  string layerName;	
  vector<float> weights;   
  string pool_Type;
  
    pool(string layerName1,string pool_Type1):layer(layerType1, kernelHeight1, kernelWidth1)//constructor
    {
         layerName= layerName1;
         pool_Type=pool_Type1;
    }
    
    void UpdateWeights(int h1,int w1)
    {
        for (int i = 0; i < (h1*w1); i++)
        {
            if(i==0)
                weights.push_back(1);
            else
                weights.push_back(0);
                
        }
        
    }
    
     void displayParams(int h1,int w1)
    {
        int temp=0;
        cout<<endl<<"**********pool_layer**********"<<endl;
        disp_krnl_val();
        
        for(int i=0;i<h1;i++)
        {
            for(int j=temp;j<(w1+temp);j++)
            {
                cout<<weights[j]<<" ";
            }
            cout<<endl;
            temp+=w1;
        }
        
        cout<<"pool_type= "<<pool_Type<<endl;
    }
    
};
//devired class 3
class upscale:public layer
{
    public:
    string layerName;	
    vector<float> weights;   
    int scale_factor;
    
    upscale(string layerName1,int scale_factor1):layer(layerType1, kernelHeight1, kernelWidth1)
    {
         layerName= layerName1;
         scale_factor=scale_factor1;
    }
    
    void UpdateWeights(int h1,int w1)
    {
        for (int i = 0; i < (h1*w1); i++)
        {
            if(i==0)
                weights.push_back(1);
            else
                weights.push_back(0);
        }
    }
    
     void displayParams(int h1,int w1)
    {
        int temp=0;
        cout<<endl<<"**********upscale_layer**********"<<endl;
        disp_krnl_val();
        
        for(int i=0;i<h1;i++)
        {
            for(int j=temp;j<(w1+temp);j++)
            {
                cout<<weights[j]<<" ";
            }
            cout<<endl;
            temp+=w1;
        }
        
        cout<<"scale_factor= "<<scale_factor<<endl;
    }
};


int main()
{
    int pool_data;
    int h,w=0;
    string s;
    
    cout<<"Enter kernal data"<<endl;            // user input for layer name and kernal width and height
    cout<<"Enter Height : ";
    cin>>h;                                     //get height data
    cout<<"Enter width : ";
    cin>>w;                                     //get width data
    
    cout<<"Entered Weight Matrix is : "<<h<<"x"<<w<<endl;
    cout<<"Total Weight is : "<<h*w<<endl;      //total number of element in matrix
    
    cout<<"Enter Pool type"<<endl;            // user input for pool type
    
    cout<<"Please Enter [1] for Max Pooling and Press [2] for Average Pooling : ";
    cin>>pool_data;
    
    if(pool_data==1)
    {
        cout<<"Max Pool type Chosen"<<endl;
        s="Max Pooling";
    }
    else if(pool_data==2)
    {
        cout<<"Average Pool type Chosen"<<endl;
        s="Average Pooling";
    }
    else
    {
        cout<<"Incorrect input, Please try again"<<endl;
        exit(0);
    }
    
    layer layer_obj("layer_name",h,w);          // layer class obj
    conv conv_obj("conv");                      // conv class obj
    pool pool_obj("pool",s);                // pool class obj
    upscale upscale_obj("upscale",2);           //upscale class obj

    //UpdateWeights called for each class with different weights
    conv_obj.UpdateWeights(h,w);
    pool_obj.UpdateWeights(h,w);
    upscale_obj.UpdateWeights(h,w);

    //displayParams func Displays all parameters
    conv_obj.displayParams(h,w);
    pool_obj.displayParams(h,w);
    upscale_obj.displayParams(h,w);
    
    
    return 0;
}

void disp_krnl_val(void)
{
    cout<<"kernelHeight= "<<kernelHeight1<<endl;
    cout<<"kernelWidth= "<<kernelWidth1<<endl;
}