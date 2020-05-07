#include<iostream>
#include<iomanip>

using namespace std;

//defining class time
class time
{
public:
    //member variables
    int hh,mm,ss;

    //member functions
    void show_time()
    {
        //To display the time in specified format
        //00:00:00
        cout<<"The time is = "<<setfill('0')<<setw(2)<<hh<<":"<<setfill('0')<<setw(2)<<mm<<":"<<setfill('0')<<setw(2)<<ss<<endl;
    }
    void seconds()
    {
        //To display total time in seconds
        cout<<"Time in total seconds: "<<hh*60*60+mm*60+ss;
    }
};


int main()
{
    //Creating a time class object t
    time t;
    cout<<"Hours? ";
    cin>>t.hh;
    cout<<"Minutes? ";
    cin>>t.mm;
    cout<<"Seconds? ";
    cin>>t.ss;

    t.show_time();
    t.seconds();

    return 0;
}
