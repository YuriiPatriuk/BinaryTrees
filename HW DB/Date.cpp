#include "Date.h"

Date Date::addDay()
{
	bool check = false;
	size_t dayInMonth[]{ 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && day == 28 && isLeap(year))
	{
		day++;
		check = true;
	}
	else if (day == dayInMonth[11])
	{
		day = 1;
		month = 1;
		year++;
	}
	else if (day == dayInMonth[month - 1] && check == false || month == 2 && day == 29 && isLeap(year))
	{
		day = 1;
		month++;
	}
	else if (day < dayInMonth[month - 1])
	{
		day++;
	}



	return *this;
}

Date::Date(const size_t& day, const size_t& month, const size_t& year)
{
	setDay(day);
	setMonth(month);
	setYear(year);
}