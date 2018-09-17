#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>

using namespace std;
extern char filename2[50];

class cipher
{
	char* finalcode;
	public:
			cipher()
      	{
      		finalcode=new char[500];
      		strcpy(finalcode,"\0");
      	}
    void CC_decrypt(char*);
}obj;

void cipher::CC_decrypt(char*code)
{
		for(int i=0;i<strlen(code);i++)
        {
            *(code+i)=toupper(*(code+i));
            if(*(code+i)==' ')
            {
				*(code+i)=*(code+i);
			}
            else if (*(code+i)=='A')
        	{
				*(code+i)='X';
			}
			else if (*(code+i)=='B')
        	{
				*(code+i)='Y';
			}
			else if (*(code+i)=='C')
        	{
				*(code+i)='Z';
			}
			else
            {
				*(code+i)-=3;
		    }
	}
		strcat(finalcode,code);
		cout<<endl<<"The deencrypted string is: "<<finalcode<<endl;
	}
	
int main6()
{
	char cc[200];
	fstream fin;
	fin.open(filename2,ios::in);
		 if(!fin)
	 {
	 	cout<<"No string present in file to decode";
	 }
	 else
	{
	fin.getline(cc,200,'\n');
	cout<<endl<<"The encrypted string is: "<<cc<<endl;
	fin.close();
    obj.CC_decrypt(cc);
	}
}
