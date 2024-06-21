#include <iostream>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<ctime>
using namespace std;
using std::string ;
int c=0;
class Airport
{
public:
    string airportName;
    string airLocation;

    Airport()
    {
        airportName="NULL";
        airLocation="NULL";
    }
     Airport(string airportName,string airLocation)
    {
        this->airportName=airportName;
        this->airLocation=airLocation;
    }
    void printAirport()
    {
       cout<<"Welcome to "<<airportName<<" "<<airLocation<<endl<<endl;
    }
};

class Employee
{
public:
    string empName;
    string empId;
    double salary;
    int experience;
    Employee()
    {
        empName="NULL";
        empId="NULL";
        salary=0;
        experience=0;
    }
    Employee(string empName,string empId,double salary,int experience)
    {
        this->empName=empName;
        this->empId=empId;
        this->salary=salary;
        this->experience=experience;
    }
    virtual void printEmployee()=0;
};

class AirportEmployee:public Employee
{
   public:
       string designation;
       AirportEmployee():Employee()
       {
           designation="NULL";
       }
       AirportEmployee(string empName,string empId,double salary,int experience,string designation):Employee(empName,empId,salary,experience)
       {
           this->designation=designation;
       }
       void printEmployee()
       {
           cout<<"Name:"<<empName<<endl;
           cout<<"Id:"<<empId<<endl;
           cout<<"Experience:"<<experience<<endl;
           cout<<"Salary:"<<salary<<endl;
           cout<<"Designation:"<<designation<<endl;;
       }
};

class AirlineEmployee:public Employee
{
   public:
       string designation;
       AirlineEmployee():Employee()
       {
           designation="NULL";
       }
       AirlineEmployee(string empName,string empId,double salary,int experience,string designation):Employee(empName,empId,salary,experience)
       {
           this->designation=designation;
       }
       void printEmployee()
       {
           cout<<"Name:"<<empName<<endl;
           cout<<"Id:"<<empId<<endl;
           cout<<"Experience:"<<experience<<endl;
           cout<<"Salary:"<<salary<<endl;
           cout<< designation;
       }
};

class ApplicationException
{
public:
    string errMsg;

    ApplicationException()
    {
        errMsg="NULL";
    }
    ApplicationException(string errMsg)
    {
        this->errMsg=errMsg;
    }
    printException()
    {
        cout<<errMsg<<endl;
    }
};
class BankAccount
{
public:
    int accNo;
    double balance;
    BankAccount()
    {
        accNo=0;
        balance=0;
    }
     BankAccount(int accNo,double balance)
    {
        this->accNo=accNo;
        this->balance=balance;
    }
   int debitAccount(int amt)
    {
        if(amt>balance)
        {
            return 1;
        }
        balance=balance-amt;
        return 0;

    }
};

class Card
{
public:
    long int cardNo;
    string expDate;
    Card()
    {
        cardNo=0;
        expDate="NULL";
    }
    Card(long int a,string b)
    {
        cardNo=a;
        expDate=b;
    }
   virtual int payAmount(double amt)=0;
   void printCard()
   {
       cout<<cardNo<<" "<<expDate<<endl;
   }


};
class CreditCard:public Card
{
public:
    string cardType;
    double maxLimit;
    double credAmount;

    CreditCard()
    {
        cardNo=0;
        expDate="NULL";
        cardType="NULL";
        maxLimit=0;
        credAmount=0;
    }
    CreditCard(long int a,string b,string c,double d,double e)
    {
        cardNo=a;
        expDate=b;
        cardType=c;
        maxLimit=d;
        credAmount=e;
    }
    void printCreditCard()
    {
        cout<<cardNo<<" "<<expDate<<" "<<cardType<<" "<<maxLimit<<" "<<credAmount<<endl;
    }
   int payAmount(double amt)
    {
        if(credAmount+amt>maxLimit)
        {
            return 1;
        }
        credAmount=credAmount+amt;
        return 0;
    }


};


class DebitCard:public Card
{
public:

    string cardType;
    double balance;
    DebitCard():Card()
    {
        cardType="NULL";
       balance=0;
    }

