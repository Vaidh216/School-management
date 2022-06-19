//***************************************************
//*************PROJECT ON FEE MANAGEMENT*************
//***************************************************
//*************HEADER FILES ARE INCLUDED*************
#include<bits/stdc++.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
// #include<fstream.h>
#include<dos.h>
// #include<iomanip.h>

using namespace std;

//*******************************************************
//**************CLASS TO DRAW LINES**********************
//*******************************************************


//*****************************************************************
//*********CLASS TO MANAGE FEE COLLECTION AND GENERATION***********
//*****************************************************************

class sfee
{

		char paid;
		int adm;
	public:
	int cl,term;
		void gfee(int a,int d,int t)
		{
			adm=a;
			cl=d;
			term=t;
			paid='N';
		}

		int chfee(int t,int a)
		{
			if(adm==a&&term==t)
				return 1;
			else
				return 0;
		}
		void upfee()
		{
			paid='Y';
		}
		int retad()
		{
			return adm;
		}
		int retterm()
		{
			return term;
		}
		char retpaid()
		{
			return paid;
		}
}sf;


//***************FUNCTIONS MANAGING STUDENT INFO***************

void add();
void del();
void modify();


//*************************************************************
//*****************CLASS TO MANAGE STUDENT INFO****************
//*************************************************************

class student
{
	public:
		char name[20],address[30],ph[30],fathername[30],mothername[30];
		char sec;
		int admno,cls;
		void enter()
		{
			cout<<"\n\t\t Enter the admission number   :   ";
			cin>>admno;
			cout<<"\n\t\t Enter the Name               :   ";
			gets(name);
			cout<<"\n\t\t Enter Father\'s name         :   ";
			gets(fathername);
			cout<<"\n\t\t Enter Mother\'s name         :   ";
			gets(mothername);
			cout<<"\n\t\t Enter Address                :   ";
			gets(address);
			cout<<"\n\t\t Enter phone no               :   ";
			gets(ph);
			cout<<"\n\t\t Enter the class             :   ";
			cin>>sec;
			sec=toupper(sec);
		}
		void display()
		{
			cout<<"\n\t\t Admno is   	:  ";
			cout<<admno;
			cout<<"\n\t\t Name is    	:  ";
			puts(name);
			cout<<"\n\t\t Class is   	:  "<<cls;
			cout<<"\n\t\t Sectionn is	:  "<<sec;
		}

		int retno()
		{
			return admno;
		}
		int clcheck(int c,char se);
}s;

int student::clcheck(int c,char se)
{
	if((cls==c)&&(sec==se))
		return 1;
	else
		return 0;
}

//************* FUNCTIONS TO CONTROL FEE INFO **************
void ADDITION();
void MODIFICATION();
void DELETE();


//**********************************************************
//***************CLASS TO MANAGE FEE INFO*******************
//**********************************************************

class fee
{
		float tution,pta,science,pupil,supw;
	public:
		fee()
		{
			tution  = 0.0;
			pta     = 0.0;
			science  = 0.0;
			pupil   = 0.0;
			supw    = 0.0;
		}
		void enterd();
		void displayd()
		{
			// clrscr();
			cout<<"\n\n\t TUTION FEE    :  "<<tution;
			cout<<"\n\n\t P.T.A. FUND   :  "<<pta;
			cout<<"\n\n\t SCIENCE FEE   :  "<<science;
			cout<<"\n\n\t PUPIL FUND    :  "<<pupil;
			cout<<"\n\n\t S.U.P.W FEE   :  "<<supw;
			cout<<"\n\t\7 Press any key to continue ..........";
		}
		int retad();
		float rettution();
		float retpta();
		float retscience();
		float retpupil();
		float retsupw();
}f;
float fee::rettution()
{
	return tution;
}
float fee::retpta()
{
	return pta;
}
float fee::retpupil()
{
	return pupil;
}
float fee::retscience()
{
	return science;
}

float fee::retsupw()
{
	return supw;
}

//********************FUNCTION TO ENTER FEE STRUCTURE*****************

