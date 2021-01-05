#pragma once
#include<iostream>
class Date
{
	static const size_t CURR_YEAR = 2020;
	bool isLeap(size_t year) {
		return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	}
private:
	size_t day, month, year;
public:
	Date addDay();
	Date(const size_t& day, const size_t& month, const size_t& year);

	void setMonth(const size_t& month_)
	{
		if (month_ >= 1 && month_ <= 12)
		{
			month = month_;
		}
	}
	void setYear(const size_t& year_)
	{
		if (year_ >= CURR_YEAR - 18)
		{
			year = year_;
		}
	}
	void setDay(const size_t& day_)
	{
		size_t dayInMonth[]{ 31,28,31,30,31,30,31,31,30,31,30,31 };
		if (day_ >= 1 && day_ <= dayInMonth[month - 1])
		{
			day = day_;
		}
		else if (month == 2 && day_ == 29 && isLeap(year))
		{
			day = day_;
		}
	}
	void input()
	{
		do {
			std::cout << "Enter day: ";
			std::cin >> day;
			std::cout << "Enter month: ";
			std::cin >> month;
			std::cout << "Enter year: ";
			std::cin >> year;
			if (day > 0 && day <= 31 && month > 0 && month <= 12)
			{
				std::cout << "Enter date successfull!" << std::endl;
				break;
			}
			else if (month == 2 && day == 29 && isLeap(year))
			{
				std::cout << "Enter date successfull!" << std::endl;
				break;
			}
			/*if (day < 0 || day>31) std::cout << "DAY ERROR\n";
			if (month <= 0 || month > 12) std::cout << "MONTH ERROR \n";
			if (year < 0 || year > CURR_YEAR - 18) std::cout << "YEAR ERROR \n";*/
		} while (true);
	}
	void print()
	{
		std::cout << day << "." << month << "." << year << std::endl;
	}
};