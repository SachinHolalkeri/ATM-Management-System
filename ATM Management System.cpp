#include<fstream>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include<windows.h>
#include<unistd.h>
#include <bits/stdc++.h> 
#include <sstream>
#include<vector>
#include<unordered_map>
#include<graphics.h>
#include<list>
using namespace std;
    void punit (void);
    void deposit(void);
    int addrecord();
    int delrecord();
    void modrecord();
    void disprecord();
    void dispall();
    void withdraw();
    int login();
    vector<int> encoding(string s1);
    void decoding(vector<int> op);
    void dcbff();
    void payment();
    void transfer();
    void ta(int a,int m);
    void hashdata();
    void delhash(int mrno);
    void foreexch();
    int elogin(int acc);
    int d=0,l;
   	float w,z;
   	
class account
{
    public:
	int accountno,cls,pwd;
    char name[30],type;
    float deposit,withdraw;
  
	public:
            account()
 			{
                deposit=withdraw=0;
    		}
            
			int giveaccountno()
 			{
                return accountno;
    		}
    		
			int givepin()
    		{
    			return pwd;
			}
    
            void getdata(int mrno)
 			{
                accountno=mrno+1;
                cout<<endl<<endl<<"ACCOUNT NUMBER        ::  ";
                cout<<accountno<<"\n"<<endl;
	        	cout<<"ENTER YOUR NAME       ::  ";
	        		cin>>name;cout<<endl;
	        	dis:
				cout<<"ENTER TYPE OF ACCOUNT SAVING(s)/CURRENT(c)  ::  ";
	        		cin>>type;cout<<endl;
	        	
	        		switch(type)
	        		{
	        			case 'c':break;
	        			case 's':break;
	        			case 'C':break;
	        			case 'S':break;
	        			default: goto dis;
					}
				
	        	cout<<"ENTER A 5 DIGIT PIN   ::  ";
				   	cin>>pwd;cout<<endl;
				
				while(true)
				{
					int size=trunc(log10(pwd))+1;
					if(size==5)
						break;
					else
					{
						cout<<"ENTER A 5 DIGIT PIN   ::  ";
				   	cin>>pwd;cout<<endl;
					}
				}
	        	cout<<"ENTER INITIAL AMOUNT  ::Rs  ";
					cin>>deposit;cout<<endl;
  			}
            
			void withdrawal(int m)
   			{
   				if(m>deposit)
   				{
   					cout<<"NOT ENOUGH BALANCE!!!"<<endl;
				}
				else
				{
				    cout<<"AMOUNT BEFORE WITHDRAWING::Rs  "<<deposit<<"\n\n";
      				deposit=deposit-m;
                	cout<<"AMOUNT AFTER WITHDRAWING::Rs  "<<deposit;
            	}
    		}
    		
    		void pay(int m)
    		{
    			if(m>deposit)
    			{
    				cout<<"NOT ENOUGH BALANCE!!!"<<endl;
    			}
				else
				{
					deposit=deposit-m;
					cout<<"PAYMENT SUCCESSFUL!!"<<endl<<endl;
					cout<<"YOUR CURRENT BALANCE IS:"<<deposit<<endl;
				}
			}
                
			void deposital(int m)
 			{
                cout<<"AMOUNT BEFORE DEPOSIT::Rs  "<<deposit<<"\n\n";
    			deposit=deposit+m;
                cout<<"AMOUNT AFTER DEPOSIT ::Rs  "<<deposit<<endl;
  			}
            
			void dispdata()
   			{
				int scrnt=0;
                if(scrnt==1)
    			{
      				system("cls");
                   	cout<<"\n\t\t\t\t\t\t\t\t\tDISPLAY ALL MENU ";
    				scrnt=0;
  				}
                cout<<endl<<endl<<"ACCOUNT NUMBER              ::  ";
                cout<<accountno<<endl<<endl;
                cout<<"NAME OF DEPOSITER           ::  ";
                cout<<name<<endl<<endl;
                cout<<"TYPE OF ACCOUNT             ::  ";
                cout<<type<<endl<<endl;
                cout<<"BALANCE                     ::  Rs ";
                cout<<deposit<<endl<<endl;
                
    			scrnt++;
     		}
     		
     		void trans(int m)
     		{
     			deposit+=m;	
			}
     		
};