void fee::enterd()
{
	// clrscr();

	cout<<"\n\t Enter Class              :   ";
	cin>>s.cls;

	cout<<"\n\t Enter the Tution fee     :   ";
	cin>>tution;
	cout<<"\n\t Enter the pta fee        :   ";
	cin>>pta;
	cout<<"\n\t Enter the Science fee    :   ";
	cin>>science;
	cout<<"\n\t Enter the Pupil fund     :   ";
	cin>>pupil;
	cout<<"\n\t Enter the S.U.P.W fund   :   ";
	cin>>supw;
	cout<<"\n\t Enter the term           :   ";
	cin>>sf.term;
}

//*****************FUNCTION TO ADD STUDENT STRUCTURE********************

void add()
{
	// clrscr();
	char chh;
	fstream fin("student.dat",ios::app|ios::binary);
	do
	{
		s.enter();
		fin.write((char *)&s,sizeof(s));
		cout<<"\n\t Do U want to enter more records ? \n";
		cin>>chh;
	}while(chh=='y'||chh=='Y');
	cout<<"\n Data has been added on the file";
	cout<<"\n\t\7 Press any key to continue..........\n";
	getch();
	fin.close();
}

//***************FUNCTION TO DELETE STUDENT STRUCTURE****************

void del()
{
	// clrscr();
	fstream fin("student.dat",ios::in|ios::binary);
	fstream fout("temp.dat",ios::out|ios::binary);
	int r;
	cout<<"\n Enter the Admno of the Student whose record is to be deleted : \n";
	cin>>r;
	int flag=0;
	while(fin.read((char *)&s,sizeof(s)))
	{
		if(r!=s.retno())
		{
			fout.write((char *)&s,sizeof(s));
		}
		else
			flag=1;
	}
	if(flag==1)
	cout<<"\n\t Data has been Deleted\n";
	else
		cout<<"\n\t No such record..............\n";
		cout<<"\n\t\7 Press ay key to continue........\n";
	getch();
	fin.close();
	fout.close();
	remove("student.dat");
	rename("temp.dat","student.dat");
}

//****************FUNCTION TO MODIFY STUDENT STRUCTURE***************

void modify()
{
	// clrscr();
	fstream fin("student.dat",ios::in|ios::out|ios::binary);
	int t;
	cout<<"\n Enter the Admno of the student whose record is to be modified \n";
	cin>>t;
	long offset=0;
	while (fin.read((char *)&s,sizeof(s)))
	{
		if(t==s.retno())
		{
			s.enter();
			fin.seekp(offset,ios::beg);
			fin.write((char *)&s,sizeof(s));
		}
		offset+=sizeof(s);
	}
	fin.close();
}

//*************FUNCTION TO ADD FEE STRUCTURE*****************

void ADDITION()
{
	// clrscr();
	fstream file;
	file.open("fee.dat",ios::app|ios::binary);
	char rep;
	do
	{
		f.enterd();
		file.write((char *)&f, sizeof(f));
		cout<<"\n\t Want to add data for more classes  \n";
		cin>>rep;
	}while(rep=='y'||rep=='Y');
	cout<<"\n Data has been added on the file \n";
	file.close();
}

//******************FUNCTION TO MODIFY FEE STRUCTURE****************

void MODIFICATION()
{
	// clrscr();
	fstream fin("fee.dat",ios::in|ios::out|ios::binary);
	int clw;
	cout<<"\n Enter the Classes whose Fee Structure is to be Modified ";
	cin>>clw;
	long offset=0;
	while(fin.read((char *)&f,sizeof(f)))
	{
		if(s.cls==clw)
		{
			f.enterd();
			fin.seekp(offset,ios::beg);
			fin.write((char *)&f,sizeof(f));
		}
		offset+=sizeof(f);
	}
	fin.close();
	cout<<"\n\n\t Modified data   :  \n";
	f.displayd();
	getch();
}

//******************FUNCTION TO DELETE FEE STRUCTURE********************

void DELETE()
{
	// clrscr();
	fstream fin("fee.dat",ios::in|ios::binary);
	fstream fout("temp.dat",ios::out|ios::binary);
	int clw;
	cout<<"\n Enter the Class of the student whose Fee structure is to be Deleted : ";
	cin>>clw;
	while(fin.read((char *)&f,sizeof(f)))
	{
		if(clw!=s.cls)
		{
			fout.write((char *)&f,sizeof(f));
		}
	}
	fin.close();
	fout.close();
	cout<<"\n\n\t Data deleted " ;
	cout<<"\n\t\7 Press any key to continue\n";
	remove("fee.dat");
	rename("temp.dat","fee.dat");
	}

