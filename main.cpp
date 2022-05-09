/* AIRLINES RESERVATION SYSTEM
  MENU DRIVEN USING FILE HANDLING
  
 
               
                                 IMPORTANT  INSTRUCTIONS
                                 
USER ID AND PASSWORD HAS TO BE GENERATED USING USER MANAGEMENT OPTION IN ADMIN MODE.
WHILE RUNNING THIS CODE FIRST TIME ON ANY IDE FIRST CREATE DETAILED AIRLINES DATABASE IN ADMIN MODE TO AVOID COMPILATION ERROR.
CODE AND FILES SHOULD BE IN THE SAME FOLDER OTHERWISE DATA WILL NOT BE STORED PROPERLY.   */

// header files used

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>   
#include <time.h> 
using namespace std;

char B[10] = "B";
char E[10] = "E";
int addr, ad, flag, f1, d, m, i, amt;
float tamt;

class login              // class login  for login id and password
{
public:
char id[100];
char pass[100];
char password[10];

void getid()           // method function of class login to get user id and password
{
cout << "\nEnter your id:";
std::cin >> id;
std::cout << "Enter the Password: ";
std::cin >> password;
std::cout << "\n";
strcpy(pass,password);
}

void displayid()          // method function of class login to display id and password
{
    std::cout << "\n|" << "User ID:" << "\t" << "|" << "Password\n";
std::cout << "|" << id << "\t\t" << "|" << pass << "\n\n";
}

};

class Detail          // class detail for flight details
{
public:
int flight_no;
char flight_name[100];
char bp[100];
char dest[100];
int B,Bfare;
int E,Efare;
int d,m,y; 


void getDetail()    // method function of class detail to get flight details
{
std::cout << "\n--Add New details--\n";
std::cout << "FLIGHT no: ";
std::cin >> flight_no;
std::cout << "FLIGHT Name: ";
std::cin >> flight_name;
std::cout << "Boarding point: ";
std::cin >> bp;
std::cout << "Destination pt: ";
std::cin >> dest;
std::cout << "No of seats in BUSINESS class & fare per ticket: ";
std::cin >> B >> Bfare;
std::cout << "No of seats in ECONOMY class & fare per ticket: ";
std::cin >> E >> Efare;
std::cout << "Date of travel\n";
std::cout << "Day: ";
std::cin >> d;
std::cout << "Month: ";
std::cin >> m;
std::cout << "Year: ";
std::cin >> y;
}

void displaydetail()      // method function of class detail to display flight details
{
    std::cout << "\n|FLIGHT No." << "\t" << "|FLIGHT Name" << "\t" << "|Boarding pt." << "\t" << "|Destination pt."  <<"\t";
std::cout << "|B-Class" << "\t"<< "|B-Class Fare" << "\t" << "|E-Class" << "\t" << "|E-Class Fare" <<"\t" ;
std::cout << "|Day" << "-" << "Month" << "-" << "Year" << "\n";
 
std::cout << "|" << flight_no << "\t\t" << "|" << flight_name << "\t\t" << "|" << bp << "\t\t" << "|" << dest <<"\t\t\t";
std::cout << "|" << B << "\t\t" << "|"<< Bfare << "\t\t" << "|" << E<< "\t\t" << "|" << Efare <<"\t\t"  ;
std::cout << "|" << d << "-" << m << "-" << y << "\n";
}
};