    DebitCard(long int cardNo,string expDate,string cardType,double balance):Card(cardNo,expDate)
    {
        this->cardType=cardType;
        this->balance=balance;
    }
    void printDebitCard()
    {
        cout<<cardNo<<" "<<expDate<<" "<<cardType<<" "<<balance<<endl;
    }
    int payAmount(double amt)
    {
        if(amt>balance)
        {
            return 1;
        }
        balance=balance-amt;
        return 0;
    }

};
class Luggage
{
public:
    int lugId;
    double weight;
    int noOfLug;
    double amtPaid;

    Luggage()
    {
        lugId=0;
        weight=0;
        noOfLug=0;
        amtPaid=0;
    }

    Luggage(int lugId,int weight,int noOfLug)
    {
        this->lugId=lugId;
        this->weight=weight;
        this->noOfLug=noOfLug;
         amtPaid=0;
    }
    void printLuggage()
    {
        cout<<"Id:"<<lugId<<endl;
        cout<<"Weight:"<<weight<<endl;
        cout<<"Number Of Luggage:\n"<<noOfLug;
    cout<<"Amount Paid:\n"<<amtPaid;
    }
    void checkLuggage()
    {
        if(weight>12)
        {
            amtPaid=(weight-12)*600;

        }

    }

};

class Flight
{
public:
    string flightId;
    string fname;
    int capacity;
    string arrivalTime;
    string departureTime;
    string destination;
    Flight()
    {
        flightId="NULL";
        fname="NULL";
        capacity=0;
        arrivalTime="NULL";
        departureTime="NULL";
        destination="NULL";
    }
    Flight(string flightId,string fname,int capacity,string arrivalTime,string departureTime,string destination)
    {
        this->flightId=flightId;
        this->fname=fname;
        this->capacity=capacity;
        this->arrivalTime=arrivalTime;
        this->departureTime=departureTime;
        this->destination=destination;
    }
    void printFlight()
    {
        cout<<"flightId= "<<flightId<<"\nflight name= "<<fname<<"\nCapacity"<<capacity<<"\narrivalTime= "<<
        arrivalTime<<"\ndepartureTime= "<<departureTime<<endl<<endl;

    }


};
class BookingStatus
{
public:
    virtual void print()=0;
};

class Processing : public BookingStatus
{
public:
    void print()
    {
        cout<<"Under the process"<<endl;
    }
};

class Confirm : public BookingStatus
{
public:
    void print()
    {
        cout<<"Ticket booked successfully";
        c++;
    }
};

class Aborted: public BookingStatus
{
public:
    void print()
    {
        cout<<"Sorry!!Process aborted/failed ";
        cout<<"Unable to book ticket ";
    }
};


