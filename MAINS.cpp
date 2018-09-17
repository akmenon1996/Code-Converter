#include<iostream>
#include<stdlib.h>

using namespace std;

extern int main1();
extern int main2();
extern int main3();
extern int main4();
extern int main5();
extern int main6();
extern int main();
void coding_start();
int main()

{	int i=1;
	system("COLOR 2");
	
	main1();
	main2();
	
}
	void coding_start()
  {
	int ch,ch1,i;
	cout<<"Choose a method of encryption: "<<endl<<"1. Morse Code."<<endl<<"2. Caeser Cipher."<<endl<<"3. Log out"<<endl<<endl;
	cin>>ch;
//case 3 has to be added to return to main menu	
	do
	{
		switch(ch)
		{
			case 1:
				cout<<endl<<"What would you like to do? "<<endl<<"1. Encryption."<<endl<<"2. Deencryption."<<endl<<"3.Back to main menu"<<endl;
				cin>>ch1;
				switch(ch1)
				{
					case 1:
						system("cls");
						main3();
						break;
					case 2:
						system("cls");
						main4();
						break;
					case 3:
						system("cls");
						coding_start();
						break;
// case 3 has to be provided to return to primary do while loop.
				}
				break;
			case 2:
				cout<<endl<<"What would you like to do? "<<endl<<"1. Encryption."<<endl<<"2. Deencryption."<<endl<<"3.Back to main menu"<<endl;
				cin>>ch1;
				switch(ch1)
				{
					case 1:
						system("cls");
						main5();
						break;
					case 2:
						system("cls");
						main6();
						break;
					case 3:
						system("cls");
						coding_start();
						break;
				}
				break;
			case 3: 
			          cout<<"LOGGING OUT!! BYE BYE!! " <<endl;
			          cout<<".";
			          for(unsigned int i=0;i<100000000;i++)
					  {}
					  cout<<".";
					  for(unsigned int i=0;i<100000000;i++)
					  {}
					  cout<<".";
					  for(unsigned int i=0;i<100000000;i++)
					  {}  
					  system("cls");  
					  
			          main1();
			          break;
			default: break;
		
	    }
    }while(ch!=3);
  }

//function to go back to main menu
