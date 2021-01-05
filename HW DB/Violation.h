#pragma once
#include "Lib.h"
#include "Date.h"
class Violation
{
public:
	//Violation() = default;
	Violation(const string& name, const Date& date, const float& sum)
		:date(date), sum(sum)
	{
		setName(name);
	}
	void print() const;
	void setName(const string& data);
private:
	string name;
	Date date;
	float sum;
};

inline void Violation::print() const
{
	cout << "Name: " << name << endl;
	cout << "Date: ";
	date.print();
	cout << "Sum: " << sum << endl;
}

inline void Violation::setName(const string& data)
{
	name = data;
}