class TicketCounter
{
public:
    int tid;
    string source;
    string destination;
    double price;
    BookingStatus *currentStatus;
   // BankAccount ba;
    Flight *f[5],ho;
    string classType;
    string g;
     int h;
     int j=0;
    TicketCounter()
    {
         tid=0;
         source="NULL";
         destination="NULL";
         price=0;
        currentStatus= new Processing();
    }
    TicketCounter(int tid,string source,string destination,double price)
    {
        this->tid=tid;
        this->source=source;
        this->destination=destination;
        this->price=price;
        currentStatus= new Processing();
    }
    void printTicket()
    {
       cout<<"Ticket Id= "<<tid<<"\n Source= "<<source<<"\n destination= "<<destination<<"\n price= "<<price<<endl<<endl;


    }
    void bookTicket(BookingStatus *x,BankAccount *b2,Luggage l1,Card *card,CreditCard ca1,DebitCard da1)
    {

        currentStatus=x;
        double c=classTypePrice();
        double d=additionalServices();

           // statusPrint();
            currentStatus=new Processing;
            cout<<endl<<"Ticket Booking is ";
            statusPrint();

            cout<<"-------------- Ticket Details -------------------"<<endl;
            printTicket();

            cout<<"----------------Flight details from Source to Destination------------------------"<<endl;
              for(int i=0;i<5;i++)
              {

                  if(f[i]->destination==destination)
                  {
                      f[i]->printFlight();
                      ho=*f[i];
                  }
              }

               cout<<"Additional charges are"<<endl;
               l1.checkLuggage();
               cout<<"Overweight Luggage Charge="<<l1.amtPaid<<endl;
               cout<<"Class type charges="<<c<<endl;
               cout<<"Service charge="<<d<<endl<<endl;

        price=TotalPrice(l1.amtPaid,c,d);
        cout<<"-------Total Price------\n";
        cout<<"Total price of Ticket Booking is "<<price<<endl<<endl;
        int j=0;
        while(j<3)
        {


        cout<<"Enter the mode of payment \n 1.credit card 2.debit card 3.net Banking "<<endl;
        cin>>h;

       if(h==2)
       {
           card=&da1;
      int a= card->payAmount(price);
        if(a==1)
        {
            currentStatus=new Aborted;
            cout<<"|-------------------------------------------------------------------------------------------------|"<<endl;
            cout<<"|";
             statusPrint();
            cout<<"  failed due to insufficient balance         |"<<endl;
            cout<<"|-------------------------------------------------------------------------------------------------|"<<endl<<endl;
            j++;
            cout<<"use the another payment method"<<endl;

        }
        else
        {
           currentStatus=new Confirm;
           cout<<"**************************************"<<endl;
           cout<<"|     ";
           statusPrint();cout<<"     |"<<endl;;
           cout<<"**************************************"<<endl;
           break;

        }
       }
       else if(h==3)
       {
        int a=b2->debitAccount(price);
         if(a==1)
         {
            currentStatus=new Aborted;
            cout<<"|------------------------------------------------------------------------------------------------------|"<<endl;
            cout<<"|";
            statusPrint();
            cout<<" due to insufficient balance                      |"<<endl;
            cout<<"|------------------------------------------------------------------------------------------------------|"<<endl;
            j++;
            cout<<endl;
            cout<<"use the another payment method"<<endl;
         }
        else
        {
           currentStatus=new Confirm;
           cout<<"**************************************"<<endl;
           cout<<"|     ";
           statusPrint();cout<<"     |"<<endl;;
           cout<<"**************************************"<<endl;
           break;
          }

       }
       else
       {
           card=&ca1;
           int a= card->payAmount(price);
            if(a==1)
           {
            currentStatus=new Aborted;
            cout<<"|------------------------------------------------------------------------------------------------------|"<<endl;
            cout<<"|";
            statusPrint();
            cout<<" due to crossing the maximum credit limit amount  |"<<endl;
            cout<<"|------------------------------------------------------------------------------------------------------|"<<endl;
            j++;
            cout<<endl;
            cout<<"use the another payment method"<<endl;

           }
            else
           {
           currentStatus=new Confirm;
           cout<<"**************************************"<<endl;
           cout<<"|     ";
           statusPrint();cout<<"     |"<<endl;;
           cout<<"**************************************"<<endl;
           break;
           }
            }
        }
            if(j==3)
            {
              throw ApplicationException("All payment methods are failed try next time");
            }

    }
    void statusPrint()
    {
        currentStatus->print();
    }
    double classTypePrice()
    {
        cout<<"Enter the ticket class you want:"<<endl;
        cout<<"1.economy  2.premium economy  3.business class\n";
        cin>>classType;
        int b=0;
        if(classType=="economy")
        {

        }
        else if(classType=="premium economy")
        {
            b=500;
            return b;
        }
        else if(classType=="business class")
        {
            b=1500;
            return b;
        }
        else
        {
            b=2500;
            return b;
        }
        return b;
    }
    double additionalServices()
    {
        cout<<"Do u want additional services like meal,lounge access etc"<<endl;
           cin>>g>>g;
           if(g=="yes")
           return 2000;
           return 0;
    }
    double TotalPrice(double h,double c,double d)
    {
        price=price+h+c+d;
        return price;
    }
};

class Passengers
{
public:
   string  pasName;
   int pasId;
   int age;
   long int phoneNo;
   string email;
   string ticketBooked;
   BankAccount *b2;
   Card *card;
   Luggage la;

