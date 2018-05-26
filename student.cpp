/*
 * aluno.cpp
 *
 *  Created on: 19/05/2018
 *      Author: aet

 */
#include "student.h"
#include <iostream>

Student::Student(): year(2018){
	cout << "Constructing a new student with the default constructor...";
	number = 1;  //And name, which will be its value?
	show();
}

Student::Student(const string & nam, int n, int y):year(y>2000?y:2018),name(nam){
	cout << "Constructing a new student...";
	if(n > 0)
		number = n;  //And name, which will be its value?
	else
		n = 1;
	show();

}

Student::Student(const string & nam, int n, int y, int dd, int mm, int yy):year(y>2000?y:2018),name(nam),registration(dd,mm,yy){ //new constructor to initialize the new member
	cout << "Constructing a new student...";
	if(n > 0)
		number = n;  //And name, which will be its value?
	else
		n = 1;
	show();




}
int Student::getNumber() const{ //this member function is const so it can be called on constant and non-constant objects
	return number;
}
int & Student::getSetNumber(){ //in what this differ from the previous?
	return number;
}

void Student::setNumber(int n){
	if(n>1)
		number=n;

}
void Student::show() const{
	cout << "Student:" << name << "(" << number << "," << year << ") registration:" << registration << endl;


}
	//... other get and set function for the remaining member
Student::~Student(){
    cout << "Destroying a student...";
	show();
	}
