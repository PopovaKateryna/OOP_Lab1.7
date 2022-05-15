#pragma once
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Time
{
private:
	unsigned int hour, minute, second;
public:
	unsigned int GetHour() const { return hour; };
	unsigned int GetMinute() const { return minute; };
	unsigned int GetSecond() const { return second; };

	void SetHour(unsigned int);
	void SetMinute(unsigned int);
	void SetSecond(unsigned int);

	void Init_time(unsigned int, unsigned int, unsigned int);
	void Read();
	void Display();
	string toString() const;

	friend Time SubstractSeconds(Time, unsigned int);

	friend Time Difference(Time, unsigned int);

	friend unsigned int Difference(Time, Time);

	friend unsigned int ToSeconds(Time);

	friend unsigned int ToMinutes(Time);

	friend bool IsEqual(Time, Time);

	friend bool IsNotEqual(Time, Time);

    friend bool IsEarlierThan(Time, Time);

	friend bool IsEarlierThanOrEq(Time, Time);

	friend bool IsLaterThan(Time, Time);

	friend bool IsLaterThanOrEq(Time, Time);
};