class reser    // class reser for reservation of passengers
{
public:
int pnr;
int flight_no;
char flight_name[100];
char bp[100];
char dest[100];
char pname[10][100];
int age[20];
char clas[10];
int no_seats;
int i;
int d,m,y;
int con;
float amt_pay;
int mob[20];
int aadhar_no[20];
char gender;

void getresdet()     // method function of class reser to get passengers details
{
cout<<"Enter the details as follows\n";
cout<<"\nFLIGHT no:";
cin>>flight_no;
cout<<"\nFLIGHT name:";
cin>>flight_name;
cout<<"\nBoarding point:";
cin>>bp;
cout<<"\nDestination pt:";
cin>>dest;
cout<<"\nNo of seats required:";
cin>>no_seats;
for(i=0;i<no_seats;i++)
{
cout<<"\nPassenger name:";
std::cin >> pname[i];
cout<<"\nPassenger age:";
std::cin>>age[i];
cout << "\nMobile No.:  ";
std::cin >> mob[i];
cout << "\nAadhar No.:  ";
std::cin >> aadhar_no[i];
cout << "\nGender M or F :  ";
std::cin >> gender;
}
cout<<"\nEnter the class B-Business class E-Economy class:";
std::cin >> clas;
cout<<"\nDate of travel:";
std::cin>>d>>m>>y;
cout<<"Enter the concession category:\n";
cout<<"1.Military\n2.Senior citizen\n";
cout<<"3.Children below 5 yrs\n4.None\n";
std::cin>>con;
cout<<"    END OF GETTING DETAILS      \n";
cout<<"\n";
}

void displayresdet()       // method function of class reser to display reserved passengers details
{
cout<<"Pnr no: "<<pnr;
cout<<"\nFLIGHT no: "<<flight_no;
cout<<"\nFLIGHT name: "<<flight_name;
cout<<"\nBoarding point: "<<bp;
cout<<"\nDestination pt: "<<dest;
cout<<"\nNo of seats reserved: "<<no_seats;
for(i=0;i<no_seats;i++)
{
   cout<<"\nPassenger name: ";puts(pname[i]);
   cout<<"\nPassenger age: "<<age[i];
   cout <<"\nMobile No.:  "<<mob[i];
   cout<<"\nAadhar No.: "<<aadhar_no[i];
   cout<<"\nGender: "<<gender; 
}
cout<<"\nYour class: ";puts(clas);
cout<<"\nDate of reservation: "<<d<<"-"<<m<<"-"<<y;
cout<<"\nYour concession category: "<<con;
cout<<"\nYou must pay: "<<amt_pay<<endl;
cout<<"***********************************\n";
}
};

class canc          // class canc to cancel reseved tickets
{
    public:
    int pnr;
    int flight_no;
    char flight_name[100];
    char bp[100];
    char dest[100];
    char pname[10][100];
    int age[20];
    int i;
    int mob[20];
    int aadhar_no[20];
    char clas[10];
    int no_seats_can;
    int d, m, y;
    char gender;
    float amt_returned;
    
void getcancdet()     // method function of class canc to get ticket details
{
    std::cout << "Enter the details as follows\n";
    std::cout << "\nPnr no:";
    std::cin >> pnr;
    std::cout << "\nDate of cancellation:";
    std::cin >> d >> m >> y;
    std::cout << "     END OF GETTING DETAILS     \n";
    cout <<"\n";
}
void displaycancdet()   // method function of class canc to display cancelled tickets details
{
    std::cout << "\n";
    std::cout << "Pnr no:" << pnr;
    std::cout << "\nFLIGHT no:" << flight_no;
    std::cout << "\nFLIGHT name:";
    std::cout << flight_name;
    std::cout << "\nBoarding point:";
    std::cout << bp;
    std::cout << "\nDestination pt:";
    std::cout << dest;
    std::cout << "\nYour class:";
    std::cout << clas;
    std::cout << "\nNo. of seats to be cancelled:" << no_seats_can;
    for (i = 0; i < no_seats_can; i++)
    {
        std::cout << "\nPassenger name:";
        std::cout << pname[i];
        std::cout << "\npassenger age:" << age[i];
    }
    std::cout << "\nDate of cancellation:" << d << "-" << m << "-" << y;
    std::cout << "\nYou can collect:" << amt_returned << "RS." << endl;
    std::cout <<" \n";
    std::cout << "*****************************************\n";
    std::cout << "    END OF CANCELLATION    \n";
    std::cout << "*****************************************\n";
    }
};

// FUNCTION PROTOTYPE DECLARATION 
// FUNCTIONS TO BE CALLED IN MAIN FUNCTION
void manage();
void can();
void user();
void database();
void res();
void reserve();
void displaypassdetail();
void cancell();
void enquiry();

int main(void)     // MAIN FUNCTION
{
int ch;
std::cout <<"********************************************\n";
std::cout << "----- AIRLINES RESERVATION SYSTEM ----- \n";
std::cout <<"********************************************\n";
do
{
std::cout << "\n MAIN MENU \n";
std::cout << "1.Admin mode\n2.User mode\n3.Exit \n";
std::cout << "Enter your choice : ";
std::cin >> ch;

switch(ch)
{
case 1:
database();  // function called for admin mode
break;

case 2:
user();      // function called for user mode
break;

default:
exit(0);    // exit

}
}while(ch<3);
return 0;
}

