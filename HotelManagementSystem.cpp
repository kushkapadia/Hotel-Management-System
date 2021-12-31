
#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <fstream>
#define max 100
using namespace std;

class Room;
class Customer;
void mainMenu(void);
int adminMenu(void);

class Room{
private:
int rno;
string rtype;
//string check_out_date;
int beds;
int fare;
int status;
public:
Room addRoom(int);
void displayRooms();
int chkRepeat(int);
friend Customer bookRoom(int);
friend void checkOut(int);
int checkAvailibility();
int chkValidity(int);
Room(){
    status=0;
}
};

class Customer {
private:
int bookingId;
string Name;
char gender;
int age;
string mobileNumber;
int r_no;
int rent;
int status;
string check_in_date;
public:
void viewCustomer();
//void bookRoom();
friend Customer bookRoom(int);
friend void checkOut(int);

Customer(){
    status=1;
}
};

int count=0, c_count=0;
Room rooms[max];
Customer customers[max];


void login()
{
 
    int flag=0,count=3;
    char password[50];
    int i=0;
  char username[50];
    char ch;
    //system("cls");
    cout<<"\n\t\t\t\t************************************";
    cout<<"\n\t\t\t\t         -----------------                       ";
    cout<<"\n\t\t\t\t********|   Admin Login   |*********";
    cout<<"\n\t\t\t\t        -----------------                       ";
    cout<<"\n\t\t\t\t************************************";
    while(count>=1)
    {
    i = 0;
    cout<<"\n\n\t\t\t\tEnter User Name: ";
   cin>>username;
    cout<<"\n\n\t\t\t\tEnter Password: ";
    while (1)
    {
        ch = getch();
        if (ch == 13)
        {
            password[i] = '\0';
            break;
        }
        else
        {
            password[i] = ch;
            i++;
            printf("*");
        }
      
    }
    if (strcmp(username, "taj") == 0)
    {
        if (strcmp(password, "12345") == 0)
        {
            cout<<"\n\n\t\t\t\t~~~~~~Logged IN Successfully~~~~~~";

            Beep(493,250);
            Beep(659,400);
            Beep(739,250);
            Beep(987,600);
            cout<<"\n\n\t\t\t\t********|| WELCOME "<<username<<"! ||*********";
            flag=1;
            break;
        }
        else
        {
            cout<<"\n\n\t\t\t\t------------------ ERROR!Invalid Password! --------------------";
            Beep(415,200);
            Beep(311,200);
            
     
        }
    }
    else
    {
        cout<<"\n\n\t\t\t\t----------------- ERROR!Invalid Username! --------------------";
       
            Beep(415,200);
            Beep(311,200);                    
    }
    count--;
    cout<<"\n"<<count<<" Attempts Remaining\n";
 
    }
    if (flag!=1)
    {
        cout<<"Access Denied!\n";
        cout<<"\nPress any key to exit!";
        getch();
        exit(0);
    }
}


int Room::chkRepeat(int r_no){
int flag;
    for(int i=0; i<count; i++){

         if(rooms[i].rno==r_no){
             flag=1;
             break;
         }
     }
     return flag;
}

Room Room::addRoom(int r_no){
class Room room;

room.rno=r_no;

cout<<"Enter room type [AC/NAC]: ";
cin>>room.rtype;

cout<<"Enter no.of beds: ";
cin>>room.beds;

cout<<"Enter fare for 1 night: ";
cin>>room.fare;
return room;
}

void Room:: displayRooms(){
    
    for(int i=0; i<count; i++){
        cout<<"|Room Number: "<<rooms[i].rno<<endl;
        cout<<"|Room Type: "<<rooms[i].rtype<<endl;
        cout<<"|No.of Beds: "<<rooms[i].beds<<endl;
        cout<<"|Room Rent Rs. : "<<rooms[i].fare<<endl;
        cout<<"|Occupancy[0-Vaccant | 1-Occupied] : "<<rooms[i].status<<endl<<endl;
    }
   
}

int Room:: checkAvailibility(){
    int flag=0;
for(int i=0; i<count; i++)
{
    if(rooms[i].status!=1){
        cout<<"\nRoom Number: "<<rooms[i].rno<<endl;
        cout<<"No.of Beds:"<<rooms[i].beds<<endl;
        cout<<"Room Type:"<<rooms[i].rtype<<endl;
        cout<<"Room Fare: "<<rooms[i].fare<<endl<<endl;
        flag=1;
    }
}
return flag;
}

Customer bookRoom(int r_no){
   Customer customer;
   int i=0;
   while(rooms[i].rno!=r_no){
       i++;
   }
   //cout<<rooms[i].rno;
 customer.r_no = rooms[i].rno;
 //customer.rent = rooms[i].fare;
 cout<<"Enter Booking Id: ";
 cin>>customer.bookingId;

cout<<"Enter your Name: ";
getline(cin>>ws, customer.Name);

cout<<"Enter your gender [M/F/O]: ";
cin>>customer.gender;

cout<<"Enter your Age: ";
cin>>customer.age;

cout<<"Enter check in date [31-12-21] : ";
getline(cin>>ws, customer.check_in_date);
cout<<"Enter your Mobile Number: ";
cin>>customer.mobileNumber;

customer.rent = rooms[i].fare;
 rooms[i].status=1;

return customer;
}

