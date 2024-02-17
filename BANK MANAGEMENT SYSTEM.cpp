
//                   HEADER FILE USED IN PROJECT


#include<iostream>

#include<fstream>

#include<cctype>     /*These functions take the int equivalent of one character as parameter and return an int that can either be
                       another character or a value representing a boolean value: an int value of 0 means false, and an int value 
					   different from 0 represents true*/

#include<iomanip>     /*Sets the field width to be used on output operations.
                        Behaves as if member width were called with n as argument on the stream on which it is inserted/extracted 
						as a manipulator (it can be inserted/extracted on input streams or output streams).
                         This manipulator is declared in header <iomanip>.*/
using namespace std;



// group members
//KUDCSD201F-018
//KUDCSD201F-016
//KUDCSD201F-017

//                   CLASS USED IN PROJECT



class Account
{
    int Acno;
	char name[50];
    int deposit;
	char type;
public:
	void create_account();	//function to get data from user
	
	void show_account() const;	//function to show data on screen
	
	void dep(int);	//function to accept amount and add to balance amount
	
	void draw(int);	//function to accept amount and subtract from balance amount
	
	void report() const;	//function to show data in tabular format
	
	int ret_acno() const;	//function to return account number
	
	int ret_deposit() const;	//function to return balance amount
	
	char ret_type() const;	//function to return type of account
	
};         //class ends here

void Account::create_account()
{
    cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n\n[1]. Enter The Account No. : ";
	cin>>Acno;
	cout<<"\n\n[2]. Enter The Name Of The Account Holder : ";
	cin.ignore(); //ignore is useded clear one or more characters from the input buffer
	cin.getline(name,50);
	cout<<"\n\n[3]. Enter Type Of The Account (Special(S)/Senior Citizen(C)) : ";
	cin>>type;
	type=toupper(type); // toupper is using a lowercase letter and has an uppercase equivalent
	cout<<"\n\n[4]. Enter The Initial Amount(1000 for Saving and 5000 for current ) Rs: ";
	cin>>deposit;
	cout<<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
	cout<<"\n\n\nACCOUNT CREATED..............................";
}

void Account::show_account() const //Declaring a member function with the const keyword specifies that the function is a "read-only" 
                                   //function that does not modify the object for which it is called
{
	cout<<"\n\n\t\t\t\t(01). Account No. : "<<Acno;
	cout<<"\n\n\t\t\t\t(02).Account Holder Name : ";
	cout<<name;
	cout<<"\n\n\t\t\t\t(03).Type Of Account : "<<type;
	cout<<"\n\n\t\t\t\t(04).Balance Amount Rs: "<<deposit;
	cout<<"\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
}



	
void Account::dep(int x)
{
	deposit+=x;
}
	
void Account::draw(int x)
{
	deposit-=x;
}
	
void Account::report() const 
{
	cout<<Acno<<setw(10)<<" "<<name<<setw(10)<<" \t\t\t"<<type <<setw(6)<<" \t\t\t"<<"\tRs:"<<deposit<<endl; // setw is Sets the field 
	                                                                                                          //width to be used on output operations.
}
	
int Account::ret_acno() const
{
	return Acno;
}

int Account::ret_deposit() const
{
	return deposit;
}

char Account::ret_type() const
{
	return type;
}




//    	THE MAIN FUNCTION OF PROGRAM


 main()
{
	//    	function declaration

void write_account();	//function to write record in binary file
void delete_account(int);	//function to delete record of file
void display_all();		//function to display all account details
void deposit_withdraw(int, int); // function to desposit/withdraw amount for given account
void intro();	//introductory screen function


	
	
	
	
	
	
	char ch;
	int num;
	intro();
	do
	{
		system("cls");
		cout<<"\n\n\n\t\t\t\t\t\tMAIN MENU";
		cout<<"\n\n\t\t\t\t===================================================";
		cout<<"\n\n\t\t\t\t^\t[01.] CREATE NEW ACCOUNT                  ^";
		cout<<"\n\n\t\t\t\t^\t[02.] DEPOSIT AMOUNT                      ^";
		cout<<"\n\n\t\t\t\t^\t[03.] WITHDRAW AMOUNT                     ^";
		cout<<"\n\n\t\t\t\t^\t[04.] ALL ACCOUNT HOLDER LIST             ^";
		cout<<"\n\n\t\t\t\t^\t[05.] CLOSE AN ACCOUNT                    ^";
        cout<<"\n\n\t\t\t\t^\t[06.] EXIT                                ^";
		cout<<"\n\n\t\t\t\t===================================================";
		cout<<"\n\n\t\t\t\t\t[+].Select Your Any Option  :  ";
		cin>>ch;
		cout<<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
	
		system("cls"); //The system() function is a part of the C/C++ standard library. 
                       // It is used to pass the commands that can be executed in the command processor or the terminal of the operating 
					    // system, and finally returns the command after it has been completed.              
		switch(ch)
		{
		case '1':
			write_account();
			break;
		case '2':
			cout<<"\n\n\t[1]. Enter The Account No. : "; cin>>num;cout<<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
			deposit_withdraw(num, 1);
			break;
		case '3':
			cout<<"\n\n\t[1]. Enter The Account No. : "; cin>>num;cout<<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
			deposit_withdraw(num, 2);
			break;
		case '4':
			display_all();
			break;
		case '5':
			cout<<"\n\n\t[1]. Enter The Account No. : "; cin>>num;cout<<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
			delete_account(num);
			break;
		 
		 case '6':       
		  cout<<"\n\n\t\t\t\t=================================================";
		  cout<<"\n\n\t\t\t\t|                  THANKS                       |";	
	      cout<<"\n\n\t\t\t\t|                   FOR                         |";
	      cout<<"\n\n\t\t\t\t|                  USING                        |";
	      cout<<"\n\n\t\t\t\t|                   BANK                        |";
          cout<<"\n\n\t\t\t\t|                MANAGEMENT                     |";
		  cout<<"\n\n\t\t\t\t|                 SYSTEM....!!!                 |";
		  cout<<"\n\n\t\t\t\t=================================================";
			break;
		 default :cout<<"\a";
		}
		cin.ignore();// ignore() function is used which is used to ignore or clear one or more characters from the input buffer.
		cin.get();
    }while(ch!='8');
	return 0;
}