   Passengers()
   {
       pasName="NULL";
       pasId=0;
       age=0;
       phoneNo=0;
       email="NULL";
       ticketBooked="NULL";

   }
   Passengers(string pasName,int pasId,int age,int phoneNo,string email,string ticketBooked,Luggage l1)
   {
       this->pasName=pasName;
       this->pasId=pasId;
       this->age=age;
       this->phoneNo=phoneNo;
       this->email=email;
       this->ticketBooked=ticketBooked;
       la=l1;
   }
   void printPassengers()
   {
       cout<<pasName<<" "<<pasId<<" "<<age<<" "<<phoneNo<<" "<<email<<" "<<ticketBooked<<endl;

   }
   void ticketBook(TicketCounter t1,CreditCard ca1,DebitCard da1)
   {
       if(ticketBooked=="no")
       {
         t1.bookTicket(new Processing,b2,la,card,ca1,da1);
         }
   }

};

class NoticeBoard
{
public:

    Flight *f1[5];

    void flightDisplay()
    {
        cout<<"|Flight Name     |Flight ID       |Boarding Time          | Departure Time         |"<<endl;
        cout<<endl;
        for(int i=0;i<5;i++)
        {
            cout<<i+1<<") "<<f1[i]->fname<<"|"<<f1[i]->flightId<<"|"<<f1[i]->arrivalTime<<"|"<<f1[i]->departureTime<<""<<endl;
        }

    }
};

