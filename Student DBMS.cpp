
    #include<conio.h>
    #include<cstdio>
    #include<iostream>
    #include<iomanip>
    #include<string.h>
    #include<cstdlib>
    #include<windows.h>

    using namespace std;

    int main()
    {
        FILE *fp,*ft;
        char another, choice;

        struct student //Defining Structure
        {
            char first_name[50],last_name[50];
            char course[100];
            char mobno[10];
        };

        struct student e;
        char xfirst_name[50],xlast_name[50];
        long int recsize;

        fp=fopen("users.txt","rb+");

        if(fp==NULL) //To check if file is present then open it
        {
            fp=fopen("users.txt","wb+");

            if(fp==NULL)
            {
                puts("Cannot open file");
                return 0;
            }
        }

        recsize = sizeof(e);

        for(int i=0;i<50;i++) //For giving starting effect
        {
            system("cls");
            cout<<"Starting Project...";
            Sleep(2);
            if(i%4==0)
            {
                cout<<"\\";
            }
            else if(i%4==1)
            {
                cout<<"|";
            }
            else if(i%4==2)
            {
                cout<<"/";
            }
            else
            {
                cout<<"-";
            }
        }

        while(1) //To display menu to user
        {
            fflush(stdin);
            system("cls");
            cout<<"\t_________________________________________________\n";
            cout<<"\t|====== STUDENT DATABASE MANAGEMENT SYSTEM =====|\n";
            cout<<"\t'''''''''''''''''''''''''''''''''''''''''''''''''\n";
            cout<<"\t|\t\t\t\t\t\t|";
            cout<<"\n\t|\t\t1. Add Records\t\t\t|";
            cout<<"\n\t|\t\t2. List Records\t\t\t|";
            cout<<"\n\t|\t\t3. Modify Records\t\t|";
            cout<<"\n\t|\t\t4. Delete Records\t\t|";
            cout<<"\n\t|\t\t5. Exit Program\t\t\t|";
            cout<<"\n\t|\t\t\t\t\t\t|\n";
            cout<<"\t|_______________________________________________|\n\n";
            cout<<"\t\tSelect Your Choice:> ";
            fflush(stdin);
            cin>>choice;
            switch(choice)
            {
            case '1':
            	fflush(stdin);
                fseek(fp,0,SEEK_END);
                another = 'Y';
                while(another == 'Y' || another == 'y') //For taking new entry of records
                {
                    system("cls");
                    cout<<"\n\t|==========<<<<<<<<< NEW RECORD >>>>>>>>>========|\n";
                    cout<<"\t--------------------------------------------------\n";
                    cout<<"\t|\n";
                    cout<<"\t|Enter following details - \n";
                    cout<<"\t|  > First Name : ";
                    cin>>e.first_name;
                    cout<<"\t|  > Last Name : ";
                    cin>>e.last_name;
                    cout<<"\t|  > Course Name : ";
                    cin>>e.course;
                    cout<<"\t|  > Mobile Number : ";
                    cin>>e.mobno;
                    cout<<"\t|_________________________________________________\n";
                    fwrite(&e,recsize,1,fp);
                    cout<<"\n\nAdd Another Record(Y/N)? -> ";
                    fflush(stdin);
                    cin>>another;
                }
                break;
            case '2': //For displaying records
            	fflush(stdin);
                system("cls");
                rewind(fp);
                cout<<"\n|====================================<<<<<<<<<<< RECORDS >>>>>>>>>>====================================|\n";
                cout<<"---------------------------------------------------------------------------------------------------------\n";
                cout<<"\n";
                cout<<setw(10)<<"|"<<setw(15)<<"First Name"<<setw(6)<<"|"<<setw(15)<<"Last Name"<<setw(6)<<"|"<<setw(15)<<"Course"<<setw(6)<<"|"<<setw(15)<<"Mobile Number"<<setw(7)<<"|\n";
                while(fread(&e,recsize,1,fp)==1)
                {
                    cout<<"\n\n";
                    cout<<setw(10)<<"|"<<setw(20)<<e.first_name<<"|"<<setw(20)<<e.last_name<<"|";
                    cout<<setw(20)<<e.course<<"|"<<setw(20)<<e.mobno<<"|";
                }
                cout<<"\n\n";
                system("pause");
                break;
            case '3': //for making changes in pre-registered record
            	fflush(stdin);
                system("cls");
                another='Y';
                while(another == 'Y' || another == 'y')
                {
                    int flag=1;
                    cout<<"\n\t| Enter last name of the student: ";
                    cin>>xlast_name;
                    cout<<"\t|____________________________________________________\n\n";

                    rewind(fp);
                    while(fread(&e,recsize,1,fp)==1)
                    {
                        if(strcmp(e.last_name,xlast_name)==0)
                        {

                            cout<<"\n\t|==========<<<<<<<<< MODIFY RECORD >>>>>>>>>========|\n";
                            cout<<"\t-----------------------------------------------------\n";
                            cout<<"\t|\n";
                            cout<<"\t|Enter new details - \n";
                            cout<<"\t| > First Name : ";
                            cin>>e.first_name;
                            cout<<"\t| > Last Name : ";
                            cin>>e.last_name;
                            cout<<"\t| > Course Name: ";
                            cin>>e.course;
                            cout<<"\t| > Mobile Number : ";
                            cin>>e.mobno;
                            fseek(fp,- recsize,SEEK_CUR);
                            fwrite(&e,recsize,1,fp);
                            flag=0;
                            break;
                        }

                    }
                    if(flag==1)
                    {
                        cout<<"\n\tRecord NOT FOUND!!!!";
                    }
                    cout<<"\n\n Modify Another Record(Y/N)? -> ";
                    fflush(stdin);
                    cin>>another;
                    system("cls");
                }
                break;

            case '4': //To delete a record
            	fflush(stdin);
                system("cls");
                another = 'Y';
                while(another == 'Y' || another == 'y')
                {
                    cout<<"\n\t|Enter the last name of the student to delete : ";
                    cin>>xlast_name;
                    cout<<"\t|________________________________________________________________";

                    ft = fopen("temp.dat","wb");
                    int flag=1;
                    rewind(fp);
                    while(fread(&e,recsize,1,fp)== 1)
                    {
                        if(strcmp(e.last_name,xlast_name)!= 0)
                        {
                            fwrite(&e,recsize,1,ft);
                        }
                        else
                        {
                            flag=0;
                            cout<<"\n\n\t\tRecord Deleted SUCCESSFULLY!!!";
                        }
                    }
                    fclose(fp);
                    fclose(ft);
                    remove("users.txt");
                    rename("temp.dat","users.txt");

                    fp=fopen("users.txt","rb+");
                    if(flag)
                    {
                        cout<<"\n\n\t\t\tRecord NOT found!!!!";
                    }
                    cout<<"\n\n\n\n Delete Another Record (Y/N)? -> ";
                    fflush(stdin);
                    cin>>another;
                    system("cls");
                }
                break;
            case '5': //Exit Lines
                fclose(fp);
                cout<<"\n\n";
                cout<<"\t\t THANK YOU FOR USING OUR SERVICE ^_^";
                cout<<"\n\n";
                exit(0);
            }
        }

        system("pause");
        return 0;
    }

