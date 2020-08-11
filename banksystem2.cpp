//revised
/*"Created By Divakar D
		Program To Simulate a real time Banking System
		HERE We created a class called bank and inherited 2 classes called employee and account
		class employee:-Will get a data the of employee of a bank and stores the data of employee by creating a file called "employee" in .dat format
		class account:-Deals with account management of Banking customers,stores a data of customer account by creating a file called "account" in .dat format*/  
#include<iostream>
#include<fstream>//To Handle file I/O operations it includes ifstream and ofstream
#include<cctype>//declares a set of function to classify individual characters
#include<iomanip>//used to manipulate the output of program
#include<ctime>
#include<cstdlib>
using namespace std;
class bank//creating a class called bank
{
	protected://data members are protected 
		int empid;//cannot be accessed by non-member functions 
		int acno;
		int accpin_em;
		int accpin_acc;
		int autho;
		int accautho;
	public:
		bank()
		{
			autho=2020;
			accautho=1947;
		}
		void write_employee();//memeber fuctions to class called bank to store a data in a file of employee
		void display_Semp(int);//display single employee from a file called employee.dat
		void modifyemployee(int);//modifying employee file data
		void delete_emp(int);//delete employee data
		void display_emp_all();//display all employee's
		void write_account();//store a data in a file called account
		void display_sp(int);//display single account holder data from a file
		void transfer_sc(int);//transfer money(sender)
		int transfer_rc(int,char,int);//money receiver function
		void modify_account(int);//modify account data
		void delete_account(int);//delete account data in a file
		void display_all();
		void deposit_withdraw(int, int);//withdraw and deposit function	
		void modify_access();
		void modify_acc_access();
};
class employee:public bank
{
	char name[50];/*private data members of class employee*/
    char dob[50];
	long salary;	
	int jgex;
	int id;
    char add[30];
    char email[50];
	public:
		employee()//constructor to initailze the data members of class employee
		{
			salary=15000;//fixing a salary for a employee
		}
		void newemployee();//member functions for class employee
		void show_employee();
		void modify_emp();
		void modifyaccess();
		void display_emp() const;/*using a const member function becouse "not to allow a function to modify the object on which they are called*/
		int retempid() const;
		int resalary() const;
		int retaccess() const;
		
};
void employee::newemployee()
{
	int i;
	int max=1000;
	int min=1;
	int maxi=9000;
	int mini=1000;
	char ad[30];
	system("CLS");
	std::srand(std::time(0));
	empid = std::rand()%max+min;//clearing a Screen
	cout<<"\n\t\t\t\tEnter the Name of emlpoyee: ";
	cin.ignore();			//clears a single character buffer
	cin.getline(name,50);	//Take a string 
	cout<<"\n\t\t\t\tEnter Your Date of Birth(dd/mm/yyyy): ";
	cin.getline(dob,50);//Take a string
	cout<<"\n\t\t\t\tEnter your Adharr number:";
	cin.getline(add,30);
	cout<<"\n\t\t\t\tEnter Your mail ID: ";
	cin.getline(email,50);
	char jc;
	cout<<"\n\t\t\t\tDo you have any worked expeience(y/n): ";
	cin>>jc;
	if(jc=='Y'|| jc=='y')
	{
		cout<<"\n\t\t\t\tEnter your Job Experience(in Years): ";//getting a Job Exprerience of an employee
		cin>>jgex;
		if(jgex >= 5)
		{
			salary=salary+salary*0.15;	//if an employee Job experience is more than 5 years then an additional 15% of salary is added
		}
	}
	accpin_em=std::rand()%maxi+mini;
	cout<<"\n\t\t\t\t\t\t\tYour Employee profile created successfully";
	cout<<"\n\n\t\t\t\t\t\tATTENTION PLEASE";
	cout<<"\n\t\t\t\t\t\t\tYOur Employee ID is: "<<empid;
	cout<<"\n\n\t\t\t\t\t\t\tYour Access PIN: ";
	cout<<accpin_em;
}
void employee::show_employee()//Display's Details of Individual Employee
{
	cout<<"\n\t\tEmployee ID : "<<empid;
	cout<<"\n\t\tEmployee Name: ";
	cout<<name;
	cout<<"\n\t\tDate of Birth: ";
	cout<<dob;
	cout<<"\n\t\tAdhaar number: ";
	cout<<add;
	cout<<"\n\t\tEmail Address: ";
	cout<<email;
	cout<<"\n\t\tSalary: "<<salary;
}
void employee::modify_emp()//This Function will modify any modifications is required 
{
	cout<<"\n\n\t\tEmpid: "<<empid;
	cout<<"\n\t\t\t\tEnter your Adhaar number: ";
	cin.ignore();
	cin.getline(add,30);
	cout<<"\n\t\t\t\tEnter your Mail ID: ";
	cin.getline(email,50);
}
void employee::modifyaccess()
{
	int maxi=9000;
	int mini=1000;
	show_employee();
	cout<<"\n\t\t\t\t\tReseting Your Access PIN:)";
	cout<<"\n\n\t\t\t\tKindly Remember 4 digit Access PIN to make Actions";
	std::srand(std::time(0));
	accpin_em=std::rand()%maxi+mini;
	cout<<"\n\n\t\t\tNEW Access PIN: ";
	cout<<accpin_em;
}
void employee::display_emp() const//This function will Display all employee's Details in a bank
{
	cout<<"\n\t\t\t\t"<<empid<<setw(10)<<" "<<name<<setw(10)<<" "<<add<<setw(10)<<" "<<email<<setw(10)<<" "<<dob<<setw(15)<<"INR "<<salary<<endl;
}
int employee::retempid() const//returns employee id
{
	return empid;
}
int employee::resalary() const//returns employee salary 
{
	return salary;
}
int employee::retaccess() const
{
	return accpin_em;
}
//class account for customers


