#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>

using namespace std;

extern char filename1[50];

char morse1[26][5]={{".-"},{"-..."},{"-.-."},{"-.."},{"."},
				   {"..-."},{"--."},{"...."},{".."},{".---"},
				   {"-.-"},{".-.."},{"--"},{"-."},{"---"},
				   {".--."},{"--.-"},{".-."},{"..."},{"-"},
				   {"..-"},{"...-"},{".--"},{"-..-"},{"-.--"},
				   {"--.."}};

class morse_encrypt
{
	int temp;
	
	public:
		char morseword[100];
		morse_encrypt()
		{
			strcpy(morseword,"\0");
		}
		void morseconvert(char *);	
		void dispmorse();
		void write_morse();
}encode;

void morse_encrypt::morseconvert(char *chars)
		{ 
			for (int i=0;i<strlen(chars);i++)
			{
				chars[i]= toupper(chars[i]);
			}
							
			for(int i=0;i<strlen(chars);i++)
			{ 
				if (isspace(chars[i]))
				{
					strcat(morseword,"  ");												
				}
				else
				{
					temp=chars[i]-'A';
					strcat(morseword,morse1[temp]);
					strcat(morseword," ");
				}
			}
			write_morse();
		}

void morse_encrypt::write_morse()
{
	ofstream fout1;
	fout1.open(filename1,ios::out);
	fout1<<morseword;
	fout1.close();
}

void morse_encrypt::dispmorse()
{
	cout<<morseword;
}

int main3()
{
	char *chars=new char[100];
	cout<<endl<<"Enter a string that you would like to encrypt:\n";
	fflush(stdin);
	gets(chars);
	fflush(stdin);
	encode.morseconvert(chars);
	cout<<endl<<"The string after encryption is: "<<endl;
	encode.dispmorse();
	cout<<endl;
}
