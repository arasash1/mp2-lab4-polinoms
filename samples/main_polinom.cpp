#include "polinom.h"
#include "monom.h"
#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	Polynom poly1("3x1y2z1 + 2x2y2z1");
	Polynom poly2("3x1y2z1 + 2x2y2z3");
	Monom mon1(10, 2, 4, 6);
	cout << "Полином 1:" << endl;
	poly1.printPol();
	cout << "Полином 2:" << endl;
	poly2.printPol();
	Polynom res = poly1 + poly2;
	cout << "Сумма полиномов: " << endl;
	res.printPol();
	Polynom ress = mon1 * poly1;
	cout << "Умножение полинома на моном: " << endl;
	ress.printPol();
	Polynom resss = poly1 * poly2;
	cout << "Умножение полинома на полином: " << endl;
	resss.printPol();
}

//если коэффициент ноль то удаляем моном из списка