//******************FUNCTION FOR FEE COLLECTION*********************

void Fee_collect()
{
	// clrscr();
	int clas,anum,t;
	char section;
	cout<<"\n\n\t Enter the Admission no           : ";
	cin>>anum;
	cout<<"\n\n\t Enter The Class Of The Student    : ";
	cin>>clas;
	cout<<"\n\n\t Enter the Section Of The Student    : ";
	cin>>section;
	section=toupper(section);
	fstream file,file2,file3,file4;
	file.open("fee.dat",ios::in|ios::binary);

	int flag=0;

	while(file.read((char *)&s, sizeof(s)))
	{
		if(s.cls==clas)
		{
			flag=1;
			break;
		}
	}
		if(flag==0)
		{
			cout<<"\n\t Please check the input for class.......\n";
			getch();
			file.close();
			return;
		}
		file2.open("student.dat", ios::in|ios::binary);
		flag=0;
		while(file2.read((char *)&s,sizeof(s)))
		{
			if(s.retno()==anum)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			cout<<"\n\t Please check the admission no........\n";
			getch();
			file.close();
			file2.close();
			return;
		}
		long offset=0;
		file3.open("sfee.dat",ios::in|ios::out|ios::binary);
		cout<<"\n\t Enter term         :  ";
		cin>>t;
		flag=0;
		while(file3.read((char *)&sf,sizeof(sf)))
		{
			if(sf.retad()==anum && sf.retterm()==t)
			{
				flag=1;
				break;
			}
			offset+=sizeof(sf);
		}
	if(flag==1)
	{
		int fine;
		char rep;
		cout<<"\n\n\t Is There A Fine ?? : ";
		cin>>rep;
		if(rep=='y'||rep=='Y')
		{
			cout<<"\n\n\t Enter the fine : ";
			cin>>fine;
		}
		sf.upfee();
		file3.seekg(offset,ios::beg);
		file3.write((char*)&sf,sizeof(sf));
		cout<<"\n\n\t FEE PAID ..................\n";
		getch();
	}
	else
	{
	cout<<"\n\t please check your inputs .............\n";
	getch();
	}
	file.close();
	file2.close();
	file4.close();

}

//****************FUNCTION TO DEFAULTER'S LIST***************

void DEFAULTER_LIST()
{
	// clrscr();
	int clas,anum,t;
	char section;
	cout<<"\n\n\t Enter The Class of the Student     :  ";
	cin>>clas;
	cout<<"\n\n\t Enter the section of the student   :  ";
	cin>>section;
	section=toupper(section);
	fstream file,file3;
	file.open("student.dat",ios::in|ios::binary);

	cout<<"\n\t Enter term            :  \n";
	cin>>t;
	// clrscr();
	cout<<"DEFAULTER\'S LIST \n";
	cout<<"ABC MODEL SCHOOL\n";
	cout<<"Term    "<<t;
	cout<<"class   "<<clas;
	cout<<"section "<<section;
	cout<<"Admission no\n";
	cout<<"Student\'s Name\n";
	cout<<"Father\'s Name\n";
	int r=10;
	while(file.read((char *)&s, sizeof(s)))
	{
		if(s.clcheck(clas,section))
		{
		file3.open("sfee.dat",ios::in|ios::binary);
		anum=s.retno();
		while(file3.read((char *)&sf,sizeof(sf)))
		{
		if(sf.retad()==anum && sf.retterm()==t && sf.retpaid()=='N')
		{
		int admno=s.retno();
		cout<<admno;
		cout<<s.name;
		cout<<s.fathername;
		r++;
		}
		}
		}
		file3.close();
	}
	file.close();
	getch();

}

//****************FUNCTION FOR QUERY ON STUDENT*****************