//    	function to write in file

void write_account()
{
	Account Ac;
	ofstream outFile;
	outFile.open("Account.dat",ios::binary|ios::app); // ios::binary	Open in binary mode. ios::app All output operations are performed at the end of the file, appending the 
	                                                    //content to the current content of the file.
	Ac.create_account();
	outFile.write(reinterpret_cast<char *> (&Ac), sizeof(Account));
	outFile.close();
}

void delete_account(int c)
{
	Account Ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("Account.dat",ios::binary);
	if(!inFile)
	{   
	    cout<<endl;
	    cout<<endl;
		cout<<"File Could Not Be Open !! Press Enter  Key...!";
		cout<<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg); //offset from the beginning of the stream's buffer
	while(inFile.read(reinterpret_cast<char *> (&Ac), sizeof(Account)))//Reads the Account structure data directly from a file into the memory occupied by ac . 
	                                                               //  cast is because read expects a char* , and this is how you convert a pointer 
                                                               // of one type to a pointer of a completely unrelated type.
	{
		if(Ac.ret_acno()!=c)
		{
			outFile.write(reinterpret_cast<char *> (&Ac), sizeof(Account));
		}
	}
    inFile.close();
	outFile.close();
	remove("Account.dat");
	rename("Temp.dat","Account.dat");
	cout<<endl;
	cout<<endl;
	cout<<"\n\n\tRecord Deleted......!";
	cout<<"\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
}


//    	function to display all accounts deposit list


void display_all()
{
	Account Ac;
	ifstream inFile;
	inFile.open("Account.dat",ios::binary);
	if(!inFile)
	{   
	    cout<<endl;
	    cout<<endl;
		cout<<"File Could Not Be Open !! Press Enter  Key...!";
		cout<<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
		return;
	}
	cout<<"\n\n\t\t\t\t\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n\n|A/C No:      \t\tNAME           \t\tAC Type Special(S)\\Senior Citizen(C)   \t\tBalance(Rs:)\n\t";
	cout<<"\n------------------------------------------------------------------------------------------------------------------------\n";
	while(inFile.read(reinterpret_cast<char*  >(& Ac),sizeof( Account)))//Reads the Account structure data directly from a file into the memory occupied by ac . 
	                                                               //  cast is because read expects a char* , and this is how you convert a pointer 
                                                               // of one type to a pointer of a completely unrelated type.
		{
	
		
		Ac.report();
	}
	inFile.close();
}


//    	function to deposit and withdraw amounts


void deposit_withdraw(int n, int option)
{
	int amt;
	bool found=false;
	Account Ac;
	fstream File;
    File.open("Account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{  
	    cout<<endl;
	    cout<<endl;
		cout<<"File Could Not Be Open !! Press Enter  Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&Ac), sizeof(Account));
		if(Ac.ret_acno()==n)
		{
			Ac.show_account();
			if(option==1)
			{
				cout<<"\n\n\tTO DEPOSITE AMOUNT ";
				cout<<"\n\n<01>. Enter The Amount To Be Deposited  Rs:";
				cin>>amt;
				Ac.dep(amt);
			}
		    if(option==2)
			{
				cout<<"\n\n\tTO WITHDRAW AMOUNT ";
				cout<<"\n\n<01>. Enter The Amount To Be Withdraw Rs:";
				cin>>amt;
			    int bal=Ac.ret_deposit()-amt;
				if((bal<500 && Ac.ret_type()=='S') || (bal<1000 && Ac.ret_type()=='C'))
					cout<<endl;
					cout<<endl;
					cout<<"Insufficience Balance...!!!!";
			}
				else{
					
				
					Ac.draw(amt);
		      }
			int pos=(-1)*static_cast<int>(sizeof(Ac));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&Ac), sizeof(Account));
			cout<<endl;
			cout<<endl;
			cout<<"\n\n\t Record Updated......!";
			cout<<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
			found=true;
	       }
         }
    File.close();
	if(found==false)
	    cout<<endl;
	    cout<<endl;
		cout<<"\n\n RECORD NOT FOUND...!!! ";
		cout<<"\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
}


//    	INTRODUCTION FUNCTION


void intro()
{         
           cout<<"\n\t\t\t\t\t=================================================";
		  cout<<"\n\t\t\t\t\t!                   BANK                        !";	
	      cout<<"\n\t\t\t\t\t!                                               !";
	      cout<<"\n\t\t\t\t\t!                                               !";
	      cout<<"\n\t\t\t\t\t!                                               !";
          cout<<"\n\t\t\t\t\t!                MANAGEMENT                     !";
		  cout<<"\n\t\t\t\t\t!                                               !";
		  cout<<"\n\t\t\t\t\t!                                               !";
		  cout<<"\n\t\t\t\t\t!                                               !";
		  cout<<"\n\t\t\t\t\t!                  SYSTEM........               !";
		  cout<<"\n\t\t\t\t\t================================================="; 
	   
	      cout<<"\n\n\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
		  cout<<"\n\n\n\t\t\t\t\t\tPress Enter Key To Continue....!";
          cout<<"\n\n\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
	    
	cin.get();
}


//    			END OF PROJECT	 