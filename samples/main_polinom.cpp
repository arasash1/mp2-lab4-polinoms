#include "polinom.h"
#include "monom.h"
#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	Polynom poly1("3x1y2z1 + 2x2y2z1");
	Polynom poly2("3x1y2z1 + 2x2y2z3");
	poly1.printPol();
	poly1.printPol();
	Polynom res = poly1 + poly2;
	cout << "Сумма полиномов: " << endl;
	res.printPol();
	Polynom ress = poly1 * poly2;
	cout << "Умножение полиномов: " << endl;
	ress.printPol();
}

//если коэффициент ноль то удаляем моном из списка