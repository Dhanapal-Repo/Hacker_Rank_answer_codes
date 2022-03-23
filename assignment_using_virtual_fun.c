/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

string layerType2="layer_name";
int kernelHeight2=0;
int kernelWidth2=0;
int h,w=0;

void disp_krnl_val(void);

// base class
class layer{
    private:

    string layerType; // layer types eg.convolution,pooling..etc
    int kernelHeight; //kernal height of an image
    int kernelWidth;  //kernal weight of an image

    public:
     layer(string layerType1,int kernelHeight1,int kernelWidth1)//constructor
     {
          layerType= layerType1;
          kernelHeight= kernelHeight1;
          kernelWidth= kernelWidth1;
     }

    virtual void UpdateWeights(int h1,int w1)//update weight func
    {

    }

    virtual void displayParams(int h1,int w1)//display all parameters func
    {

    }

    int get_krnl_higt()
    {
        return(kernelHeight);
    }

     int get_krnl_widt()
    {
        return(kernelWidth);
    }
};

//devired class 1
class conv:public layer
{
    private:
    string layerName;
    vector<float> weights;

    public:
    conv(string layerName1):layer(layerType2, kernelHeight2, kernelWidth2)//constructor
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
   private:
  string layerName;
  vector<float> weights;
  string pool_Type;

  public:
    pool(string layerName1,string pool_Type1):layer(layerType2, kernelHeight2, kernelWidth2)//constructor
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

    upscale(string layerName1,int scale_factor1):layer(layerType2, kernelHeight2, kernelWidth2)
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
        return 0;
    }

    layer *layer_obj;                           // layer class pointer obj for virtual function
    conv conv_obj("conv");                      // conv class obj
    pool pool_obj("pool",s);                    // pool class obj
    upscale upscale_obj("upscale",2);           //upscale class obj

    //UpdateWeights called for each class with different weights using virtual class
    layer_obj=&conv_obj;
    layer_obj->UpdateWeights(h,w);
    layer_obj->displayParams(h,w);

    layer_obj=&pool_obj;
    layer_obj->UpdateWeights(h,w);
    layer_obj->displayParams(h,w);

    layer_obj=&upscale_obj;
    layer_obj->UpdateWeights(h,w);
    layer_obj->displayParams(h,w);

    return 0;
}

void disp_krnl_val(void)
{
    layer store_obj("layer_name",h,w);          //layer class obj

    cout<<"kernelHeight= "<<store_obj.get_krnl_higt()<<endl;
    cout<<"kernelWidth= "<<store_obj.get_krnl_widt()<<endl;
}
