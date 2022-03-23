#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
    vector<int> val;
    stringstream ss(str);
    int arr[str.size()],i=0;
    char ch;
    
    while (!ss.eof())
    {
        ss>>arr[i]>>ch;
        val.push_back(arr[i]);
        i++;
    }
    
    
    return(val);
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}