class account:public bank//creates a class called account  
{
	char name[50];//private data members of class account
	int deposit;
	char type;//type of account (S/C)
	char acadd[30];
	char mail[50];
public:
	void create_account();//member Functions of class account
	void show_account();
	void dep(int);
	void modify_acc();
	void draw(int);
	void modify_accessPin();
	void report() const;
	int retacno() const;
	int retdeposit() const;
	char rettype() const;
	int retaccess_acc() const;
};

void account::create_account()//This function create a new account for customer 
{                  //clearing the screen
	int max=1000;
	int min=1;
	int mini=1000;
	int maxi=9000;
	system("CLS");
	std::srand(std::time(0));
	acno = std::rand()%max+min;
	cout<<"\n\t\t\tEnter the Name of the Account holder : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\t\t\tLink your Adhaar number: ";
	cin.getline(acadd,30);
	cout<<"\n\t\t\tEnter your Email ID: ";
	cin.getline(mail,50);
	cout<<"\n\t\t\tEnter Type of the Account....\n\t\t\tSavings|Current(S/C) : ";
	cin>>type;//type of account
	type=toupper(type);//converting lower case character to uppercase we included "cctype" hearder file for this purpose
	cout<<"\n\t\t\tEnter The Initial amount : ";//deposit intial amount
	cin>>deposit;
	accpin_acc= std::rand()%maxi+mini;
	cout<<"\n\t\t\t\tAccount Created....";
	cout<<"\n\n\t\t\t\t\t\tKINDLY PLEASE ATTENTION";
	cout<<"\n\n\t\t\t\tYour Account Number is: "<<acno;
	cout<<"\n\n\t\t\t\tPlease Kindly Remember Your 4 digit Access PIN";
	cout<<"\n\n\t\t\t\tAccount Holder Access Code: ";
	cout<<accpin_acc;
	if(type=='S')
	{
		cout<<"\n\t\t\t\tYou Have To maintain minimum balance of INR 1000 in your account\n";
	}
}

void account::show_account()//display's indivdual customer's account details
{
	cout<<"\n\t\t\tAccount No. : "<<acno;
	cout<<"\n\t\t\tAccount Holder Name : ";
	cout<<name;
	cout<<"\n\t\t\tlinked Adhaar number: ";
	cout<<acadd;
	cout<<"\n\t\t\tEmail ID: "<<mail;
	cout<<"\n\t\t\tType of Account : "<<type;
	cout<<"\n\t\t\tBalance amount : "<<deposit;
}
void account::modify_acc()
{
	cout<<"\n\n\t\tAccount number: "<<acno;
	cout<<"\n\t\t\t\tEnter your Adhaar number: ";
	cin.ignore();
	cin.getline(acadd,30);
	cout<<"\n\t\t\t\tEnter your Mail ID: ";
	cin.getline(mail,50);
	
}
void account::modify_accessPin()
{
	show_account();
	cout<<"\n\n\t\t\t\tRegenarating Your Access PIN: )";
	int mini=1000;
	int maxi=9000;
	std::srand(std::time(0));
	accpin_acc = std::rand()%maxi+mini;
	cout<<"\n\n\t\t\t\tPlease Kindly Note Your 4 digit Access PIN to make any Actions on your Account";
	cout<<"\n\t\t\t\tYour NEW Access Code:";
	cout<<accpin_acc;
}
void account::dep(int x)//This function to Deposit amount into account 
{
	deposit+=x;
}
int account::retaccess_acc() const
{
	return accpin_acc;
}

void account::draw(int x)//This Function is to Withdraw
{
	deposit-=x;
}

void account::report() const//Display's all accounts in a bank with customer details
{
	cout<<"\n\t\t\t\t"<<acno<<setw(10)<<" "<<name<<setw(10)<<" "<<acadd<<setw(8)<<" "<<mail<<setw(9)<<" "<<type<<setw(15)<<"INR "<<deposit<<endl;
}

int account::retacno() const//returns account number
{
	return acno;
}

