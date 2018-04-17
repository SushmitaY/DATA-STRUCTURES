//Program to write and read object using read and write function.

#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
 
using namespace std;
 
class student
{
    /*
    Objective : Class definition for student.
    Description : Data Members : Roll number of a student, Name of the student, Grade of the student.
    		  Member Functions : getDate() -> Take input for data members from the user
				     showData() -> Displays the value of data members. 
    */
    private:
	int roll_no;        
	char name[30];	
	char grade;
	
    public:
	student();
	student(int,char[],char);
        void getData();
        void showData();
};

student::student(){
	//Default Constructor 
	roll_no = 0;
	strcpy(name,"");
	grade = 'X';
}
 
student::student(int r, char n[], char g){

	/*
	Objective : Contructor to initialize the values during the declaration of the object.
	*/
	roll_no = r;
	strcpy(name,n);
	grade = g;
}

void student::getData(){
	/*
	Objective : To take input from user and initialize the data menmbers.
	Input : None.
	Output : None.
	Side Effect : Values of the object is updated with the input values
	*/
	  cout<<"\n\n\t\tEnter student's details\n";
	  cout<<"Enter roll number: ";
	  cin>>roll_no;
	  cout<<"Enter name:";
	  cin.ignore();
	  cin.getline(name,30);
          cout<<"Enter Grade:"; 
	  cin>>grade;

}

void student::showData(){
     /*
      Objective : To Display the members of the object on output console.	
     */
     cout<<"Roll number : "<<roll_no<<"\tName : "<<name<<"\tGrade : "<<grade<<endl;
}

void write(student s){

    /*
    Objective : To write an object of class student into file.
    Input : s -> object of class student.
    Return value : None.
    Side Effect : The object passed is appended at the end of the file. 
    */

    ofstream fout;
    fout.open("student.dat",ios::binary|ios::app);	//append mode
    if(!fout){
      cout<<"Error in creating file.."<<endl;
      exit(1);
    }    
    fout.write((char*)&s,sizeof(s));  
    fout.close();
}

void read(){

    /*
    Objective : To read the file 'student.dat'
    Input : None.
    Output : Data of file 'student.dat'
    */

    ifstream fin;  
    fin.open("student.dat",ios::binary);
    if(!fin){
        cout<<"Error in opening file..";
        exit(1);
    }
    student s;
    cout<<"\n\n\t\t\tSTUDENT FILE\n\n";
    while(fin.read((char*)&s,sizeof(s)))
	s.showData();
    fin.close();
}

int main(){

    /*
    Objective : Driver function to demonstrate reading and writing object from/to a binary file. 	
    */
    student s;
    int choice; 
    while(true){
	cout<<"\n\n\t\t\tMENU\n\n1. WRITE\n2. READ\n3. EXIT\n\nEnter your choice : ";
	cin>>choice;
	switch(choice){
	
		case 1: s.getData();
			write(s);
			break;

		case 2: read();
			break;

		case 3: exit(0);
			break;

		default: cout<<"\n\nINVALID CHOICE!!";
			 break;
	}
    }
     
    return 0;
}