// CPP program to implement hashing with chaining 
class Hash:public account
{ 
	int BUCKET; // No. of buckets 

	// Pointer to an array containing buckets 
	list<long int> *table; 
public: 
	Hash(int V); // Constructor 

	// inserts a key into hash table 
	void insertItem(long int x); 

	// hash function to map values to key 
	int hashFunction(long int x) { 
		return (x % BUCKET); 
	} 
 
}; 

Hash::Hash(int b) 
{ 
	this->BUCKET = b; 
	table = new list<long int>[BUCKET]; 
} 

void Hash::insertItem(long int key) 
{ 
	int index = hashFunction(key); 
	table[index].push_back(key); 
	ofstream myFile("hashdata.txt",ios::app);
    list <long int> :: iterator i; 
	for (i = table[index].begin(); i != table[index].end(); i++) 
	{ 
		if (*i == key) 
			myFile<<key<<endl; 
	}
	myFile.close();	 
} 
  
int main()
{
	int menuch,ch,useless=0;
	int rv;
	Hash h(7);
    do
	{
	    system("cls");
		cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\t\tWELCOME to SCE ATM\n\n\n\n\n\n 1.EXISTING ACCOUNT\n\n 2.NEW ACCOUNT\n\n 3.EXIT\n\n\n\n ENTER YOUR CHOICE: ";cin>>ch;
		switch(ch)
		{
			case 1:useless=login();
					if(useless==1)
					{      
	                    do
	    				{
	                    	system("cls");
	                    
		                    cout<<"\n\t\t\t\t\t\t\t\t\t\tMAIN MENU\n\n\n\n";
		                    cout<<"  1.ACCOUNT INFO\n"<<endl;
		                    cout<<"  2.DISPLAY ALL RECORDS\n"<<endl;
		                    cout<<"  3.WITHDRAW AMOUNT\n"<<endl;
		                    cout<<"  4.DEPOSIT AMOUNT\n"<<endl;
		                    cout<<"  5.CLOSE ACCOUNT\n"<<endl;
		                    cout<<"  6.MODIFY ACCOUNT\n"<<endl;
		                    cout<<"  7.ONLINE PAYMENT\n"<<endl;
		                    cout<<"  8.TRANSFER AMOUNT\n"<<endl;
		                    cout<<"  9.FOREIGN EXCHANGE\n"<<endl;
		                    cout<<"  10.EXIT\n"<<endl<<endl;
		                    cout<<"  ENTER YOUR CHOICE  ";
	      						cin>>menuch;
	
	                        switch(menuch)
	    					{
			                    case 5:rv=delrecord();break;
			                    case 6:modrecord();break;
			                    case 1:disprecord();break;
			                    case 2:dispall();break;
			                    case 3:withdraw();break;
			                    case 4:deposit();break;
			                    case 7:payment();break;
			                    case 8:transfer();break;
			                    case 9:foreexch();break;
	    					}
	  					}while(menuch<=9);
	                    break;
	     			}
		  			break;
	      	case 2:rv=addrecord();
	      			cout<<rv;
	      			h.insertItem(rv);
	      			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			  		break;
		  	default: hashdata(); 
			  		cout<<endl<<endl<<"PLEASE VISIT AGAIN!!!"<<endl<<endl<<endl;
		}
	}while(ch<=2);
	
	std::ifstream inFile;
    inFile.open("banking.txt"); //open the input file
    std::stringstream strStream;
    strStream << inFile.rdbuf(); //read the file
    std::string str = strStream.str(); //str holds the content of the file
	inFile.close();
    vector<int> myvector;
    myvector=encoding(str);
    ofstream myFile("file.txt");
    for(int i=0;i<myvector.size(); i++)
    {
    	myFile<<myvector[i]<<endl;
	}
	
	myFile.close();
	return 0;
} 