int account::retdeposit() const//returns balance amount in a account
{
	return deposit;
}

char account::rettype() const//returns a type of account(S/C)
{
	return type;
}

int main()//main function
{
	account ob;//creating a object to class account inturn invokes the class bank
	employee emp;//creating a object to class employee inturn invokes the class bank
	char ch,ch1;
	int num1,num2;
	char choice;
	char verify[30];
	int num;
	do
	{
	system("CLS");//clearing a screen like in Turbo C++
	cout<<"\n\t\t\t\t\t======================\n";
	cout<<"\t\t\t\t\tBANK MANAGEMENT SYSTEM       ";
	cout<<"\n\t\t\t\t\t======================\n";
	cout<<"\n\t\t\t\t\tUpdated";
	cout<<"\n\t\t\t\t\tNote:Provided Additional Security for Account Holders and Employee's'";
	cout<<"\n\n\t\t\t\t       ::MAIN MENU::";
	cout<<"\n\t\t\t\t\t1:Customer";
	cout<<"\n\t\t\t\t\t2:Employee";
	cout<<"\n\t\t\t\t\t3:Exit";
	cout<<"\n\t\t\t\t\t\tSelect Your option(1-3): ";
	cin>>choice;
	if(choice=='1')//TRUE when this for an Customer
	{
		do
		{
		system("CLS");
		cout<<"\n\t\t\t\t\t======================\n";
		cout<<"\t\t\t\t\t      CUSTOMER         ";
		cout<<"\n\t\t\t\t\t======================\n";
			cout<<"\t\t\t\t\t    ::MAIN MENU::\n";
			cout<<"\n\t\t\t\t\t1. NEW ACCOUNT";
			cout<<"\n\t\t\t\t\t2. DEPOSIT AMOUNT";
			cout<<"\n\t\t\t\t\t3. WITHDRAW AMOUNT";
			cout<<"\n\t\t\t\t\t4. BALANCE ENQUIRY";
			cout<<"\n\t\t\t\t\t5. ALL ACCOUNT HOLDER LIST";
			cout<<"\n\t\t\t\t\t6. CLOSE AN ACCOUNT";
			cout<<"\n\t\t\t\t\t7. Money transfer";
			cout<<"\n\t\t\t\t\t8. Modify your account details";
			cout<<"\n\t\t\t\t\t9. Forgot Account Access PIN";
			cout<<"\n\t\t\t\t\tE. Exit";
			cout<<"\n\n\t\t\t\t\tSelect Your Option (1-E): ";
			cin>>ch;

			switch(ch)
			{
			case '1':
				ob.write_account();
				break;
			case '2':
				system("CLS");//clearing the screen
				cout<<"\n\n\t\t\t\t\tEnter The account No. : "; cin>>num;
				ob.deposit_withdraw(num, 1);
				break;
			case '3':
				system("CLS");//clearing the screen
				cout<<"\n\n\t\t\t\t\tEnter The account No. : "; cin>>num;
				ob.deposit_withdraw(num, 2);
				break;
			case '4':
				system("CLS");//clearing the screen
				cout<<"\n\n\t\t\t\t\tEnter The account No. : "; cin>>num;
				ob.display_sp(num);
				break;
			case '5':
				ob.display_all();
				break;
			case '6':
				system("CLS");//clearing the screen
				cout<<"\n\n\t\t\t\t\tEnter The account No. : "; cin>>num;
				ob.delete_account(num);
				break;
			case '7':
				system("CLS");
				cout<<"\n\t\t\t\t\t\t===============================";
				cout<<"\n\t\t\t\t\t\t       TRANSFER MONEY ";
				cout<<"\n\t\t\t\t\t\t================================\n";
				cout<<"\n\t\t\t\t\t\tEnter  the Account no. :"; cin>>num;
				ob.transfer_sc(num);
				break;
			case '8':
				system("CLS");
				cout<<"\n\n\t\t\t\tEnter Your Account number: "; cin>>num;
				ob.modify_account(num);
				break;
			case '9':
				system("CLS");
				ob.modify_acc_access();
				break;
			case 'E':
		 		system("CLS");//clearing the screen
				cout<<"\n\n\t\t\t\t\tBrought To You Divakar D*****";
				cout<<"\n\t\t\t\t\t\tIf any Doubt Please free to Message me:-divakar2920@gmail.com";
				cout<<"\n\t\t\t\t\tPress->Enter to GO Main Menu\n";
				break;
			default :cout<<"\a";
			}
			cin.ignore();
			cin.get();
			//clearing a buffer 
    		}while(ch!='E');
    }
    else if(choice=='2')//This for Employee
    {
    	do
    	{
    	system("CLS");
		cout<<"\n\t\t\t\t\t======================\n";
		cout<<"\t\t\t\t\t         EMPLOYEE         ";
		cout<<"\n\t\t\t\t\t======================\n";
			cout<<"\t\t\t\t\t    ::MAIN MENU::\n";
			cout<<"\n\t\t\t\t\t1. NEW EMPLOYEE";
			cout<<"\n\t\t\t\t\t2: Display an Employee";
			cout<<"\n\t\t\t\t\t3. ALL EMPLOYEES LIST";
			cout<<"\n\t\t\t\t\t4. CLOSE AN EMPLOYEE PROFILE";
			cout<<"\n\t\t\t\t\t5. MODIFY AN EMPLOYEE DETAILS";
			cout<<"\n\t\t\t\t\t6. Forgot Access PIN";
			cout<<"\n\t\t\t\t\t7. EXIT";
			cout<<"\n\n\t\t\t\t\tSelect Your Option (1-7): ";
			cin>>ch1;
			switch(ch1)
			{
			case '1':
				emp.write_employee();
				break;
			case '2':
				system("CLS");
				cout<<"\n\n\t\t\t\tEnter Emp ID: "; cin>>num1;
				emp.display_Semp(num1);
				break;
			case '3':
				emp.display_emp_all();
				break;
			case '4':
				system("CLS");
				cout<<"\n\n\t\t\t\tEnter Emp ID: "; cin>>num1;
				emp.delete_emp(num1);
				break;
			case '5':
				system("CLS");
				cout<<"\n\n\t\t\t\tEnter Emp ID: "; cin>>num1;
				emp.modifyemployee(num1);
				break;
			case '6':
				system("CLS");
				emp.modify_access();
				break;
			case '7':
				system("CLS");
				cout<<"\n\n\t\t\t\tBrought TO YOU BY Divakar divakar2920@gmail.com\n";
				cout<<"\t\t\t\tPress->Enter to Go Main Menu\n";
				break;
			default:cout<<"\a";
			}
			cin.ignore();
			cin.get();
		}while(ch1!='7');
	}
	else
	{
		cout<<"\n\t\t\t\t\t==========================";
		cout<<"\n\t\t\t\t\t Brought you by Divakar D divakar2920@gmail.com";
		cout<<"\n\t\t\t\t\t==========================\n";
		cout<<"\t\t\t\t\t\tThank You";
	}
		cin.ignore();
		cin.get();
	}while(choice!='3');
return 0;
}

