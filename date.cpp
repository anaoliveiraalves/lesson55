/*
 * date.cpp
 *
 *  Created on: 25/05/2018
 *      Author: aet
 */

#include "date.h"
#include <time.h>
#include <iomanip>

Date::Date(int dd, int mm, int yy){
	if(!setD(dd)){
		d = 26;
	}
	if(!setM(mm)){
		m = 2;
	}
	if(!setY(yy)){
		y=2018;
	}
	cout << "Constructing a new date";
	show(cout);
}

int Date::getD()const{
	return d;
}

int Date::getM()const{
	return m;
}

int Date::getY() const{
	return y;
}

int & Date::getSetY(){
	return y;
}

bool Date::setD(int dd){ //return true it was changed
	bool result = false;
	if((dd >= 1 && dd <= 30 && m != 2) || (dd >=1 && dd <= 28 && m == 2 ) || (d == 31 &&
			(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12))){ //not considering leap years
		d=dd;
		result = true;
	}
	return result;
}

bool Date::setM(int mm){
	bool result = false;
	if((mm == 2 && d <= 28) || ((mm == 4 || mm == 6 || mm == 9 || mm == 11 ) && d <= 30) || (m >= 1 && m <= 12)){
		m = mm;
		result = true;
	}
	return result;
}

bool Date::setY(int yy){
	bool result = false;
	time_t timestamp = time(NULL);
	struct tm timefinal = *localtime(&timestamp);
	if (yy >= 1974 && yy <= timefinal.tm_year){ //this year as superior limit
		y = yy;
		result = true;
	}
	return result;
}

void Date::show(ostream & o)const{ //even if we don't know other types of ostream beyond cout, in this way this show is more generic
	o << setfill('0');
	o << setw(2);
	o << d << '/' << setw(2) << setfill('0') << m << '/' << setw(4) << y << endl;
}
bool operator==(const Date & d1, const Date & d2){ //what is the difference putting this operator as a global function instead of member?
	return d1.getD() == d2.getD() && d1.getM() == d2.getM() && d1.getY() == d2.getY();
}
ostream & operator<<(ostream & o, const Date & d){
	d.show(o);
	return o;
}


