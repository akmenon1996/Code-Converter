#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>

using namespace std;
extern char filename2[50];

class cipher
{ 
      char *finalcode;
	  public:
      	cipher()
      	{
      		finalcode=new char[500];
      		strcpy(finalcode,"\0");
      	}
      void CC_encrypt(char*);
      void display1(char*);
      
}obj1;  

void cipher::CC_encrypt(char *code)
{    
     for(int i=0;i<strlen(code);i++)
     {
            *(code+i)=toupper(*(code+i));
            if(*(code+i)==' ')
            {
				*(code+i)=*(code+i);
			}
            else if (*(code+i)=='X')
        	{
				*(code+i)='A';
			}
			else if (*(code+i)=='Y')
        	{
				*(code+i)='B';
			}
			else if (*(code+i)=='Z')
        	{
				*(code+i)='C';
			}
			else
            {
				*(code+i)+=3;
				strcpy(finalcode,code);
				
		    }
	}
	display1(finalcode);
}
            
void cipher::display1(char*string)
{
	cout<<endl<<"The string after encryption is: "<<string<<endl;
}

int main5()
{    
     char code[500];
     cout<<endl<<"Enter a string that you would like to encrypt:\n";
     fflush(stdin);
     cin.getline(code,500,'\n');
	 obj1.CC_encrypt(code);
	 ofstream fout2;
	 fout2.open(filename2,ios::out);
	 fout2<<code;
	 fout2.close();
	
}