void bank::write_account()//This function creates a file and stores a data in file
{
	account ac;			//object to account to access member function of class account
	ofstream outFile;	//used to create a file and write information to file
						//ios::out(binary)ios::binary makes the data is written without translating a newline
	outFile.open("account.dat",ios::binary|ios::app);//opening a file in binary or ios::app:-opens a file in writing mode at last byte(Append)
	ac.create_account();//calls a member function to get data of a account
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));//Binary input function to write into a file //write the individual bytes of varible
	outFile.close();	//closing a file
}
void bank::modify_account(int n)
{
	bool found=false;
	int a;
	account ac;
	fstream File;
    File.open("account.dat",ios::binary|ios::in|ios::out);//ios::binary opens in binary mode
                                                          //ios::in is for input operation
                                                          //iso::out is for ouput operation
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			found=true;
			cout<<"\n\t\t\t\tPlease Kindly provide Your Account Access PIN  to proceed:";
			cin>>a;
			if(ac.retaccess_acc()==a)
			{
				ac.show_account();//Previous data of employee
				cout<<"\n\n\t\t\tEnter The New Details of account"<<endl;
				ac.modify_acc();//Function call
				int pos=(-1)*static_cast<int>(sizeof(account));//Static_cast:-It is a operator used for converting a numeric data types into "int"
				File.seekp(pos,ios::cur); 
		    	File.write(reinterpret_cast<char *> (&ac), sizeof(account));
		    	cout<<"\n\n\t\t\tNew Details Updated";
		    }
		    else
		    {
		    	cout<<"\n\t\t\t\tIncorrect Access PIN";
		    	cout<<"\n\t\t\t\tKindly Try again later";
			}
		}
	}
	File.close();
	if(found==false)
		cout<<"\n\n\t\t\tEntered Account number not exits";
}

