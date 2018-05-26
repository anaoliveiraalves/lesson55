/*
 * date.h
 *
 *  Created on: 25/05/2018
 *      Author: aet
 */

#ifndef DATE_H_
#define DATE_H_
#include <iostream>
using namespace std;

class Date{
	int d,m,y;
public:
	Date(int dd=26,int mm=2, int yy=2018);
	int getD()const;
	int getM()const;
	int getY() const;
	int &getSetY(); //do you remember what this returning reference means?
	bool setD(int dd);
	bool setM(int mm);
	bool setY(int yy);
	void show(ostream & o)const; //even if we don't know other types of ostream beyond cout, in this way this show is more generic
};
bool operator==(const Date & d1, const Date & d2); //what is the difference putting this operator as a global function instead of member?
ostream & operator<<(ostream & o, const Date & d);

#endif /* DATE_H_ */
