#include <cmath>
#include <cstdio>
#include <map>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;


string tag_name,value_name;
//map<string,string> query_map;
struct hrml_val
{
    string attribute;
    string value;
};

void split(string str, char del,char del2){
    // declaring temp string to store the curr "word" upto del
      string temp = "",pre_temp;
      
   
      for(int i=0; i<(int)str.size(); i++)
      {
        // If cur char is not del, then append it to the cur "word", otherwise
          // you have completed the word, print it, and start a new word.
        if((str[i] != del)&&(str[i] != del2))
        {
            temp += str[i];
        }
        else
        {
            pre_temp=temp;
            temp="";
        }
        
        if(str[i] == del2)
        {
            tag_name=pre_temp;
            //cout << tag_name;
        }
    }
       
      value_name=temp;
      
     // cout<<tag_name;
     // cout << value_name;
      
     // query_map.insert(pair<string, string>(tag_name, value_name));
      // 
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int line=0,query=0,i=0;
    string s,tag,attr,val;
    uint8_t tag_flag=0,loop_flag=0;
    hrml_val new_one;
    map<string,hrml_val> hrml;
     
    cin>>line>>query; // get values of query and hrml lines
    cin.ignore();      //clear the cin buffer for whitespace
    
    for(i=0;i<line;i++)
    {
        getline(cin,s);
        stringstream line(s);
        while(line>>s)
        {
            if(s[0]=='<')
            {
                if(s[1]=='/')
                {
                    //cout<<s<<endl;
                }
                else
                {
                    s.erase(remove(s.begin(), s.end(), '<'), s.end());
                    tag=s;
                }   
            }
            else if((s[0]!=' '&&s[0]!='"'&&s[0]!='='))
            {
                new_one.attribute=s;
            }
            else if (s[0] == '"')
            {
                s.erase(remove(s.begin(), s.end(), '"'), s.end());
                s.erase(remove(s.begin(), s.end(), '>'), s.end());
                new_one.value=s;
                tag_flag=1;
            }
            
            
            if(tag_flag==1)
            {
                tag_flag=0;
                hrml.insert(pair<string, hrml_val>(tag, new_one));
            }
            
        }
    }
    

    for(i=0;i<query;i++)
    {
        getline(cin,s);
        split(s, '.','~');
        map<string, hrml_val>::iterator itr;
        for (itr = hrml.begin(); itr != hrml.end(); ++itr)
        {
           if((itr->first==tag_name)&&(itr->second.attribute==value_name))
           {
               loop_flag=0;
               cout<<itr->second.value<<endl;
               break;
           }
           else
           {
               loop_flag=1;
           }
        }
       
        if(loop_flag==1)
        {
            loop_flag=0;
            cout<<"Not Found!"<<endl;            
        }
        
    }
    
     return 0;
}