void bank::display_sp(int n)//This function is to Display a single person account details
{
	account ac;
	int a;
	bool flag=false;//Declaring a boolean varialbe with false value
	ifstream inFile;//Reading a input form a file 
	inFile.open("account.dat",ios::binary);//opening a file
	if(!inFile)//if file is not able to open properly
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))//Binary output function to read from a file called account
	{
		if(ac.retacno()==n)//ac.retacno :-returns the account number and checks it with a account number in variable 'n' if it matches then display's
		{
			flag=true;//flag is updated to 1 if  account exits
			cout<<"\n\t\t\t\tKindly Provide Your Access Code To proceed: ";
			cin>>a;
			if(ac.retaccess_acc() == a)
			{
				cout<<"\n\n\t\t\tBALANCE DETAILS\n";
				ac.show_account();
			}
			else
			{
				cout<<"\n\t\t\tIncorrect Access PIN";
				cout<<"\n\n\t\t\tPlease try Again after sometime";
			}
		}
	}
    inFile.close();//close a file
	if(flag==false)//if Flag is not updated then the message will be displayed
		cout<<"\n\n\t\t\tAccount number does not exist";
}
//            Money transfer
void bank::transfer_sc(int n)//This Function allows sender to transfer a money into another account  
{
	int amt;
	int a;
	int temp;
	char senacctype;
	char rcacc;
	int accnum;
	bool found=false;//Declaring a boolean varialbe with false value
	bool foun=true;
	bank bb;
	account ac;
	fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);//ios::out:-open a file for writing a Data
	if(!File)//if file is not able to open properly		  //ios::in:-opens a file for reading a Data
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)//checking if file pointer is reached "End of File"
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));//reads from a file called account
		if(ac.retacno()==n)
		{
			accnum=ac.retacno();
			found=true;//update found to 1
			cout<<"\n\t\t\t\t\t\tAccess PIN: ";
			cin>>a;
			if(ac.retaccess_acc()==a)
			{
				cout<<"\n\t\t\t\t\t\tEnter The amount to be tranfer: ";
				cin>>amt;
				if(amt<100)
				{
					cout<<"\n\t\t\tMinimum tranction is Rupees 100";
				}
				else
				{
					temp=amt;
					senacctype = ac.rettype();
					if(ac.rettype()=='S')//money Transfer for savings account holder 
					{
						if(amt<=ac.retdeposit()-1000)//savings account holder maintain an initial balance of INR 1000
						{
							foun,rcacc=bb.transfer_rc(temp,senacctype,accnum);
				       	//calls reciever account to recieve money
							if(foun==true && ac.rettype() == rcacc)//rcacc(receiver acctype)
									ac.draw(amt);
							else //else deposit the amount into account of sender  
								ac.retdeposit()+amt;
						}
						else if(amt<=1000)
						{
							system("CLS");
							cout<<"\n\t\t\t\tYour Transaction is Declined Due To......";
							cout<<"\n\t\t\t\tInsufficience balance";
							cout<<"\n\t\t\t\tPlease maintian minimum balance Amount\n";
						}
						else
						{	
							system("CLS");
							cout<<"\n\t\t\t\tTranscation declined\n";
						}
					}
				
					else//else for current account holder 
					{
						int bal=ac.retdeposit()-amt;//amount is reduced from sender account
						if(bal<0)//checking for insuffinceint balance
						{
							system("CLS");
							cout<<"\n\t\t\t\t\t\tTransaction Declined Due To";
							cout<<"\n\t\t\t\t\t\tInsufficient balance";
						}
						else
						{
							foun,rcacc=transfer_rc(temp,senacctype,accnum);//calls reciever account to recieve money
							if(foun==true && rcacc == ac.rettype())//foun is equal to boolean true then Do this
									ac.draw(amt);
							else //else deposit the amount into account of sender  
									ac.retdeposit()+amt;
						}
					}
					int pos=(-1)*static_cast<int>(sizeof(ac));//Turns the Unsigned result of the sizeof operator into a signed number and multiplies it by -1. 
					File.seekp(pos,ios::cur);//seekp() is used to move a file pointer to a desired location from current location
					File.write(reinterpret_cast<char *> (&ac), sizeof(account));//update the value on to the file
				}
			}
			else
			{
				cout<<"\n\t\t\t\tTransaction Incomplete!!";
				cout<<"\n\n\t\t\tDue to Incorrect Access PIN";
				cout<<"\n\n\t\t\tCheck Your Access PIN and Try later";
			}
			
		}
	}
	File.close();//close file when operation is done
	if(found==false)
		cout<<"\n\n\t\t\t\t\t\tEntered Account number does not Exits";
}
int bank::transfer_rc(int m,char senacctype,int accnum)//function for reciever
{
	int x;
	char rcacctype;
	bool found=false;//Declaring a boolean varialbe with false value
	account ac;
	fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);//ios::out:-open a file for writing a Data
	if(!File)//if file is not able to open properly		  //ios::in:-opens a file for reading a Data
	{
		cout<<"File could not be open !! Press any Key...";
		return -1;
	}
	cout<<"\n\t\t\t\t\t\tEnter reciever a/c no. : ";
	cin>>x;
	if(accnum!=x)
	{
		while(!File.eof() && found==false)//checking if file pointer is reached "End of File"
		{	
			File.read(reinterpret_cast<char *> (&ac), sizeof(account));//reads from a file called account
			if(ac.retacno()==x)
			{
				found=true;
				rcacctype = ac.rettype();
				if(ac.rettype() == senacctype)
				{
					ac.dep(m);  //The amount will be Deposited into account of reciever
					int pos=(-1)*static_cast<int>(sizeof(ac));//Turns the Unsigned result of the sizeof operator into a signed number and multiplies it by -1.
					File.seekp(pos,ios::cur);
					File.write(reinterpret_cast<char *> (&ac), sizeof(account));
					cout<<"\n\t\t\t\t\t\t\t\tYour Transaction is Complete";
				}	
				else if(ac.rettype() == senacctype)
				{
					ac.dep(m);  //The amount will be Deposited into account of reciever
					int pos=(-1)*static_cast<int>(sizeof(ac));//Turns the Unsigned result of the sizeof operator into a signed number and multiplies it by -1.
					File.seekp(pos,ios::cur);
					File.write(reinterpret_cast<char *> (&ac), sizeof(account));
					cout<<"\n\t\t\t\t\t\t\t\tYour Transaction is Complete";
				}
				else
				{
					system("CLS");
					cout<<"\n\t\t\tYour Transaction is Incomplete\n\t\t\tYou attemted to initiate Transfer between different account type";
					cout<<"\n\t\t\tBanking Terms:-";
					cout<<"\n\t\t\t\t\tSavings account ==> Savings account";
					cout<<"\n\t\t\t\t\tCurrent account ==> current account";
				}
			}
		}
	}
	else
	{
		cout<<"\n\t\t\t\tTransaction Incomplete\n";
		cout<<"\n\t\t\t\tSelf Transfer is Not allowed";
	}
	File.close();
	if(found==false && accnum!=x)
		cout<<"\n\n\t\t\tEntered Account number Does not Exits:(\n\t\t\tPlease try again:)";
