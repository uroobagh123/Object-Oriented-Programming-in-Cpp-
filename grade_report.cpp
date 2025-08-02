// Program to generate grade reports based on tuition status using OOP and file handling

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
class Course{
	private:
		string name;
		string id;
		int credits;
		char grade;
	public:
		void setName(string name){
			this->name=name;
		}
		void setId(string id){
			this->id=id;
		}
		void setCredit(int credits){
			this->credits=credits;
		}
		void setGrade(char grade){
			this->grade=grade;
		}
		string getName(){
			return name;
		}
		string getId(){
			return id;
		}
		int getCredit(){
			return credits;
		}
		char getGrade(){
			return grade;
		}
};
class Student{
	private:
		string name;
		string id;
		char paid;
		int noOfCourses;
		Course* obj;
	public:
		void setname(string firstName,string lastName){
			name=firstName+" "+lastName;
		}
		void setId(string id){
			this->id=id;
		}
		void setPaid(char paid){
			this->paid=paid;
		}
		void setNoOfCourse(int value){
			noOfCourses=value;
			obj=new Course[value];
		}
		void setCourses(string name, string id, int credit, char grade, int no){
			(obj+no)->setName(name);
			(obj+no)->setId(id);
			(obj+no)->setCredit(credit);
			(obj+no)->setGrade(grade);
		}
		void display(int fee){
			cout<<"STUDENT: "<<name<<endl;
			cout<<"STUDENT ID:"<<id<<endl;
			cout<<"COURSES: "<<noOfCourses<<endl;
			if(paid=='Y' || paid=='y'){
				cout<<"COURSE NO: "<<setw(15)<<"COURSE NAME: "<<setw(15)<<"CREDIT: "<<setw(10)<<"GRADE: "<<endl;
	int totalCrds=0;
	float gpa;
	for(int i=0; i<noOfCourses; i++){
					cout<<(obj+i)->getId()<<setw(15)<<(obj+i)->getName()<<setw(15)<<(obj+i)->getCredit()<<setw(10)<<(obj+i)->getGrade()<<endl;
					totalCrds+=(obj+i)->getCredit();
					if((obj+i)->getGrade()=='A')
						gpa+=(obj+i)->getCredit()*4;
					else if((obj+i)->getGrade()=='B')
						gpa+=(obj+i)->getCredit()*3;
					else if((obj+i)->getGrade()=='C')
						gpa+=(obj+i)->getCredit()*2;
					else if((obj+i)->getGrade()=='D')
						gpa+=(obj+i)->getCredit()*1;
	}
				cout<<"TOTAL CREDITS: "<<totalCrds<<endl;
				cout<<"MID SEM GPA: "<<gpa/totalCrds<<endl;
			} else{
				cout<<"COURSE NO"<<setw(15)<<"COURSE NAME"<<setw(15)<<"CREDIT"<<setw(10)<<"GRADE"<<endl;
	int totalCrds=0;
	float gpa;
				for(int i=0 ;i<noOfCourses; i++){
					int credits=(obj+i)->getCredit();
					cout<<(obj+i)->getId()<<setw(15)<<(obj+i)->getName()<<setw(15)<<(obj+i)->getCredit()<<setw(15)<<"PAYMENT : "<<credits*fee<<endl;
					totalCrds+=(obj+i)->getCredit();
	}
				cout<<"TOTAL CREDITS: "<<totalCrds<<endl;
				cout<<"MID SEM GPA: HELD FOR NON-PAYMENT"<<endl;
			}		
		}
};
int main (){
	fstream inputfile("input.txt");
	int n, fee;
	inputfile>>n>>fee;
	Student obj[n];
	for(int i=0;i<3;i++){
		string firstName,lastName,id;
		char paid;
		int noOfCourses;
		inputfile>>firstName;
		inputfile>>lastName;
		inputfile>>id;
		inputfile>>paid;
		inputfile>>noOfCourses;
		obj[i].setname(firstName,lastName);
		obj[i].setId(id);
		obj[i].setPaid(paid);
		obj[i].setNoOfCourse(noOfCourses);
		for(int j=0; j<noOfCourses; j++){
			string c_name,c_id;
			int credit;
			char grade;
			inputfile>>c_name;
			inputfile>>c_id;
			inputfile>>credit;
			inputfile>>grade;
			obj[i].setCourses(c_name,c_id,credit,grade,j);
		}
	}	for(int i=0; i<n; i++)
		obj[i].display(fee);
}