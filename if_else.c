#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

const string num_array[10]=
{
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
};



int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));
    
    if(n<=9)
    {
        for(int i=1;i<=9;i++)
        {
            if(i==n)
            {
                cout<<num_array[i-1];
            }
        }
        
    }
    else {
    cout<<"Greater than 9";
    }
    

    // Write your code here

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