int addrecord()
{
    account obj_1,obj_2;
    fstream fout;
    ofstream file;
	int mrno=100;                         	
    fout.open("banking.txt",ios::in);
    if(!fout)
  	{
        file.open("banking.txt");
           	file.close();
	}
    int recsize=sizeof(account);
    fout.seekg(0,ios::end);
    fout.seekg(-1*recsize,ios::cur);
    fout.read((char*)&obj_1,recsize);
	mrno=obj_1.giveaccountno();	
    fout.close();
	system("cls");
    cout<<"\n\t\t\t\t\t\t\t\t\t\tADD MENU\n\n\n\n";
 	obj_2.getdata(mrno);
    fout.open("banking.txt",ios::out|ios::app);
 	if(!fout)
	{
        cout<<"FILE OPEN ERROR  ";
		getch();
		return mrno;
	}
  	fout.write((char*)&obj_2,recsize);
    cout<<endl<<"Account created"<<endl<<endl<<" Press any key to continue... ";
  	getch();
    fout.close();
    return mrno+1;
}
                
void dispall()
{
    account obj_3;
    fstream fout;
    int recsize=sizeof(account);
    int countrec=0;
    system("cls");
    cout<<"\n\t\t\t\t\t\t\t\t\t\tDISPLAY ALL MENU\n\n"<<endl<<endl;
    fout.open("banking.txt",ios::in);
    if(!fout)
  	{
        cout<<"FILE OPEN ERROR  ";
		getch();
		return;
	}
    while(fout.read((char*)&obj_3,recsize))
  	{
        obj_3.dispdata();
    	countrec++;
        cout<<endl<<" PRESS ANY KEY FOR NEXT....";
     	getch();
  	}
    cout<<endl<<endl<<"END OF FILE.\n\n\n\nTOTAL NUMBER OF RECORDS...     "<<countrec<<endl<<endl;
    cout<<"Press any key......";
    getch();
    fout.close();
}
    
void disprecord()
{
    account obj_4;
    fstream fout;
    int mrno,flag=0;
    int recsize=sizeof(account);
    system("cls");
    cout<<"\n\t\t\t\t\t\t\t\t\tDISPLAY A RECORD MENU\n\n"<<endl<<endl;
    fout.open("banking.txt",ios::in);
    if(!fout)
   	{
        cout<<"FILE OPEN ERROR  ";
		getch();
		return;
	}
    cout<<"ENTER THE ACCOUNT NUMBER  ";cin>>mrno;
    int useless=0;
    useless=elogin(mrno);
    if(useless!=1)
    	return;
 	while(fout.read((char*)&obj_4,recsize))
	{
 		if (obj_4.giveaccountno()==mrno)
		{
            obj_4.dispdata();
            cout<<endl<<endl<<"Press any key.....";
    		flag=1;break;
		}
	}
 	if(flag==0)
	{
        cout<<"NO SUCH ACCOUNT EXISTS  ";
 		cout<<"Press any key......";
	}
    getch();
	fout.close();
}
 
int login()
{
    account obj_11;
    fstream fout;
	int mrno,pw,p,status=0,c=0;
    int recsize=sizeof(account);              
    system("cls");
    cout<<"\n\t\t\t\t\t\t\t\t\tINSERT YOUR CARD\n\n\n"<<endl;
    fout.open("banking.txt",ios::in);
    if(!fout)
   	{
        cout<<"FILE OPEN ERROR  ";
		getch();
		return 0;
	}
    cout<<" ENTER THE ACCOUNT NUMBER  ";cin>>mrno;
    cout<<"\n\n ENTER THE PIN  ";cin>>pw;
    p=pw;
	while(p!=0)
	{
    	p=p/10;
    	c++;
	}
	if(c==5)
	{   
		while(fout.read((char*)&obj_11,recsize))
		{
 			if((obj_11.giveaccountno()==mrno)&&(obj_11.givepin()==pw))
			{
            	cout<<"\nWelcome to your account \" "<<obj_11.name<<" \" !";
                cout<<endl<<endl<<"Press any key.....";
 				status=1;
				 break;
			}
		}
	}
 	if(status==0)
	{
        cout<<"NO SUCH ACCOUNT EXIST  ";
 		cout<<"Press any key......";
	}
    getch();
    return status;
    fout.close();
}
 