// function definition
void database()   //  used in admin mode
{
char password[10];
char pass[10] = "admin";
std::cout << "\nEnter the Admin Password: ";  // asking for password
std::cin >> password;
Detail a;
fstream f;
int ch;
char c;
if(strcmp(pass,password)!=0)  // if admin  password doesnot match
{
std::cout << "Enter the password correctly \n";
std::cout << "You are not permitted to login this mode\n";
}
if(strcmp(pass,password)==0)  // if admin password matches
{
char c;
do
{
std::cout << "\n --- ADMINISTRATOR MENU --- \n";      // menu of admin mode
std::cout << "1. Create detailed Airlines Database \n";
std::cout << "2. Add details in database \n";
std::cout << "3. Display details of database \n";
std::cout << "4. User Management \n";
std::cout << "5. Diplay Passenger details \n";
std::cout << "6. Return to Main Menu \n";
std::cout << "Enter your choice : ";
std::cin >> ch;
 
switch(ch)
{
case 1:         // to create detailed airlines database
f.open("t.txt",ios::out|ios::binary); //file opened to write flight details in binary mode
do
{
a.getDetail();
f.write((char *) & a,sizeof(a));
cout << "\nDo you want to add one more record?\n";
cout << "y-for Yes\nn-for No\n";
cin >> c;
}while(c=='y');
f.close();
break;

case 2:     // to add flight details in detailed airline database
f.open("t.txt",ios::in|ios::out|ios::binary|ios::app);
a.getDetail();
f.write((char *) & a,sizeof(a));
f.close();
break;

case 3:    // to display flight details
f.open("t.txt",ios::in|ios::out|ios::binary|ios::app);
f.seekg(0);
while(f.read((char *) & a,sizeof(a)))
{
a.displaydetail();
}
f.close();
break;

case 4:   // to manage user id and password
manage();
break;

case 5:   // to display details of reserved passengers
displaypassdetail();
break;
}
}while(ch<=5);
}
}

// function definition
void reserve()    // confirming if reserving flight tickets demanded
{
    int ch;
    do
    {   std::cout<<"\n";
	    std::cout << "KINDLY VISIT ENQUIRY TO LOOK FOR AVAILABLE FLIGHTS AND DATES.\n";
        std::cout << "1.Reserve\n2.Return to the main menu\n";
        std::cout << "Enter your choice:";
        std::cin >> ch;
        std::cout << endl;
        switch (ch)
        {
        case 1:
            res();
            break;
        }
    } while (ch == 1);
}
 
void res()  // to reserve flight tickets
{
    Detail a;
    reser b;
    fstream f1, f2;
    time_t t;
    f1.open("t.txt", ios::in | ios::out | ios::binary);
    f2.open("p.txt", ios::in | ios::out | ios::binary | ios::app);   // file opened for reserved passenger details
    int ch;
    b.getresdet();
    while (f1.read((char *)&a, sizeof(a)))
    {  // ticket will be booked if entered flight no matches airlines database
        if (a.flight_no == b.flight_no)  
        {
            if (strcmp(b.clas, B) == 0)  // for bussiness class
            {
                if (a.B >= b.no_seats)  // if seats required of business class are available.
                {
                    amt = a.Bfare;
                    addr = f1.tellg();
                    ad = sizeof(a.B);
                    f1.seekp(addr - (7 * ad));
                    a.B = a.B - b.no_seats;
                    f1.write((char *)&a.B, sizeof(a.B));
                    // concession criteria in ticket amount of business class
                    if (b.con == 1)
                    {
                        cout << "Concession category:MILITARY PERSONNEL\n";
                        b.amt_pay = b.no_seats * ((amt * 50) / 100);  // 50 % concession
                    }
                    else if (b.con == 2)
                    {
                        cout << "Concession category:SENIOR CITIZEN\n";
                        b.amt_pay = b.no_seats * ((amt * 60) / 100);   // 60% concession
                    }
                    else if (b.con == 3)
                    {
                        cout << "Concession category:CHILDERN BELOW FIVE\n";  
                        b.amt_pay = 0.0;    // free
                    }
                    else if (b.con == 4)
                    {
                        cout << "You cannot get any concession\n";
                        b.amt_pay = b.no_seats * amt;
                    }
                    srand((unsigned)time(&t));
                    b.pnr = rand();
                    f2.write((char *)&b, sizeof(b));
                    cout <<" \n";
                    b.displayresdet();
                    cout <<"\n";
                    cout << "\n--------Your ticket is reserved--------\n";
                }
                else
                {   cout <<"\n";
                    cout << "**********Sorry requested no. seats not available********\n";
                }
            }
            else if (strcmp(b.clas, E) == 0) // for economy class
            {
                if (a.E >= b.no_seats)     // if seats required of economy class are available.
                {
                    amt = a.Efare;
                    addr = f1.tellg();
                    ad = sizeof(a.E);
                    f1.seekp(addr - (5 * ad));
                    a.E = a.E - b.no_seats;
                    f1.write((char *)&a.E, sizeof(a.E));
                    // concession criteria in ticket amount of economy class and same as business class
                    if (b.con == 1)
                    {
                        cout << "Concession category:MILITARY PRESONNEL\n";
                        b.amt_pay = b.no_seats * ((amt * 50) / 100);
                    }
                    else if (b.con == 2)
                    {
                        cout << "Concession category:SENIOR CITIZEN\n";
                        b.amt_pay = b.no_seats * ((amt * 60) / 100);
                    }
                    else if (b.con == 3)
                    {
                        cout << "Concession category:CHILDERN BELOW FIVE\n";
                        b.amt_pay = 0.0;
                    }
                    else if (b.con == 4)
                    {
                        cout << "You cannot get any concession\n";
                        b.amt_pay = b.no_seats * amt;
                    }
                    f2.write((char *)&b, sizeof(b));
                    cout <<" \n";
                    b.displayresdet();
                    cout <<"\n";
                    cout << "\n-----Your ticket is reserved-----\n";
                }
                else
                {   cout <<"\n";
                    cout << "********Sorry requested no. of seats not available*******\n";
                    cout<<"\n";
                }
            }
        }
        else
        {
            flag = 0;
        }
    }
    if (flag == 0)
    {   
        cout << "\n";
    }
    f1.close();
    f2.close();
}

 // function definition
