#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

class Box
{
    private:
    int length,breadth,height=0;
    
    public:
    
    Box()       //default constructor
    {
       length=0,breadth=0,height=0; 
    }
    
    Box(int length1,int breadth1,int height1)  //parameterized constructor
    {
       length=length1;
       breadth=breadth1;
       height=height1; 
    }
    
    Box(const Box &p1) //copy constructor
    {
        length = p1.length; 
        breadth = p1.breadth; 
        height = p1.height;
    }
    
    int getLength()
    {
        return(length);
    }
    
    int getBreadth()
    {
        return(breadth);
    }
    
    int getHeight()
    {
        return(height);
    }
    
    long long CalculateVolume()
    {
        return(length*breadth*height);
    }
    
    friend bool operator<(Box& a,Box& b)
    {
        if((a.length<b.length)||((a.breadth<b.breadth)&&(a.length==b.length))||((a.height<b.height)&&(a.breadth==b.breadth)&&(a.length==b.length)))
        {
            return(true);
        }
        else
        {
            return(false);
        }
        
    }
    
    friend ostream& operator<<(ostream& out, Box& B)
    {
        out<<B.getLength()<<" "<<B.getBreadth()<<" "<<B.getHeight();
        return(out);
    }
};



void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}