int delrecord()
{
    account obj_5;
    fstream fout,temp;
    int mrno,flag;
	int recsize=sizeof(account);
	system("cls");
    cout<<"\n\t\t\t\t\t\t\t\t\tCLOSE ACCOUNT MENU\n\n"<<endl<<endl;
    fout.open("banking.txt",ios::in);
    if(!fout)
 	{
        cout<<"FILE OPEN ERROR  ";
        getch();
        return mrno;
    }
    temp.open("temp.txt",ios::app|ios::binary);
    if(!temp)
 	{
        cout<<"FILE OPEN ERROR  ";
    	getch();
     	return mrno;
  	}
    cout<<" ENTER THE ACCOUNT NUMBER ";
    cin>>mrno;
    int useless=0;
    useless=elogin(mrno);
    if(useless!=1)
    	return mrno;
    while(fout.read((char*)&obj_5,recsize))
   	{
        if(obj_5.giveaccountno()==mrno)
 		{
            obj_5.dispdata();
            char confirm;
            cout<<endl<<endl<<"ARE YOU SURE TO DELETE IT(Y/N)..";
				cin>>confirm;
      		if(confirm=='Y'||confirm=='y')
 			{
                fout.read((char*)&obj_5,recsize);
            	cout<<endl<<endl<<"Your account has been removed";
                cout<<endl<<endl<<"press any key....";
                flag=1;
                d=1;
                delhash(mrno);
                if(!fout)
                	 break;
      		}
            flag=1;
     	}
   		temp.write((char*)&obj_5,recsize);
	}
    fout.close();
	temp.close();
    remove("banking.txt");
    rename("temp.txt","banking.txt");
    if(flag==0)
	{
        cout<<"NO SUCH ACCOUNT EXIST";
        cout<<"Press any key.....";
	}
 	getch();
 	return mrno;
}

void modrecord()
{
    account obj_6;
    fstream fout;
    int mrno,flag=0;
    int recsize=sizeof(account);
    system("cls");
    cout<<"\n\t\t\t\t\t\t\t\t\tMODIFY RECORD MENU\n\n"<<endl<<endl;
    fout.open("banking.txt",ios::in|ios::out|ios::binary);
    if(!fout)
 	{
        cout<<"FILE OPEN ERROR  ";
        getch();
        return;
    }
    fout.seekg(ios::beg);
    cout<<"ENTER ACCOUNT NUMBER  ";
    cin>>mrno;
    int useless=0;
    useless=elogin(mrno);
    if(useless!=1)
    	return;
    while(fout.read((char*)&obj_6,recsize))
  	{
        if(obj_6.giveaccountno()==mrno)
  		{
            system("cls");
        	cout<<endl<<"\n\t\t\t\t\t\t\t\t\tMODIFY MENU\n\n\n"<<endl;
            obj_6.dispdata();
      		int tmprno=obj_6.giveaccountno()-1;
            account obj_7;
            cout<<endl<<" ENTER NEW DATA";
            obj_7.getdata(tmprno);
            char confirm;
      		cout<<" ARE YOU SURE(Y/N)";
            cin>>confirm;
     		if(confirm=='Y'||confirm=='y')
 			{
                fout.seekg(-1*recsize,ios::cur);
                fout.write((char*)&obj_7,recsize);
	            cout<<endl<<" Account details modified  ";
                cout<<endl<<endl<<"Press any key.....";
                flag=1;
  			}
     	}
        if(flag==0)
 		{
            cout<<"NO SUCH RECORD EXIST";
            cout<<"Press any key.....";
   		}
    }
    fout.close();
    getch();
}

void withdraw()
{
    account obj_9;
    fstream fout;
    int mrno=0;
	int recsize=sizeof(account);
    system("cls");
    cout<<endl<<endl<<"\n\t\t\t\t\t\t\t\t\tWITHDRAWAL MENU\n\n\n\n";
    fout.open("banking.txt",ios::in|ios::out|ios::binary);
    if(!fout)
    {
        cout<<"FILE OPEN ERROR  ";
		getch();
		return;
	}
	fout.seekg(ios::beg);
    cout<<endl<<endl<<"ENTER ACCOUNT NUMBER  ";
  	cin>>mrno;
  	int useless=0;
    useless=elogin(mrno);
    if(useless!=1)
    	return;
    while(fout.read((char*)&obj_9,recsize))
 	{
    	if(obj_9.giveaccountno()==mrno)
      	{
            cout<<"\n\n\n\nENTER THE AMOUNT TO BE WITHDRAWED::Rs ";
    			cin>>w;cout<<endl<<endl;
            obj_9.withdrawal(w);
            fout.seekg(-1*recsize,ios::cur);
            fout.write((char*)&obj_9,recsize);
  		}
    }
    fout.close();
    getch();
}

