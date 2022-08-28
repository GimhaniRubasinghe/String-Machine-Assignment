#include <bits/stdc++.h>
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
using std::ifstream;


void stringmatch(string pattern,string text,int a)
{
	char resaultpath[20];
	
    sprintf(resaultpath,"Output/Patternmatch%d.txt", a);
	ofstream OutputFile(resaultpath);
	OutputFile<<"********Test case "<<a<<"*********" <<endl<<endl;//write the output
	OutputFile<<"Text :"<<text<<endl;
	OutputFile<<"Pattern :"<<pattern<<endl<<endl;
	        
	
    int textlen=text.size();
    int patlen=pattern.size();
    int flag1,flag2=0;
    int j;
    for(int i=0;i<=(textlen-patlen);i++)
	{
    	flag1=1;
        for(int j=0;j<patlen;j++)
		{
            if(pattern[j]!='_' && pattern[j]!=text[i+j])// to neglect the mismatch
			{
                flag1=0;
                break;
            }    
        }
        	if(flag1==1)
			{
                OutputFile<<"Pattern found from starting index "<< i << endl;
                flag2 = 1;
                
        	}
             
    }
    if(flag2 == 0){
    	OutputFile<<endl<<"No match resault found "<< endl;//to display if there is no match found
	}
}

int main()
{   
	int choice,i;	
	char textname[20],patname[20];
	string text,pattern;
	
	cout<<"How many test cases do you want to run?(Testcases should be between 0 -9) : ";//If user press 0,it will display output of empty text and empty pattern.so that get here range 0 to 9 not to 1 to 10
	cin>>choice;
	if(choice<0 || choice>=10){
		cout<<"Error input : Testcases should be between 0-9";//If user enter number not in range 0-9
		exit(0);
	}

	for(i=0;i<=choice;i++)
	{
		
			//save the path in array 
			sprintf(patname,"TestData/Patterns/pattern%d.txt", i);
			sprintf(textname,"TestData/Texts/text%d.txt", i);	
			
			//create file pointers
			ifstream fp1(patname);	
			ifstream fp2(textname);
			
			//read files
			getline (fp1, pattern);	
			getline (fp2, text);
             
			stringmatch(pattern,text,i);//run the "stringmatch" function 

			//close files
			fp1.close();	
			fp2.close();	
					
	}
	char resaultpath[20];
	while(i<10){//to remove extra output files
	
    sprintf(resaultpath,"Output/Patternmatch%d.txt", i);
	remove(resaultpath);
	i++;
	}
  cout<<endl<<"Program output is saved in output folder and please check in there."; 
}
