#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include<conio.h>
extern int main2();

using namespace std;
int flag1=0;
char username[100];
char filename1[50];
char filename2[50];
class create_username
{
 	ofstream fout;
 	char password[50], name[20],phone_number[20];
 	char temp[4];
 	
	public: 
 		create_username()
 		{
 		}
 		void create();
 		char * getpass()
 		{
				return password;
		}
		char * getphno()
		{
			return phone_number;
		}
};

void create_username::create() 
{   
		int i=0;
		char ch,c;
		create_username obj;
  		cout<<endl<<"Enter username: ";
  		fflush(stdin);
		gets(username);
		char filename[100];
		strcpy(filename,username);
			strcat(filename,".dat");
			ofstream output_file;
			output_file.open(filename,ios::in);
		    if (!output_file)
		    {
		    		output_file.close();
		    		output_file.open(filename);
		    		cout<<endl<<"Enter name: ";
  					gets(name);
  					fflush(stdin);
  					cout<<endl<<"Enter password: \n                 ";
   					for (int i=0;i<16;i++)
						{
							ch=getch();
							if(ch==8)
								{
									cout<<"\b"<<" "<<"\b";
									password[--i]='\b';
									i--;
									continue;	
								}
							else if(ch==13)
								{
									password[i]='\0';
									break;
								}
							else
								{
									cout<<"*";
									password[i]=ch;
									if(i==15)
								{
									i--;
									continue;
								}
								
						        }		
						}
							fflush(stdin);
  							cout<<endl<<" \n Enter mobile number: ";
  							cin.get(phone_number,20);
  							cout<<endl;
  							system("cls");
  							fflush(stdin);
    						output_file.write((char *)this,sizeof(create_username));
  							fout.close();
  							system("cls");
  							cout<<"Your ID has been created successfully \n";
  							cout<<"Your ID details are"<<endl<<"Username --> "<<username<<endl<<"Name --> "<<name<<endl<<"Phone number -->"<<phone_number<<endl;
					  		cout<<"To continue press enter";
  							c=_getch();
  							if(c==13)
  								{
		    						system("cls");
  								}
			}
  	        else
			{
			
  				cout<<"Username already exists. PLease try again with different username"<<endl;
  				cout<<"To continue press enter";
  				ch=_getch();
  				if(ch==13)
  				{
		    		system("cls");
  				}
  				
  			}
}
class login
{	
 	fstream fin;
 	char word[50],phno[20],ch;
 	int j=0;
 	char username[50],password[50],name[20],phone_number[20],arr[20];
 	char temp[4]; 
 	int flag;
 	char a;
 
