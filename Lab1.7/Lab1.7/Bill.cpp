#include "Bill.h"

void Bill::SetTaryf(double v)
{
	this->taryf = v;
}

void Bill::SetZnyzhka(double v)
{
	if (v > 100 || v < 0)
	{
		v = 0;
	}
	this->znyzhka = v;
}

void Bill::SetSumforpay(double v)
{
	this->sumforpay = v;
}

void Bill::Init(string surname, string cellnumb, double taryf, double znyzhka)
{
	SetSurname(surname);
	SetCellnumb(cellnumb);
	SetTaryf(taryf);
	SetZnyzhka(znyzhka);
}

void Bill::Read()
{
	string surname;
	cout << " Enter surname: "; cin >> surname;
	string cellnumb;
	cout << " Enter phone number: "; cin >> cellnumb;

	double taryf, znyzhka;
	cout << " Enter taryf per minute: "; cin >> taryf;
	do {
		cout << " Enter discount, %: "; cin >> znyzhka;
	} while (znyzhka > 100 || znyzhka < 0);



	Init(surname, cellnumb, taryf, znyzhka);
}

string Bill::toString() const
{
	stringstream sout;
	sout << endl << " Surname: " << surname << endl;
	sout << " Phone number: " << cellnumb << endl;
	sout << " Taryf per minute: " << taryf << "UAH" << endl;
	sout << " Discount: " << znyzhka << "%" << endl;

	return sout.str();
}

void Bill::Display()
{
	cout << toString() << endl;
}


double Bill::Sum_For_Pay(Time T1, Time T2)
{
	unsigned int t(Difference(T1, T2)/60.);
	return t * taryf - (t * taryf) * (znyzhka / 100);
}