#include<iostream>
#include<stdbool.h>

//Function prototype
bool is_prime(int);

using namespace std;

//main function
int main()
{
    //declaring variable a
    int a;
    cout<<"Enter a positive integer: ";
    cin>>a;

    //Initializing variables flag and i
    int flag=1;
    int i=a-1;

    //Looping as many times as half the number
    while(i>=(float)a/2)
    {
        //Calling the function is_prime
        if(is_prime(i))
        {
            if(is_prime(a-i))
            {
                flag=0;
                cout<<a<<" = "<<a-i<<" + "<<i<<"\n";
            }
        }
        i--;
    }

    if(flag)
    {
        cout<<"The Entered Number can't be expressed as Sum of Two Prime Numbers";
    }
    return 0;
}

//Defining function is_prime
bool is_prime(int n)
{
    if(n==1)
    {
        return false;
    }
    for(int i=2;i<=n/2;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}
