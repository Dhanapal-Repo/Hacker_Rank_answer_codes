#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int proff_id =0;
int stud_id =0;
class Person
{
    private:
         string name;
         int age;
        
    public:
    
    Person()
    {
        
    }
    
    
    virtual void getdata()
    {
        
    }
    
    virtual void putdata()
    {
        
    }
    
    void set_name(string s1)
    {
        name=s1;
    }
    
    void set_age(int i1)
    {
        age=i1;
    }
    
    string ret_name()
    {
        return(name);
    }
    
    int ret_age()
    {
        return(age);
    }
    
};

class Professor:public Person
{
    private:
        int publications,cur_id=0;
        
    public:
    Professor()
    {
        
    }
        void getdata()
        {
            string s;
            int a,i=0;
            cin>>s>>a;
            set_name(s);
            set_age(a);
            cin >> a;
            publications=a;
            proff_id++;
            cur_id=proff_id;
        }
        
        void putdata()
        {
          cout<<ret_name()<<" "<<ret_age()<<" "<<publications<<" "<<cur_id<<endl;
        }
    
};

class Student:public Person
{
    private:
        int marks[6],cur_id=0;
        
    public:
    Student()
    {
        
    }
        void getdata()
        {
           string s;
           int a,i=0;
           
            cin>>s>>a;
            set_name(s);
            set_age(a);
            stud_id++;
            cur_id=stud_id;
           
           for(i=0;i<6;i++)
           {
               cin>>a;
               marks[i]=a;
           }
            
        }
        
        void putdata()
        {
            int res=0;
            string s;
            for(int i=0;i<6;i++)
            {
               res+=marks[i];
            }
            
            cout<<ret_name()<<" "<<ret_age()<<" "<<res<<" "<<cur_id<<endl;
            
        }
    
};


int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
