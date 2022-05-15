#include "Time.h"
#include <iostream>

void Time::SetHour(unsigned int value)
{
	if (value > 23 || value < 0)
		value = 0;
	this->hour = value;
}

void Time::SetMinute(unsigned int value)
{
	if (value > 59 || value < 0)
		value = 0;
	this->minute = value;
}

void Time::SetSecond(unsigned int value)
{
	if (value > 59 || value < 0)
		value = 0;
	this->second = value;
}


void Time::Init_time(unsigned int hour, unsigned int minute, unsigned int second)
{
	SetHour(hour);
	SetMinute(minute);
	SetSecond(second);
}

void Time::Read()
{
	unsigned int h, m, s;
	do {
		cout << " Enter hour: "; cin >> h;
	} while (h > 23 || h < 0);

	do {
		cout << " Enter minute: "; cin >> m;
	} while (m > 59 || m < 0);

	do {
		cout << " Enter second: "; cin >> s;
	} while (s > 59 || s < 0);

	Init_time(h, m, s);
}

void Time::Display() {
	cout << endl << toString() << endl;
}

string Time::toString() const {
	stringstream sout;
	sout << " " << hour << ":" << minute << ":" << second;
	return sout.str();
}

Time SubstractSeconds(Time a, unsigned int b)
{
	unsigned int substr = b;

	a.hour -= trunc(substr / 3600.);
	a.minute -= trunc(substr % 3600 / 60.);
	a.second -= substr % 60;

	if (a.second >= 60 || a.second < 0)
	{
		a.minute += a.second / 60;
		a.second %= 60;
		if (a.second < 0)
		{
			a.minute--;
			a.second = 60 + a.second;
		}
	}

	if (a.minute >= 60 || a.minute < 0)
	{
		a.hour += a.minute / 60;
		a.minute = a.minute % 60;
		if (a.minute < 0)
		{
			a.hour--;
			a.minute = 60 + a.minute;
		}
	}

	if (a.hour >= 24 || a.hour < 0)
		a.hour = (a.hour < 0 ? 24 : 0) + a.hour % 24;

	return a;
}

Time Difference(Time a, unsigned int b)
{
	unsigned int seconds = b;

	unsigned int hm = trunc(seconds / 3600.);
	a.hour += trunc(seconds / 3600.);
	a.minute += trunc(seconds % 3600 / 60.);
	a.second += seconds % 60;

	if (a.second >= 60 || a.second < 0)
	{
		a.minute += a.second / 60;
		a.second %= 60;
		if (a.second < 0)
		{
			a.minute--;
			a.second = 60 + a.second;
		}
	}

	if (a.minute >= 60 || a.minute < 0)
	{
		a.hour += a.minute / 60;
		a.minute = a.minute % 60;
		if (a.minute < 0)
		{
			a.hour--;
			a.minute = 60 + a.minute;
		}
	}

	if (a.hour >= 24 || a.hour < 0)
		a.hour = (a.hour < 0 ? 24 : 0) + a.hour % 24;

	return a;
}

unsigned int ToSeconds(Time b)
{
	unsigned int t;
	t = b.hour * 3600 + b.minute * 60 + b.second;
	return t;
}

unsigned int ToMinutes(Time b)
{
	unsigned int t;
	if (b.second < 1)
	{
		t = b.hour * 60 + b.minute;
	}
	if (b.second > 0)
	{
		t = b.hour * 60 + b.minute + 1;
	}
	return t;
}

unsigned int Difference(Time T1, Time T2)
{
	return ToSeconds(T2) - ToSeconds(T1);
}

bool IsEqual(Time t1, Time t2)
{
	return t1.hour == t2.hour && t1.minute == t2.minute && t1.second == t2.second;
}

bool IsNotEqual(Time t1, Time t2)
{
	return !IsEqual(t1, t2);
}

bool IsEarlierThan(Time t1, Time t2)
{
	return t1.hour < t2.hour || t1.hour == t2.hour && t1.minute < t2.minute || t1.hour == t2.hour && t1.minute == t2.minute && t1.second < t2.second;
}

bool IsEarlierThanOrEq(Time t1, Time t2)
{
	return IsEarlierThan(t1, t2) || IsEqual(t1, t2);
}

bool IsLaterThan(Time t1, Time t2)
{
	return t1.hour > t2.hour || t1.hour == t2.hour && t1.minute > t2.minute || t1.hour == t2.hour && t1.minute == t2.minute && t1.second > t2.second;
}

bool IsLaterThanOrEq(Time t1, Time t2)
{
	return IsLaterThan(t1, t2) || IsEqual(t1, t2);
}