void displaypassdetail()  // display reserved passengers details
{
std::cout << "\n--------Passenger Details--------\n";
fstream f;
reser b;
f.open("p.txt",ios::in|ios::out|ios::binary);
f.seekg(0);
while(f.read((char *) & b,sizeof(b)))
{
b.displayresdet();
}
f.close();
}

// function definition
void enquiry()   // passengers can check for available flights,dates and seats through enquiry
{
    fstream f;
    f.open("t.txt",ios::in|ios::out|ios::binary);     
    Detail a;
    while(f.read((char *) & a,sizeof(a)))
    {
        a.displaydetail();
    }
}

// function definition
void cancell()   // cancelling booked ticket
{  
    Detail a;
    reser b;
    canc c;
    fstream f1, f2, f3;
    f1.open("t.txt",ios::in|ios::out|ios::binary);
    f2.open("p.txt",ios::in|ios::out|ios::binary);
    f3.open("cn.txt",ios::in|ios::out|ios::binary);   //file opened to store ticket cancellation details
    cout<<"**********CANCELLATION MENU*********\n";
    c.getcancdet();
    while(f2.read((char *) & b,sizeof(b)))
    {
        if (b.pnr == c.pnr)  // if pnr no. matches
        {
            c.flight_no = b.flight_no;
            strcpy(c.flight_name, b.flight_name);
            strcpy(c.bp, b.bp);
            strcpy(c.dest, b.dest);
            c.no_seats_can = b.no_seats;
            for (int j = 0; j < c.no_seats_can; j++)
            {
                strcpy(c.pname[j], b.pname[j]);
                c.age[j] = b.age[j];
            }
            strcpy(c.clas, b.clas);
            if (strcmp(c.clas, B) == 0)   // cancelling business class ticket
            {
                while (f1.read((char *)&a, sizeof(a)))
                {
                    if (a.flight_no == c.flight_no)
                    {
                        a.B = a.B + c.no_seats_can;
                        d = a.d;
                        m = a.m;
                        addr = f1.tellg();
                        ad = sizeof(a.B);
                        f1.seekp(addr - (7 * ad));
                        f1.write((char *)&a.B, sizeof(a.B));
                        f1.write((char *)&a.B, sizeof(a.B));
                        tamt = b.amt_pay;
                        // checking if cancelling is possible and what amount to be refunded
                        if ((c.d == d) && (c.m == m))
                        {
                            cout << "You are cancelling at the date of departure\n";
                            c.amt_returned = tamt - ((tamt * 60) / 100);  // 60 % amount deducted
                        }
                        else if (c.m == m)
                        {
                            cout << "You are cancelling at the month of departure\n"; 
                            c.amt_returned = tamt - ((tamt * 50) / 100);        // 50 % amount deducted
                        }
                        else if (m > c.m)
                        {
                            cout << "You are cancelling one month before the date of departure\n";  
                            c.amt_returned = tamt - ((tamt * 20) / 100);   // 20 % amount deducted
                        }
                        else
                        {
                            cout << "Cancelling after the departure\n";    // cancellation not possible
                            cout << "Your request cannot be completed\n";  // no refund
                        }
                       // goto h;
                        cout <<"/n";
                        c.displaycancdet();
                    }
                }
            }
            else if (strcmp(c.clas, E) == 0)   // cancelling economy class ticket
            {
                while (f1.read((char *)&a, sizeof(a)))
                {
                    if (a.flight_no == c.flight_no)
                    {
                        a.E = a.E + c.no_seats_can;
                        d = a.d;
                        m = a.m;
                        addr = f1.tellg();
                        ad = sizeof(a.E);
                        f1.seekp(addr - (5 * ad));
                        f1.write((char *)&a.E, sizeof(a.E));
                        tamt = b.amt_pay;
                        // checking if cancelling is possible and what amount to be refunded and same criteria as business class
                        if ((c.d == d) && (c.m == m))
                        {
                            cout << "You are cancelling at the date of departure\n";
                            c.amt_returned = tamt - ((tamt * 60) / 100);
                        }
                        else if (c.m == m)
                        {
                            cout << "You are cancelling at the month of departure\n";
                            c.amt_returned = tamt - ((tamt * 50) / 100);
                        }
                        else if (m > c.m)
                        {
                            cout << "You are cancelling one month before the date of departure\n";
                            c.amt_returned = tamt - ((tamt * 20) / 100);
                        }
                        else
                        {
                            cout << "Cancelling after the departure\n";
                            cout << "Your request cannot be completed\n";
                        }
                       // goto h;
                        c.displaycancdet();
                        
                    }
                }
            }
        }
        else
        {
            flag = 0;   // if pnr no. does not matches.
           // cout << "Enter the correct pnr no\n";
        }
    }
 /* h:
    if(flag==0)
    {
            cout << "Enter the correct pnr no\n";
   }   */
    f1.close();
    f2.close();
    f3.close();
}

