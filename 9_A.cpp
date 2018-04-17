//Program to write and read values using variables in/from file.

#include<iostream>
#include<stdlib.h>
#include<string>
#include<fstream>
 
using namespace std;


void write( ofstream &fout ){
	
	/*
	Objective : To  take input from user one by one and write the input values into the file one by one.
	Input : fout -> An ofstream object used to write into the file
	Return value : None 
	Side Effect : The file is updated with the values entered by user.
	*/

	string value;		//variable used to store the value entered by user
	char choice = 'y';
	cout<<"\n\n\t\tFILE OPENED FOR WRITING\n\n";
	while(choice=='Y' || choice=='y'){
    		cout<<"Enter value : ";
		cin>>value;		
		fout<<value<<endl;
		cout<<"\nValue added!\nDo you want to add more values?(y/Y) : ";
		cin>>choice;
 	}
}
 
void read( ifstream &fin ){

	/*
	Objective : To read the values in the file one by one and print them on the output console.S
	Input : fin -> An ifstream object used to read from the file.
	Return value : None 
	Ouput : Values in the file	
	*/

	cout<<"\n\n\t\tVALUES IN THE FILE ARE\n\n";
	string value;		//variable used to store values read from the file
	while(fin>>value)
		cout<<"Value : "<<value<<endl;
	
}

int main()
{  
	/*
	Objective : Driver function to demonstrate reading and writing operations from/to a fie.
	*/

	//opening file in write mode
	ofstream fout; 
    	fout.open("my_file.txt");
    	if(!fout){
      		cout<<"Error : Cannot open file!\nExiting..."<<endl;
		exit(1);
	}
	write(fout); 
	fout.close();

	//opening file in read mode
   	ifstream fin;	
    	fin.open("my_file.txt");
    	if(!fin){
    	    	cout<<"Error : Cannot open file!\nExiting..."<<endl;
	    	exit(1);
    	}
	read(fin);
    	fin.close();

	return 0;
}
