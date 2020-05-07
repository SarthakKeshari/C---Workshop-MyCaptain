#include<iostream>

using namespace std;

int main()
{
    //To declare an int string
    int ar[5];
    cout<<"Enter elements: ";

    //To loop over array to access each of its elements
    for(int i=0;i<=4;i++)
    {
        cin>>*(ar+i);
    }

    //To print each element of array
    cout<<"You entered: ";
    for(int i=0;i<=4;i++)
    {
        cout<<*(ar+i)<<endl;
    }
}
