#include<iostream>

using namespace std;

int main()
{
    //To declare variable age
    int age;
    cout<<"Enter your age: ";
    //To take user input for age
    cin>>age;

    //Decision making statement to check
    //if the user is eligible to vote or not

    if(age>=18)
    {
        cout<<"You are eligible to vote.";
    }
    else
    {
        cout<<"You are NOT eligible to vote.";
    }
    return 0;
}