int main()
{
   int n=0;
    Luggage l1(456,15,1),l2(478,20,2),l3(479,10,3),l4(480,18,4);
    Passengers p1("Soni",123,17,4648463415,"soni12@gmail.com","no",l1);
    Passengers p2("Akshay",125,20,4788526325,"Akshay@gmail.com","no",l2);
    Passengers p3("Santosh",130,18,4567891230,"Santosh@gmail.com","no",l3);
    Passengers p4("Riya",131,25,789456125,"Riya@gmail.com","no",l4);
    Airport a1("Kempegowda International Airport","Bangalore");
    TicketCounter t1(52697,"Bangalore","Delhi",3000);
    string f;
    AirportEmployee ae1("Ganesh","EMP001",20000,5,"Entrance Verifier");
    AirportEmployee ae2("Rajendra","EMP002",22000,4,"Ticket Counter");
    Employee *e1[2];
    e1[0]=&ae1;
    e1[1]=&ae2;
    cout<<"                            Airport Reservation and Management         \n";
    cout<<"------------------------"<<endl;
    cout<<"Passenger 1 Details:\n";
    p1.printPassengers();
    cout<<"------------------------\n";
    cout<<"Airport Security\n"<<endl;
    e1[0]->printEmployee();
    cout<<"Passenger Details:\n";
    p1.printPassengers();
    cout<<"--------------------------\n";
    cout<<"Checks for passport of passengers "<<endl;
    cout <<"Check if passport is present "<<endl;
    cin >>f;
    if( f =="yes" || f=="Yes")
    {
        try{
        a1.printAirport();
        cout<<"Ticket Booking Employee\n";
        //e1[1]->printEmployee();
        p1.b2=new BankAccount(123456,50000);

        t1.f[0]=new Flight("AIR001","Air India",300,"11:30","12:00","Delhi");
        t1.f[1]=new Flight("AIR002","Indigo Airlines",250,"10:00","11:00","America");
        t1.f[2]=new Flight("AIR023","Qatar Airlines",350,"14:10","15:00","Dubai");
        t1.f[3]=new Flight("AIR056","Air Asia Airlines",260,"12:00","13:00","Nepal");
        t1.f[4]=new Flight("AIR002","Emirates Airlines",300,"19:19","20:00","Srilanka");
        CreditCard ca1(14588623574123,"12-2-2040","regular",40000,30000);
       DebitCard da1(14588623577551,"26-2-2045","business",10000);
        p1.ticketBook(t1,ca1,da1);
        cout<<endl;
         NoticeBoard n1;
        n1.f1[0]=new Flight("AIR001","Air India",300,"11:30","12:00","Delhi");
        n1.f1[1]=new Flight("AIR002","Indigo Airlines",250,"10:00","11:00","America");
        n1.f1[2]=new Flight("AIR023","Qatar Airlines",350,"14:10","15:00","Dubai");
        n1.f1[3]=new Flight("AIR056","Air Asia Airlines",260,"12:00","13:00","Nepal");
        n1.f1[4]=new Flight("AIR002","Emirates Airlines",300,"19:19","20:00","Srilanka");

        cout<<"-----------------Notice Board Display------------------\n";
          n1.flightDisplay();
          n++;


         }
         catch(ApplicationException &ab)
         {
             ab.printException();
         }

    }
    else
    {
        cout<<"Unable enter the Airport"<<endl;
    }

    cout<<endl<<"--------------------for passenger 2--------------------------------------------------\n";

    cout<<"Airport Security\n"<<endl;
    ae1.printEmployee();
    cout<<"Passenger 2 Details:\n";
    p2.printPassengers();
    cout<<"--------------------------\n";
    cout<<"Airport Security for Checking Passport of Passengers "<<endl;
    cout<<"Check if passport is present "<<endl;
    cin>>f;
    if( f =="yes" || f=="Yes")
    {
        try
        {
        a1.printAirport();
        cout<<"Ticket Booking Employee\n";
        e1[1]->printEmployee();
        p2.b2=new BankAccount(810456,1000);
         CreditCard ca2(145886752652,"18-3-2045","regular",40000,3000);
       DebitCard da2(1458862385412,"28-2-2030","business",100000);
        p2.ticketBook(t1,ca2,da2);
        cout<<endl;
         NoticeBoard n1;
        n1.f1[0]=new Flight("AIR001","Air India",300,"11:30","12:00","Delhi");
        n1.f1[1]=new Flight("AIR002","Indigo Airlines",250,"10:00","11:00","America");
        n1.f1[2]=new Flight("AIR023","Qatar Airlines",350,"14:10","15:00","Dubai");
        n1.f1[3]=new Flight("AIR056","Air Asia Airlines",260,"12:00","13:00","Nepal");
        n1.f1[4]=new Flight("AIR002","Emirates Airlines",300,"19:19","20:00","Srilanka");

        cout<<"-----------------Notice Board Display------------------\n";
          n1.flightDisplay();
          n++;

         }
         catch(ApplicationException &ab)
         {
             ab.printException();
         }

    }
    else
    {
        cout<<"Unable enter the Airport"<<endl;
    }

    cout<<"------------------------------------------for passenger 3---------------------------------------"<<endl;
    cout<<"Passenger 3 Details:\n";
    p3.printPassengers();
    cout<<"--------------------------\n";
    cout<<"Airport Security for Checking Passport of Passengers "<<endl;
    cout<<"Check if passport is present "<<endl;
    cin>>f;
    if( f =="yes" || f=="Yes")
    {
        try
        {
        a1.printAirport();
        cout<<"Ticket Booking Employee\n";
        e1[1]->printEmployee();
        p3.b2=new BankAccount(809455,1000);
         CreditCard ca3(14588674156952,"8-3-2056","regular",30000,26000);
       DebitCard da3(145885125485,"28-2-2030","business",1000);
        p3.ticketBook(t1,ca3,da3);
        cout<<endl;
         NoticeBoard n1;
        n1.f1[0]=new Flight("AIR001","Air India",300,"11:30","12:00","Delhi");
        n1.f1[1]=new Flight("AIR002","Indigo Airlines",250,"10:00","11:00","America");
        n1.f1[2]=new Flight("AIR023","Qatar Airlines",350,"14:10","15:00","Dubai");
        n1.f1[3]=new Flight("AIR056","Air Asia Airlines",260,"12:00","13:00","Nepal");
        n1.f1[4]=new Flight("AIR002","Emirates Airlines",300,"19:19","20:00","Srilanka");

        cout<<"-----------------Notice Board Display------------------\n";
          n1.flightDisplay();
           n++;
         }
         catch(ApplicationException &ab)
         {
             ab.printException();
         }

    }
    else
    {
        cout<<"Unable enter the Airport"<<endl;
    }
     cout<<endl<<"Number of seats booked ="<<n<<endl;

return 0;
}