 	public:
 		login()
			{
 				strcpy(temp,".dat");
 			}
 		void signin();
 		void forgot_password();
};

  void login::signin()
 {
 	system("cls");
 	cout<<endl<<"Enter username: ";
 	fflush(stdin);
	gets(username);
	char filename[60];
	strcpy(filename,username);
	strcat(filename,".dat");
	strcpy(filename1,username);
	strcpy(filename2,username);
	strcat(filename1,"_mc.txt");
	strcat(filename2,"_cc.txt");
 	ifstream fin(filename,ios::binary|ios::in);
 	if(!fin)
 	{
 		cout<<"Username does not exist. Sorry.";
 		extern void main1();
 	}
 	else
 	  {
      				
 			cout<<endl;
 		for(int i=0;i<3;i++)
   		{
			cout<<endl<<"Enter password: ";
   			for (int j=0;j<16;j++)
				{
					ch=getch();
					if(ch==8)
						{
							cout<<"\b"<<" "<<"\b";
							word[--j]='\b';
							j--;
							continue;	
						}
					else if(ch==13)
						{
							word[j]='\0';
							break;
						}
					else
						{
							cout<<"*";
							word[j]=ch;
							if(j==15)
								{
									j--;
									continue;
								}
								
						 }	
						 	
				}
         		
      		cout<<endl;
 			fflush(stdin);
 			create_username obj;
    do
	{    
			fin.read((char *)&obj,sizeof(obj));
		if(strcmp(obj.getpass(),word))
		{	
				cout<<"                                   AUTHORISING"<<endl<<"                                                                                                                      ";
	
					for(unsigned int i=0;i<500000000;i++)
					{}
					cout<<". ";
					for(unsigned int i=0;i<500000000;i++)
					{}
					cout<<". ";
					for(unsigned int i=0;i<500000000;i++)
					{}
					cout<<". "<<endl<<endl;
					for(unsigned int i=0;i<500000000;i++)
					{}
			system("cls");
		    cout<<"Wrong username/password combination \n";
			cout<<"You have "<<3-(i+1)<<" attempts remaining \n";
			int imp=3-(i+1);
			if(imp==0)
			cout<<endl;
			break;
		}
		else if(i==0)
		{
		 	i=i+3;
		 	main2();
		    break;
		}
		 else if(i==1)
		{
		 	i=i+2;
		 	main2();
		    break;
		}
		 else if(i==2)
		 {
		 	i=i+1;
		 	main2();
		 	break;
	     }
	 	}while(fin);
   	 }
	}
	fin.close();
}
		
 
 void login::forgot_password()
 {
 	cout<<endl<<"Enter your username: ";
 	fflush(stdin);
	gets(username);
	strcat(username,temp);
 	ifstream fin(username,ios::binary|ios::in);
 	for(int i=0;i<3;i++)
	
   {
    
	cout<<endl<<"Enter phone number: ";
	
 	gets(phno);
 	fflush(stdin);
 	create_username obj;
    do
	{    
			fin.seekg(0, ios::beg);
			fin.read((char *)&obj,sizeof(obj));
			if(strcmp(obj.getphno(),phno))
		{	
			cout<<endl<<"Wrong username/phone number combination. \n";
			cout<<"You have "<<3-(i+1)<<" attempts remaining... \n";
			int simp=3-(i+1);
			if(simp==0)
			cout<<endl;
			break;
		}
		else if(i==0)
		{
		 	cout<<endl<<"Your password is: ";
		 cout<<obj.getpass()<<"\n";
		 i=i+3;
		 	cout<<endl<<"Do you wish to log in right now? (y/n) \n";
		 	cin>>a;
		 	if(a=='y')
		 	{
		 
		 	main2();
		 	break;
		    }
		    else
		    break;
		}
		 else if(i==1)
		{   cout<<endl<<"Your password is: ";
		    cout<<obj.getpass()<<"\n";
		 	i=i+2;
		 	cout<<endl<<"Do you wish to log in right now? (y/n) \n";
		 	cin>>a;
		 	if(a=='y')
		 	{
		 
		 	main2();
		 	break;
		    }
		    else
		    break;
		}
		 else if(i==2)
		 {   
		    cout<<endl<<"Your password is: ";
		    cout<<obj.getpass()<<"\n";
		 	cout<<endl<<"Do you wish to log in right now? (y/n) \n";
		 	cin>>a;
		 	if(a=='y')
		 	{
		
		 	main2();
		 	break;
		    }
		    else
		    break;
	     }
		 
	}while(fin);
   
    fin.close();
   
   }

}

int main1()
{
  	char k;
	int c=0;
 
  {
	while((c<4)&&(flag1!=1))
	{
		create_username obj1;
		login obj2;
		
		cout<<"Please choose an option: "<<endl;
		cout<<"1. Create username. \n";
		cout<<"2. Login. \n";
		cout<<"3. Forgot password. \n\n";
		cin>>c;
		switch(c)
		{
			case 1: obj1.create();
		         	break;
			case 2: obj2.signin();
		        	break;
			case 3: obj2.forgot_password();
		        	break;
			default : cout<<"Invalid input.";
		}
	}
  }
}

	
