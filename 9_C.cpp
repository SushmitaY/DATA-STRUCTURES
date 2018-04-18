//Program to demonstrate usage of tellg() tellp() seekg() seekp().

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
	int getRoll_no();
	void setGrade(char);
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

int student::getRoll_no(){
	return roll_no;
}
void student::setGrade(char g){
	/*
	Objective : To update the existing grade of a student.
	Input : New grade
	*/
	grade = g;
}

void write(ofstream &fout,student s){

    /*
    Objective : To write an object of class student into file.
    Input : s -> object of class student.
    Return value : None.
    Side Effect : The object passed is appended at the end of the file. 
    */

    fout.write((char*)&s,sizeof(s));  
}

void read(ifstream &fin){

    /*
    Objective : To read the file 'student.dat'
    Input : None.
    Output : Data of file 'student.dat'
    */

    student s;
    cout<<"\n\n\t\t\tSTUDENT FILE\n\n";
    while(fin.read((char*)&s,sizeof(s)))
		s.showData();
}


int main()
{
	ofstream fout;
	ifstream fin;
	fout.open("student_record.dat", ios::binary);
	student s;
	write(fout,student(1,"John",'B'));
	write(fout,student(2,"Ron",'C'));
	write(fout,student(3,"Harry",'F'));
	write(fout,student(4,"Peter",'A'));
	write(fout,student(5,"Bruce",'A'));
	write(fout,student(6,"Taylor",'B'));
	write(fout,student(7,"Daniel",'E'));
	write(fout,student(8,"Jerry",'B'));
	write(fout,student(9,"April",'B'));
	write(fout,student(10,"Nata",'A'));
	fout.close();
	
	fin.open("student_record.dat", ios::binary);
	cout<<fin.tellg();		//again set the reading pointer at beginning(for reading entire database) 
    cout<<"\n\n\t\t\tFILE CONTENTS:\n";
    read(fin);  
	cout<<fin.tellg();
	int rno;
	long pos;
	char g;
	cout<<"\n\nEnter rollno of student whose record is to be modified: ";
	cin>>rno;
	fin.close();
	fstream f;
	f.open("student_record.dat", ios::binary|ios::in|ios::out);
	while(!f.eof())
	{
		pos = f.tellg();	//storing the position of reading pointer which is at the beginning of current object being searched
		f.read((char *)&s, sizeof(s));
		if(s.getRoll_no() == rno )
		{
			cout<<"\nEnter new grade  : ";
			cin>>g;
			s.setGrade(g);
			f.seekp(pos);	//updating the write pointer to point at beginning of the object with the matching roll number
			f.write((char *)&s, sizeof(s));
			break;
		}
	}
	if(f.eof())
	{
		cout<<"\nRecord not found in the file..!!\n";
		exit(1);
	}
	f.close();
	fin.open("student_record.dat", ios::binary);
    cout<<"\n\n\t\t\tNEW FILE CONTENTS:\n";
    read(fin);       
    fin.close();
    return 0;
}