return found,rcacctype;//returns boolean value to a transaction_sc 
}

void bank::delete_account(int n)//This function is to remove an account data from a file
{
	account ac;
	int a;
	bool flag=false;
	ifstream inFile;//Reading a input form a file 
	ofstream outFile;//used to write information to file
	inFile.open("account.dat",ios::binary);//opens a file in Binary Mode
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()==n)
		{
			flag=true;
			cout<<"\n\t\t\t\tEnter Your Access PIN: ";
			cin>>a;
			if(ac.retaccess_acc() == a)
			{
				cout<<"\n\t\t\tAccount DETAILS\n";
				ac.show_account();
				outFile.open("Temp.dat",ios::binary);//Creating a temparary file called Temp.dat and opens in binary mode
				inFile.seekg(0,ios::beg);//offsets from beginning of stream buffer
				while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))//read Through File
				{
					if(ac.retacno()!=n)
					{
						outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));//Write to Temp.dat file 
					}
				}
    			inFile.close();//close account.dat file
				outFile.close();//close Temp.dat file
				remove("account.dat");//remove account.dat file
				rename("Temp.dat","account.dat");//rename the Temp.dat to account.dat
				cout<<"\n\nclosed successfully........";
			}
			else
			{
				cout<<"\n\t\t\tIncorrect Access PIN";
			}
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\t\t\t\tAccount number not extis";
}


void bank::display_all()//This Function to display all account holder details in account.dat file
{
	system("CLS");
	account ac;
	int bankautho;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\t\t\t\tAllowed Only for Authorized Person ";
	cout<<"\n\n\t\t\t\tEnter Bank authorized code: ";
	cin>>bankautho;
	if(bankautho==accautho)
	{
		cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
		cout<<"\n\n\t\t\t\t=====================================================================================================";
		cout<<"\n\n\t\t\t\tA/c no.      NAME            Adhaar number            email ID             Type             Balance";
		cout<<"\n\n\t\t\t\t=====================================================================================================\n";
		while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
		{
			ac.report();//function call
		}
		inFile.close();
	}
	else
	{
		cout<<"\n\t\t\t\tIncorrect Code";
		cout<<"\n\t\t\t\tPlease check and try again";
	}
	inFile.close();
}


