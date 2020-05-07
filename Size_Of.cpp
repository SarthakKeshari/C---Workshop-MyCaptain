#include<iostream>

using namespace std;

int main()
{
    //cout is for printing the required word,sentence or number on console

    //The sizeof is a keyword, but it is a compile-time operator that
    //determines the size, in bytes, of a variable or data type.

    cout<<"Size of char: "<<sizeof(char)<<" byte\n";
    cout<<"Size of int: "<<sizeof(int)<<" bytes"<<endl;
    cout<<"Size of float: "<<sizeof(float)<<" bytes"<<endl;
    cout<<"Size of double: "<<sizeof(double)<<" bytes"<<endl;
    return 0;
}