void payment()
{
    account obj_13;
    fstream fout;
    bool qwe;
    int mrno=0,pch;
    char pt;
	int recsize=sizeof(account);
    system("cls");
    cout<<endl<<endl<<"\n\t\t\t\t\t\t\t\t\tPAYMENT MENU\n\n\n\n";
    fout.open("banking.txt",ios::in|ios::out|ios::binary);
    if(!fout)
    {
        cout<<"FILE OPEN ERROR  ";
		getch();
		return;
	}
	fout.seekg(ios::beg);
    cout<<endl<<endl<<"ENTER ACCOUNT NUMBER  ";
  	cin>>mrno;
  	int useless=0;
    useless=elogin(mrno);
    if(useless!=1)
    	return;
    while(fout.read((char*)&obj_13,recsize))
 	{
    	if(obj_13.giveaccountno()==mrno)
      	{
            system("cls");
            cout<<"\n\t\t\t\t\t\t\t\t\tPAYMENT OPTIONS\n\n\n\n 1.ELECTRICITY\n\n 2.WATER\n\n 3.MOBILE TOP-UP\n\n 4.INSURANCE PREMIUM\n\n 5.TAX PAYMENT\n\n ENTER YOUR OPTION";
            cin>>pch;cout<<endl<<endl;
            cout<<"ENTER THE AMOUNT TO BE PAYED::Rs ";
    			cin>>w;
            obj_13.pay(w);
            fout.seekg(-1*recsize,ios::cur);
            fout.write((char*)&obj_13,recsize);
  		}
    }
    fout.close();
    getch();
}

void deposit(void)
{
    account obj_10;
    fstream fout;
    int mrno=0;
    int recsize=sizeof(account);
    system("cls");
    cout<<endl<<endl<<"\n\t\t\t\t\t\t\t\t\tDEPOSITAL MENU\n\n\n\n";
    fout.open("banking.txt",ios::in|ios::out|ios::binary);
	if(!fout)
 	{
        cout<<"FILE OPEN ERROR  ";
		getch();
		return;
	}
	fout.seekg(ios::beg);
    cout<<endl<<endl<<"ENTER ACCOUNT NUMBER  ";
    cin>>mrno;
    int useless=0;
    useless=elogin(mrno);
    if(useless!=1)
    	return;
    while(fout.read((char*)&obj_10,recsize))
	{
  		if(obj_10.giveaccountno()==mrno)
		{
 			cout<<"\n\n\n\nENTER THE AMOUNT YOU ARE DEPOSITING ::Rs ";
				cin>>w;cout<<endl<<endl;
  			obj_10.deposital(w);
			fout.seekg(-1*recsize,ios::cur);
  			fout.write((char*)&obj_10,recsize);
		}
 	}
	fout.close();
 	getch();
}

void transfer()
{
    account obj_14;
    fstream fout;
    int mrno=0,ra=0;
	int recsize=sizeof(account);
    system("cls");
    cout<<endl<<endl<<"\n\t\t\t\t\t\t\t\t\tTRANSFER MENU\n\n\n\n";
    fout.open("banking.txt",ios::in|ios::out|ios::binary);
    if(!fout)
    {
        cout<<"FILE OPEN ERROR  ";
		getch();
		return;
	}
	fout.seekg(ios::beg);
    cout<<endl<<endl<<"ENTER ACCOUNT NUMBER  ";
  	cin>>mrno;
  	int useless=0;
    useless=elogin(mrno);
    if(useless!=1)
    	return;
    while(fout.read((char*)&obj_14,recsize))
 	{
    	if(obj_14.giveaccountno()==mrno)
      	{
            cout<<"\nENTER THE RECEPIENT ACCOUNT NUMBER: ";
            	cin>>ra;
            cout<<"\nENTER THE AMOUNT TO BE TRANSVERED  ::Rs ";
    			cin>>w;
            obj_14.withdrawal(w);
            fout.seekg(-1*recsize,ios::cur);
            fout.write((char*)&obj_14,recsize);
            ta(ra,w);
            cout<<"\n\n\nAmount Transfered Successfully!!";
  		}
    }
    fout.close();
    getch();
}