void can()  // confirming if cancellation demanded 
{
    int ch;
    do
    {
        cout << "……………..CANCELLATION MENU………\n";
        cout << "1.Cancel\n2.Return to the main menu\n";
        cout << "Enter your choice:";
        cin >> ch;
        cout << endl;
        switch (ch)
        {
        case 1:
            cancell();
            break;
        }
    } while (ch == 1);
}

// function definition
void user()   // to manage user id and password
{
login a;
int ch;
cout<<"\n-----Login User-----\n";
char password[10];
fstream f;
f.open("id.txt",ios::in|ios::out|ios::binary);
char id[100];
std::cout << "Enter your ID : ";
std::cin >> id;
std::cout << "Enter your Password : ";
std::cin >> password;
while(f.read((char *) & a,sizeof(a)))
{
if((strcmp(a.id,id)==0)&&(strcmp(a.pass,password)==0))  // if user id and password matches
{
do
{
std::cout<<"\n";
std::cout<<"--------WELCOME TO USER  MENU--------";   // user menu options
std::cout<<"\n1.Reserve\n2.Cancel\n3.Enquiry\n4.Return to the main menu\n";
cout<<"Enter your choice:";
cin>>ch;
switch(ch)
{
case 1:
reserve();
break;

case 2:
cancell();
break;

case 3:
enquiry();
break;
}
}while(ch<=3);
}

else
{
d=1;  // if user id and password does not matches
}
}
if(d==1)
{
cout<<"Enter your user id and password correctly\n";
}
}

// function definition
void manage()   // to manage user portal login id and password by admin
{
int ch;
fstream f;
char c;
login a;
std::cout<<"\n---WELCOME TO THE USER MANAGEMENT MENU---\n";
do
{
std::cout << "1. Create user id database\n";
std::cout << "2. Add details to user id database\n";
std::cout << "3. Display details of user id\n";
std::cout << "4. Return to the main menu\n";
std::cout << "Enter your choice: ";
std::cin>>ch;
switch(ch)
{
case 1:   // user login id and password generation
f.open("id.txt",ios::out|ios::binary);
do
{
a.getid();
f.write((char *) & a,sizeof(a));
std::cout << "Do you want to add one more record\n";
std::cout << "y-Yes\nn-No\n";
std::cin>>c;
}while(c == 'y');
f.close();
break;

case 2:  // user login id and password addition
f.open("id.txt",ios::in|ios::out|ios::binary|ios::app);  //  file opened to store user login id and password
a.getid();
f.write((char *) & a,sizeof(a));
f.close();
break;

case 3:  // to display user login id and password 
f.open("id.txt",ios::in|ios::out|ios::binary);
f.seekg(0);
while(f.read((char *) & a,sizeof(a)))
{
a.displayid();
}
f.close();
break;
}
}while(ch<=3);
}
