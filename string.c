#include <iostream>
#include <string>
using namespace std;

int main() {
	// Complete the program
    string a,b,temp="";
    cin>>a>>b;
    
    cout<<a.size()<<" "<<b.size()<<endl<<a+b<<endl;
    a[0]=a[0]^b[0];
    b[0]=b[0]^a[0];
    a[0]=a[0]^b[0];
    cout<<a<<" "<<b;
    return 0;
}