void Query1()
{
	// clrscr();
	char rep;
	int admno;
	fstream file2;
	do
	{	
		// clrscr();
		file2.open("student.dat",ios::in|ios::binary);
		cout<<"Enter the Admno of the Student\n";
		cin>>admno;
		while(file2.read((char *)&s, sizeof(s)))
		{
			if(s.retno()==admno)
			{
				s.display();
				getch();
			}
			}
		cout<<"\n\n\t Do U Want to enter more ?? ";
		cin>>rep;
		file2.close();

	}while(rep=='y'||rep=='Y');
}

//*****************FUNCTION FOR QUERY ON FEE********************

void Query2()
{
	// clrscr();
	int clas;
	char rep;
	do
	{
		// clrscr();
		cout<<"enter the class of the student : ";
		cin>>clas;
		fstream file("fee.dat",ios::in|ios::binary);
		while(file.read((char *)&f,sizeof(f)))
		{
			if(sf.cl==clas)
			{
				f.displayd();
			}
		}
		cout<<"\n\n\t Do you Want to Enter more ??\n";
		cin>>rep;
		file.close();
	}while(rep=='y'||rep=='Y');
}

//*******************************************************************
//*****************FUNCTION FOR SUB MENU OF STUDENT*******************
//*******************************************************************

void stud_menu()
{
	int ch1;
	do
	{
		// clrscr();
		cout<<"1.Add a Student Information\n";
		cout<<"2.Delete a Student Information\n";
		cout<<"3.Modify a student Information\n";
		cout<<"4.Quit to main menu\n";
		cout<<" Enter Ur Choice : ";
		cin>>ch1;
		switch(ch1)
		{
		case 1:  add();
			break;
		case 2:  del();
			break;
		case 3:  modify();
			break;
		case 4:  return;
		default: cout<<"\n\n\t\t@#! WRONG CHOICE ENTERED ! # @ \n";
		}
	}while(ch1!=5);
}

//***********************************************************************
//*********************FUNCTION FOR SUB MENU OF FEE**********************
//***********************************************************************

void fee_menu()
{
	int ch2;
	do
	{
	// clrscr();
	cout<<" 1. Add Fee Structure\n";
	cout<<"2. Delete Fee Structure\n";
	cout<<"3. Modify Fee Structure\n";
	cout<<"4. Return to Main Menu\n";
	cout<<" Enter Ur choice : ";
	cin>>ch2;
	switch(ch2)
	{
	case 1:  ADDITION();
		break;
	case 2: DELETE();
		break;
	case 3: MODIFICATION();
		break;
	case 4: return;
	default: cout<<"\n\n\t\t @#!WRONG CHOICE ENTERED !#@\n";
	}
	}while(ch2!=5);
}

//*****************************************************************
//**************FUNCTION FOR SUB MENU OF QUERY*********************
//*****************************************************************

void query_menu()
{
	int ch3;
	do
	{
		// clrscr();
		cout<<"1. Query on Student Information\n";
		cout<<"2. Query on FEE structure\n";
		cout<<" 3. return to Main Menu\n";
		cout<<"Enter your Choice : ";
		cin>>ch3;
		switch(ch3)
		{
			case 1: Query1();
				break;
			case 2: Query2();
				break;
			case 3: return;
			default: exit(0);
		}
	}while(ch3!=4);
}

//**********************************************************************
//****************************MAIN FUNCTION*****************************
//**********************************************************************

int main()
{
	// clrscr();
	int ch;
	char c;
	do
	{
		// clrscr();
		// draw_box(2,10,24,71);
		cout<<"************* MAIN MENU ****************\n";
		cout<<"1. Student Maintainance\n";
		cout<<"2. Fee Structure Mgmt\n";
		cout<<"3. Fee Collection\n";
		cout<<"4. Defaulters List\n";
		cout<<"5. Query\n";
		cout<<"6. Quit\n";
		cout<<"Enter ur choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:		stud_menu();
				break;
			case 2:		fee_menu();
				break;
			case 3:		 Fee_collect();
				break;
			case 4:		DEFAULTER_LIST();
				break;
			case 5:		query_menu();
				break;
			case 6:		exit(0);

			default:	cout<<"\n\n\t !@# WRONG CHOICE ENTERED #@!";
		}
		// clrscr();
		cout<<"\n\7 Do You Wish To Continue (Y/N):";
		cin>>c;
	}while(c=='y'||c=='Y');
	return 0;
}