void ta(int a,int m)
{
    account obj_15;
    fstream fout;
    int mrno=0,money=0;
    int recsize=sizeof(account);
    fout.open("banking.txt",ios::in|ios::out|ios::binary);
	if(!fout)
 	{
		getch();
		return;
	}
	fout.seekg(ios::beg);
    mrno=a;
    while(fout.read((char*)&obj_15,recsize))
	{
  		if(obj_15.giveaccountno()==mrno)
		{
			money=m;
  			obj_15.trans(money);
			fout.seekg(-1*recsize,ios::cur);
  			fout.write((char*)&obj_15,recsize);
		}
 	}
	fout.close();
 	getch();
}
    
vector<int> encoding(string s1) 
{ 
	unordered_map<string, int> table; 
	for (int i = 0; i <= 255; i++) { 
		string ch = ""; 
		ch += char(i); 
		table[ch] = i; 
	} 

	string p = "", c = ""; 
	p += s1[0]; 
	int code = 256; 
	vector<int> output_code; 
	
	for (int i = 0; i < s1.length(); i++) 
	{ 
		if (i != s1.length() - 1) 
			c += s1[i + 1]; 
		if (table.find(p + c) != table.end())
		{ 
			p = p + c; 
		} 
		else 
		{ 
			output_code.push_back(table[p]); 
			table[p + c] = code; 
			code++; 
			p = c; 
		} 
		c = ""; 
	} 
	cout << p << "\t" << table[p] << endl; 
	output_code.push_back(table[p]); 
	return output_code; 
} 

void decoding(vector<int> op) 
{ 
	unordered_map<int, string> table; 
	for (int i = 0; i <= 255; i++) 
	{ 
		string ch = ""; 
		ch += char(i); 
		table[i] = ch; 
	} 
	int old = op[0], n; 
	string s = table[old]; 
	string c = ""; 
	c += s[0]; 
	cout << s; 
	int count = 256; 
	for (int i = 0; i < op.size() - 1; i++) 
	{ 
		n = op[i + 1]; 
		if (table.find(n) == table.end()) 
		{ 
			s = table[old]; 
			s = s + c; 
		} 
		else 
		{ 
			s = table[n]; 
		} 
		cout << s; 
		c = ""; 
		c += s[0]; 
		table[count] = table[old] + c; 
		count++; 
		old = n; 
	} 
}

void dcbff()
{
	ifstream fileIn("file.txt"); // fileName is not a good name for a file!
    if(!fileIn.is_open())
    {
        cout << "Failed to open file!\n";
        return;
    }
    string data;           
    vector<string> myVec;  
    while (fileIn >> data) 
    {
        myVec.push_back(data);
    }
    return;
}	

void hashdata()
{
	list<long int> *tab;
	tab = new list<long int>[7];
	int key;
	ifstream fileIn("hashdata.txt"); // fileName is not a good name for a file!
    if(!fileIn.is_open())
    {
        cout << "Failed to open file!\n";
        return;
    }
    while(fileIn>>key)
    {
    	int index = key % 7; 
		tab[index].push_back(key);
	}
    for (int i = 0; i < 7; i++) 
	{ 
		cout << i; 
		for (auto x : tab[i]) 
			cout << " --> " << x; 
		cout << endl; 
	}
    return;
}

void delhash(int mrno)
{
    int a[100],i=0,cnt=0;
    list<long int> *tab;
	tab = new list<long int>[7];
	fstream fout;
	int key;
    fout.open("hashdata.txt");
    while(fout>>key)
    {
    	if(key!=mrno)
    	{
    		a[i]=key;
    		i++;cnt++;
		}
	}
	fout.close();
	remove("hashdata.txt");
	for(i=0;i<cnt;i++)
	{
		int index = a[i] % 7; 
		tab[index].push_back(a[i]); 
		ofstream myFile("hashdata.txt",ios::app);
	    list <long int> :: iterator j; 
		for (j = tab[index].begin(); j != tab[index].end(); j++) 
		{ 
			if (*j == a[i]) 
				myFile<<a[i]<<endl; 
		}
		myFile.close();
	}	
}

