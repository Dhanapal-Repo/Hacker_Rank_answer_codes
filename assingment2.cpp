#include<iostream>
#include<iterator>
#include<map>
#include <fstream>

using namespace std;

/******************************************************CLASS*******************************************************/

class layer                                             //base class
{               
    private:                                            // declared under private for abstraction
                
    string layerType;                                   // layer types eg.convolution,pooling..etc
    int stride;                                         // stride of an image
    int kernelHeight;                                   // kernal height of an image
    int kernelWidth;                                    // kernal weight of an image

    public:
    
    layer(string layerType1,int stride1,int kernelHeight1,int kernelWidth1) //parameterized constructor
    {
        layerType=layerType1;     
        stride=stride1;           
        kernelHeight=kernelHeight1;     
        kernelWidth=kernelWidth1;      
    }
    
    string get_layer_name()                             // function get layertype name
    {               
        return(layerType);              
    }               

    int get_stride()                                    // function get stride value
    {               
        return(stride);             
    }               

    int get_kernelHeight()                              // function get kernal height
    {               
        return(kernelHeight);               
    }               

    int get_kernelWidth()                               // function get kernal width
    {
        return(kernelWidth);
    }
};

/******************************************************Main*******************************************************/
int main(int argc, char** argv)
{
    int i=0,ly_parm[3],flag=0,k=2,j=0,a,b,c;            //local variables
    map<string,layer> layer_map;                        // creating a map for layer parameters
    map<string,layer>::iterator itr;                    //creating iterator for map
    fstream inp_file;                                   // fstream variable to read an input from a file 
    string file_name="file.txt",inp_layer_nm,str;
 
    /*********input file Read section************/
    inp_file.open(file_name.c_str(),ios::in);           //open a file to perform read operation using file object
    
    if(inp_file.is_open())                              //checking whether the file is open
    { 
        cout<<"You have entered "<<argv[1]<<" layers"<<endl;//prints how many layers are entered
        for(i=2;i<argc;i++)
        {
            cout<<argv[i]<<endl;                            //prints which layers are entered
        }
        
      while(inp_file >> str)                            //read data from file by text by text and put it into string.
      {
        i = atoi(str.c_str());                          //using atoi function to convert string to integer , 
            if(i==0)                                    //as atoi only accepts char as input so we converted string to char by c.str()
            {
                inp_layer_nm=str;                       // if string is not equal to a number, variable 'i' will give 0
            }
            else
            {
                ly_parm[j]=i;                           // if string is equal to a number, variable 'i' will give integer from file
                j++;
            }
            
            if(j==3)                                    // to check all values are readed from a line
            {
                a=ly_parm[0];
                b=ly_parm[1];
                c=ly_parm[2];
                
                layer obj1(inp_layer_nm,a,b,c);         // store all data in the constructor ,after reading one line
                
                layer_map.insert(pair<string, layer>(argv[k], obj1));//make map pairs of names and classes
                k++;
                j=0;
                
            }else{}
        }
    }
    else
    {
        cerr<<"No Input file detected,Please provide "<<file_name<<" to continue"<<endl;
        return(0);
    }
   
   inp_file.close();                                    //close the file object.
   
   /*********parameters display section************/
   for (itr = layer_map.begin(); itr != layer_map.end(); ++itr)   //to display all parameters using map iterator
    {
        cout<<endl;
        cout << itr->first<<" "<<itr->second.get_layer_name();  //to display values using class get functions
        cout <<" "<<itr->second.get_stride();
        cout <<" "<<itr->second.get_kernelHeight();
        cout <<" "<<itr->second.get_kernelWidth()<<endl;
    }
    cout << endl;
    
    return(0);
}
/******************************************************End of File*******************************************************/
