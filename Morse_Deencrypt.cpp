#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>

using namespace std;

extern char filename1[50];

char morse[26][5] = {{".-"}, {"-..."}, {"-.-."}, {"-.."}, {"."}, 
					{"..-."}, {"--."}, {"...."}, {".."}, {".---"}, 
					{"-.-"}, {".-.."}, {"--"}, {"-."}, {"---"}, 
					{".--."}, {"--.-"}, {".-."}, {"..."}, {"-"}, 
					{"..-"}, {"...-"}, {".--"}, {"-..-"}, {"-.--"}, 
					{"--.."}};
		
class morse_deencrypt
{
	char morsed[100];
	char temp[100];
	char temp1[1]; 
	int i,j,k,l;
	
	public:
		morse_deencrypt()
		{
			strcpy(morsed,"\0");
			strcpy(temp,"\0");
		}
		
		void morsedec(char*);
		void morsedisplay();
}decode;

void morse_deencrypt::morsedec(char *morsestring)
{           
			int count=0;
            int letters=0;
            strcat(morsestring, " ");
            
			for(i=0;i<strlen(morsestring);i++)
				{	
					if((morsestring[i]==' ')&&(morsestring[i+1]!=' '))	
					{
						for(int j=0;j<26;j++)
						{
							if(strcmp(temp, morse[j])==0)
							{
								morsed[letters]=(char)(65+j);
								letters++;
								for(int k=0;k<4;k++)
							    	temp[k]='\0';
						    	count=0;
							}
					    }
					}		
					
					else if(morsestring[i]!=' ')
					{
						temp[count]=morsestring[i];
						count++;
						
					}
					else 	
					{
						for(int j=0;j<26;j++)
						{
							if(strcmp(temp, morse[j])==0)
							{
								morsed[letters]=(char)(65+j);
								letters++;
								for(int k=0;k<4;k++)
							    	temp[k]='\0';
							    morsed[letters]=' ';
								letters++;
						    	count=0;
							}
					    }
					}
				}
}

void morse_deencrypt::morsedisplay()
{
     cout<<morsed;
}

int main4()
{
	char morsestring[200];
	fstream fin;
	fin.open(filename1,ios::in);
	 if(!fin)
	 {
	 	cout<<"No string present in file to decode";
	 }
	 else
	{
	fin.getline(morsestring,200,'\n');
	cout<<endl<<"The encrypted string is: "<<morsestring<<endl;
	fin.close();
	
	decode.morsedec(morsestring);
	cout<<endl<<"The deencrypted string is: ";
	decode.morsedisplay();
	cout<<endl;
	}
}