void foreexch()
{
	account obj_20;
    fstream fout;
    int mrno=0,cur,o;
    int recsize=sizeof(account);
    system("cls");
    cout<<endl<<endl<<"\n\t\t\t\t\t\t\t\t\tFOREIGN EXCHANGE MENU\n\n\n\n";
    fout.open("banking.txt",ios::in|ios::out|ios::binary);
	if(!fout)
 	{
        cout<<"FILE OPEN ERROR  ";
		getch();
		return;
	}
	fout.seekg(ios::beg);
    cout<<endl<<endl<<"ENTER ACCOUNT NUMBER  ";
    cin>>mrno;
    int useless=0;
    useless=elogin(mrno);
    if(useless!=1)
    	return;
    while(fout.read((char*)&obj_20,recsize))
	{
  		if(obj_20.giveaccountno()==mrno)
		{
			cout<<"\n\n\n 1.DOLLAR\n\n 2.POUND\n\n 3.EURO\n\n 4.RUBLE\n\n 5.YEN\n\n\n ENTER YOUR CHOICE : ";
				cin>>cur;cout<<endl;
			switch(cur)
			{
				case 1:cout<<"ENTER THE AMOUNT TO BE WITHDRAWED IN $ : ";
						cin>>l;cout<<endl<<endl;o=l;cout<<"1 DOLLAR = 75.83 RUPEES"<<endl<<endl;
  						l=l*75.83;o=o*0.07;
  						l+=o;
  						l+=1;cout<<"TRANSACTION CHARGES Rs :: "<<o+1<<endl<<endl;
  						obj_20.withdrawal(l);break;
  				case 2:cout<<"ENTER THE AMOUNT TO BE WITHDRAWED IN POUNDS : ";
						cin>>l;cout<<endl<<endl;o=l;cout<<"1 POUND = 92.42 RUPEES"<<endl<<endl;
  						l=l*92.42;o=o*0.08;
  						l+=o;l+=1;cout<<"TRANSACTION CHARGES Rs :: "<<o+1<<endl<<endl;
  						obj_20.withdrawal(l);break;
  				case 3:cout<<"ENTER THE AMOUNT TO BE WITHDRAWED IN EUROS : ";
						cin>>l;cout<<endl<<endl;o=l;cout<<"1 EURO = 82.80 RUPEES"<<endl<<endl;
  						l=l*82.80;o=o*0.2;
  						l+=o;l+=1;cout<<"TRANSACTION CHARGES Rs :: "<<o+1<<endl<<endl;
  						obj_20.withdrawal(l);break;
  				case 4:cout<<"ENTER THE AMOUNT TO BE WITHDRAWED IN RUBLE : ";
						cin>>l;cout<<endl<<endl;o=l;cout<<"1 RUBLE = 1.05 RUPEES"<<endl<<endl;
  						l=l*1.05;o=o*0.05;
  						l+=o;l+=1;cout<<"TRANSACTION CHARGES Rs :: "<<o+1<<endl<<endl;
  						obj_20.withdrawal(l);break;
  				case 5:cout<<"ENTER THE AMOUNT TO BE WITHDRAWED IN YEN : ";
						cin>>l;cout<<endl<<endl;o=l;cout<<"1 YEN = 0.71 RUPEES"<<endl<<endl;
  						l=l*0.71;
  						o=o*0.09;
  						l+=o;l+=1;cout<<"TRANSACTION CHARGES Rs :: "<<o+1<<endl<<endl;
  						obj_20.withdrawal(l);break;
  				default:cout<<"Wrong choice....";
			}
			fout.seekg(-1*recsize,ios::cur);
  			fout.write((char*)&obj_20,recsize);
		}
 	}
	fout.close();
 	getch();
}

int elogin(int acc)
{
    account obj_11;
    fstream fout;
	int mrno,pw,p,status=0,c=0;
    int recsize=sizeof(account);              
    fout.open("banking.txt",ios::in);
    if(!fout)
   	{
        cout<<"FILE OPEN ERROR  ";
		getch();
		return 0;
	}
	mrno=acc;
    cout<<"\n\n ENTER THE PIN  ";cin>>pw;
    p=pw;
	while(p!=0)
	{
    	p=p/10;
    	c++;
	}
	if(c==5)
	{   
		while(fout.read((char*)&obj_11,recsize))
		{
 			if((obj_11.giveaccountno()==mrno)&&(obj_11.givepin()==pw))
			{
 				status=1;
				 break;
			}
		}
	}
 	if(status==0)
	{
        cout<<"INCORRECT PIN!!\n\n";
 		cout<<"Press any key......";
	}
    getch();
    return status;
    fout.close();
}