void Customer::viewCustomer(){
      ofstream file;
      file.open("guests.csv", ios::app);
    int flag=0;
    cout<<"\nCustomer Details\n";
    if(!c_count){
        cout<<"No bookings yet"<<endl;
    }

    for(int i=0; i<c_count;i++)
    {
        if(customers[i].status==1){
        file<<"\n";

        cout<<"| Booking ID : "<<customers[i].bookingId<<endl;
        file<<customers[i].bookingId;
        file<<",";

        cout<<"| Room Number : "<<customers[i].r_no<<endl;
        
        file<<customers[i].r_no;
        file<<",";

        cout<<"| Guest Name : "<<customers[i].Name<<endl;
        
        file<<customers[i].Name;
        file<<",";

        cout<<"| Gender : "<<customers[i].gender<<endl;
        
        file<<customers[i].gender;
        file<<",";

        cout<<"| Age : "<<customers[i].age<<endl;
        
        file<<customers[i].age;
        file<<",";

        cout<<"| Mobile Number : "<<customers[i].mobileNumber<<endl;
        file<<customers[i].mobileNumber;
        file<<",";
        
        cout<<"| Check In date : "<<customers[i].check_in_date<<endl;
        file<<customers[i].check_in_date;
        file<<",";

        cout<<"|Paying Rs. "<<customers[i].rent<<" Per Day"<<endl;
        file<<customers[i].rent;
        file<<",";
        cout<<endl;
        
        }
    }
    file.close();
    getch();
}

int Room::chkValidity(int r_no){
    for(int i=0; i<count; i++){
        if((rooms[i].rno == r_no) && (rooms[i].status==0)) {
            return 1;
        }
    }
    return 0;
}

void checkOut(int r_no){
    int found=0, billingAmount=0,days,i=0,j=0;
    for( i=0; i<count; i++){
if(rooms[i].rno==r_no && rooms[i].status==1){
    found=1;
    break;
}
}

if(found==1){

    while(customers[j].r_no!=r_no){
    j++;
    }

    cout<<"Enter Number of days you stayed: ";
    cin>>days;
    cout<<"**********************Check Out Details****************"<<endl;
    cout<<"Booking Id : "<<customers[j].bookingId<<endl;
    cout<<"Guest Name : "<<customers[j].Name<<endl;
    cout<<"Mobile : "<<customers[j].mobileNumber<<endl;
    billingAmount=days*customers[j].rent;
    cout<<"Billing Amount Rs. : "<<billingAmount;
    rooms[i].status=0;
    customers[j].status=0;
}
    else{
        cout<<"Invalid Room Id"<<endl;
    }
}


//----------------------------------------Admin Menu
int adminMenu()
{
    int choice, r_no, flag=0;
    Room room;
    Customer customer;
   //login();
   while(1){
    system("cls");
    cout<<"1.Add a Room\n2.View All Rooms\n3.View All Customers\n4.<-Go Back\n";
    cout<<"Enter which action you want to perform: ";
    cin>>choice;
   switch(choice){
       case 1: 
     cout<<"Enter room number: ";
     cin>>r_no;
     flag = room.chkRepeat(r_no);
    if(flag==1){
    cout<<"Room with this number already exists"<<endl<<"Enter a unique id"<<endl;
    flag=0;
    getch();
    
    }
else{
    rooms[count] = room.addRoom(r_no);
    count++;
}
       break;

       case 2:
     room.displayRooms();
     getch();
       break;
    case 3:
    customer.viewCustomer();
     break;
    case 4:
    mainMenu();
    break;

    default:
    cout<<"Error: Invalid Choice";
   }
   }
}

//--------------------------------------------------Customer Menu
void customerArea(){
    int choice, r_no, flag, valid;
    Room room;
while(1){
    system("cls");
    cout<<"1.Check Availability\n2.Book a Room\n3.Check-Out\n4.<-Go Back\n"<<endl;
    cout<<"Enter Action Number: ";
    cin>>choice;
    switch(choice){
        case 1: 
        cout<<"Available Rooms"<<endl;
        room.checkAvailibility();
        getch();
        break;

        case 2:
        flag = room.checkAvailibility();
        if(flag==0){
        cout<<"No rooms Available"<<endl;
        getch();
        }    
        else{   
        cout<<"Enter which room you want to book: ";
        cin>>r_no;
        valid =room.chkValidity(r_no);
        if(valid ==0){
            cout<<"Error: Invalid Room or Room already booked"<<endl;
            getch();
        }
        else{
        customers[c_count] = bookRoom(r_no);
        c_count++;
        cout<<"Room Added Successfully";
        getch();
        }
        }
        break;

        case 3:
        
        if(count==0){
            cout<<"No rooms available"<<endl;
        }
        else{
        cout<<"Enter the room number you want to check out: ";
        cin>>r_no;
        checkOut(r_no);
        }
        getch();
        break;

        case 4:
        mainMenu();
        break;
    }
}
}
 
//----------------------------------------------------Main Menu
void mainMenu(){
int choice;

while(1){
system("cls");
cout<<"*************************************Welcome to Taj*********************************"<<endl;
cout<<"1.Admin Area"<<endl<<"2.Customer Area"<<endl<<"3.Exit"<<endl;
cout<<"Enter which portal you want to access? ";

cin>>choice;
switch(choice){
    case 1:
    login();
    adminMenu();
    break;

    case 2: 
   customerArea();
    break;

    case 3:
    cout<<"Press any key to exit\n";
    getch();
    exit(0);

    default: 
    cout<<"Error: Invalid choice"<<endl;
}
}
}



int main(){
mainMenu();
return 0;
}