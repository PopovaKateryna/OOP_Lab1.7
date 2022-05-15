#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "Time.h"

using namespace std;

class Bill
{
private:
	string surname;
	string cellnumb;
	double taryf;
	double znyzhka;
	Time timebeg;
	Time timeend;
	double sumforpay;
public:

	string GetSurname() const { return surname; };
	void SetSurname(string v) { this->surname = v; };

	string GetCellnumb() const { return cellnumb; };
	void SetCellnumb(string v) { this->cellnumb = v; }

	double GetTaryf() const { return taryf; };
	void SetTaryf(double);

	double GetZnyzhka() const { return znyzhka; };
	void SetZnyzhka(double);

	double GetSumforpay() const { return sumforpay; };
	void SetSumforpay(double);

	void Read();
	void Display();
	void Init(string, string, double, double);
	string toString() const;

	double Sum_For_Pay(Time T1, Time T2);
};