void bank::deposit_withdraw(int n, int option)//This function will Handle Deposit and withdraw related to account
{
	int amt;
	int a;
	bool found=false;//Declaring a boolean varaible as false
	account ac;
	fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);//Open a file
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));//Reading File 
		if(ac.retacno()==n)
		{
			found=true;
			cout<<"\n\n\t\t\t\tAccess PIN: ";
			cin>>a;
			if(ac.retaccess_acc()==a)
			{
				ac.show_account();//Display's account Deatils realated to account number
				if(option==1)//Depositing Money
				{
					cout<<"\n\n\t\t\tTO DEPOSITSS AMOUNT";
					cout<<"\n\n\t\t\tEnter The amount to be deposited: ";
					cin>>amt;
					ac.dep(amt);
				}
			   	if(option==2)//Withdraw Money
				{
					if(ac.rettype()=='S')
					{
						cout<<"\n\n\t\t\tTO WITHDRAW AMOUNT";
						cout<<"\n\n\t\t\tEnter The amount to be withdraw: ";
						cin>>amt;
						if(amt<=ac.retdeposit()-1000)
						{
							ac.draw(amt);
							system("CLS");
							cout<<"\n\t\t\t\tYour Transaction is  Successfully\n";
							cout<<"t\t\t\t\tThank YOU\n"<<"\t\t\t\tVisit Again\n";
						}	
						else if(amt<=1000)
						{
							system("CLS");
							cout<<"\n\t\t\t\tInsufficience balance";
							cout<<"\n\t\t\t\tPlease maintian minimum balance Amount\n";
						}
						else
						{
							system("CLS");
							cout<<"\nPlease maintain Minimum balance of INR 1000";
							cout<<"\n\t\t\t\tInsufficeint FUNDS\n";
						}
					}
					else
					{
						cout<<"\n\n\t\t\tTO WITHDRAW AMOUNT";
						cout<<"\n\n\t\t\tEnter The amount to be withdraw: ";
						cin>>amt;
						int bal=ac.retdeposit()-amt;
						if(bal<0)
						{
							cout<<"\t\t\t\t\t\t\tInsufficience balance";
						}
						else
							ac.draw(amt);
					}
				}										  //Static_cast:-It is a operator used for converting a numeric data types into "int"
				int pos=(-1)*static_cast<int>(sizeof(ac));//Turns the Unsigned result of the sizeof operator into a signed number and multiplies it by -1.
				File.seekp(pos,ios::cur);//seekp() is used to move a file pointer to a desired location from current location
				File.write(reinterpret_cast<char *> (&ac), sizeof(account));//reinterpret_cast:-it Turns one type directly into another 
				cout<<"\n\n\t\t\tBalance as been updated";//Update The File
			}
			else
			{
				cout<<"\n\t\t\tIncorrect Access PIN";
				cout<<"\n\n\t\t\tPlease try later";
			}
		}
	}
    File.close();
	if(found==false)
		cout<<"\n\n\t\t\tEnterd Account number not extis";
}
void bank::modify_acc_access()
{
	bool found=false;
	bank ob;
	int n;
	int bankautho;
	account ac;
	fstream File;
	cout<<"\n\t\t\t\tThis Modification is allowed only to a authorised person";
    File.open("account.dat",ios::binary|ios::in|ios::out);//ios::binary opens in binary mode
                                                          //ios::in is for input operation
                                                          //iso::out is for ouput operation
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\t\t\tEnter Bank Authorized Code: ";
	cin>>bankautho;
	if(bankautho == accautho)
	{
		cout<<"\n\t\t\t\tEnter Employee ID: ";
		cin>>n;
		while(!File.eof() && found==false)
		{
			File.read(reinterpret_cast<char *> (&ac), sizeof(account));
			if(ac.retacno() == n)
			{
				found=true;
				ac.modify_accessPin();//Function call
				int pos=(-1)*static_cast<int>(sizeof(account));//Static_cast:-It is a operator used for converting a numeric data types into "int"
				File.seekp(pos,ios::cur); 
		    	File.write(reinterpret_cast<char *> (&ac), sizeof(account));
		    	cout<<"\n\n\t\t\tYour access PIN changed";
			}
		}
		if(found==false)
			cout<<"\n\n\t\t\tAccount Number not found";
	}
	else
	{
		cout<<"\n\t\t\tEnter Authorized Code is incorrect";
	    cout<<"\n\t\t\tPlease Contact Authorized person to change Access PIN";
  	    cout<<"\n\t\t\tSorry please try agian";
	}
	File.close();
}
//Employees
void bank::write_employee()
{
	employee em;//created objects for employee
	ofstream outFile;//ios::out(binary)ios::binary makes the data is written without translating a newline
	outFile.open("employee.dat",ios::binary|ios::app);//creating and opening a file in binary or append mode
	em.newemployee();//Function call
	outFile.write(reinterpret_cast<char *> (&em), sizeof(employee));//write to a file
	outFile.close();//closing a file
}
void bank::display_Semp(int m)//This Function is to Display single Employee Details 
{
	employee em;
	int a;
	bool flag=false;//Setting a boolean Flag to 0
	ifstream inFile;
	inFile.open("employee.dat",ios::binary);//opening a file
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
    while(inFile.read(reinterpret_cast<char *> (&em), sizeof(employee)))
	{
		if(em.retempid()==m)
		{
			flag=true;//flag is updated to 1 if  account exits
			cout<<"\n\t\t\t\tEnter your access PIN: ";
			cin>>a;
			if(em.retaccess()==a)
			{
				cout<<"\n\t\t\tEmployee DETAILS\n";
				em.show_employee();
			}
			else
			{
				cout<<"\n\t\t\tIncorrect Access PIN";
			}
		}
	}
    inFile.close();//close a file
	if(flag==false)
		cout<<"\n\n\t\t\tEmployee ID does not exist";
	
}
void bank::modifyemployee(int m)//This function is to have any modification
{
	bool found=false;
	employee em;
	int a;
	fstream File;
    File.open("employee.dat",ios::binary|ios::in|ios::out);//ios::binary opens in binary mode
                                                          //ios::in is for input operation
                                                          //iso::out is for ouput operation
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&em), sizeof(employee));
		if(em.retempid()==m)
		{
			found=true;
			cout<<"\nEnter Access PIN: ";
			cin>>a;
			if(em.retaccess()==a)
			{
				em.show_employee();//Previous data of employee
				cout<<"\n\n\t\t\tEnter The New Details of account"<<endl;
				em.modify_emp();//Function call
				int pos=(-1)*static_cast<int>(sizeof(employee));//Static_cast:-It is a operator used for converting a numeric data types into "int"
				File.seekp(pos,ios::cur); 
		    	File.write(reinterpret_cast<char *> (&em), sizeof(employee));
		    	cout<<"\n\n\t\t\tNew Details Updated";
		    }
		    else
		    {
		    	cout<<"\n\t\t\tYour access PIN is Incorrect";
			}
		}
	}
	File.close();
	if(found==false)
		cout<<"\n\n\t\t\tEmployee not found";
}
void bank::delete_emp(int m)//This function removes a employee 
{
	employee em;
	int a;
	bool flag=false;
	ifstream inFile;//Reading a input form a file 
	ofstream outFile;//used to write information to file
	inFile.open("employee.dat",ios::binary);//opens a file in Binary Mode
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(inFile.read(reinterpret_cast<char *> (&em), sizeof(employee)))
	{
		if(em.retempid()==m)
		{
			flag=true;
			cout<<"\n\t\t\t\tEnter Your Access PIN: ";
			cin>>a;
			if(em.retaccess() == a)
			{
				cout<<"\n\t\t\tEmployee DETAILS\n";
				em.show_employee();
				outFile.open("Tem.dat",ios::binary);//Creating a temparary file called Temp.dat and opens in binary mode
				inFile.seekg(0,ios::beg);//offsets from beginning of stream buffer
				while(inFile.read(reinterpret_cast<char *> (&em), sizeof(employee)))//read Through File
				{
					if(em.retempid()!=m)
					{
						outFile.write(reinterpret_cast<char *> (&em), sizeof(employee));//Write to Temp.dat file 
					}
				}
    			inFile.close();//close account.dat file
				outFile.close();//close Temp.dat file
				remove("employee.dat");//remove account.dat file
				rename("Tem.dat","employee.dat");//rename the Temp.dat to account.dat
				cout<<"\n\nclosed successfully........";
			}
			else
			{
				cout<<"\n\t\t\tIncorrect Access PIN";
			}
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\t\t\t\tEmployee not extis";
}
		
void bank::display_emp_all()//This Function display all Employee Details
{
	system("CLS");
	employee em;
	int bankautho;
	ifstream inFile;
	inFile.open("employee.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\t\t\t\tAllowed TO only for Authorized Person";
	cout<<"\n\t\t\t\tEnter Bank Authorized Code to view Employee List: ";
	cin>>bankautho;
	if(bankautho==autho)
	{
		cout<<"\n\n\t\tEMPLOYEE'S  PROFILE LIST\n\n";
		cout<<"\n\n\t\t\t\t==================================================================================================================";
		cout<<"\n\n\t\t\t\tEmp-ID .      NAME                Adhaar number           Email ID               Date of Birth            Salary";
		cout<<"\n\n\t\t\t\t==================================================================================================================\n";
		while(inFile.read(reinterpret_cast<char *> (&em), sizeof(employee)))
		{
			em.display_emp();//Function call
		}
		inFile.close();
	}
	else
	{
		cout<<"\n\t\t\t\tIncorrect Code";
	}
	inFile.close();
}
void bank::modify_access()
{
	bool found=false;
	bank ob;
	int m;
	int bankautho;
	employee em;
	fstream File;
	cout<<"\n\t\t\t\tThis Modification is allowed only to a authorised person";
    File.open("employee.dat",ios::binary|ios::in|ios::out);//ios::binary opens in binary mode
                                                          //ios::in is for input operation
                                                          //iso::out is for ouput operation
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\t\t\tEnter Bank Authorized Code: ";
	cin>>bankautho;
	if(bankautho == autho)
	{
		cout<<"\n\t\t\t\tEnter Employee ID: ";
		cin>>m;
		while(!File.eof() && found==false)
		{
			File.read(reinterpret_cast<char *> (&em), sizeof(employee));
			if(em.retempid() == m)
			{
				found=true;
				em.modifyaccess();//Function call
				int pos=(-1)*static_cast<int>(sizeof(employee));//Static_cast:-It is a operator used for converting a numeric data types into "int"
				File.seekp(pos,ios::cur); 
		    	File.write(reinterpret_cast<char *> (&em), sizeof(employee));
		    	cout<<"\n\n\t\t\tYour access PIN changed";
			}
		}
		if(found==false)
			cout<<"\n\n\t\t\tEmployee not found";
	}
	else
	{
		cout<<"\n\t\t\tEnter Authorized Code is incorrect";
	    cout<<"\n\t\t\tPlease Contact Authorized person to change Access PIN";
  	    cout<<"\n\t\t\tSorry please try agian";
	}
	File.close();
}
//revised
