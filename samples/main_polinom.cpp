#include "polinom.h"
#include "monom.h"
#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	Polynom poly1("3x2y2z2 + 10x5y5z5");
	Polynom poly2("0x1y2z1 + 0x2y2z3");
	Monom mon1(10, 2, 3, 30);
	cout << "������� 1:" << endl;
	poly1.printPol();
	cout << "������� 2:" << endl;
	poly2.printPol();
	Polynom res = poly1 + poly2;
	cout << "����� ���������: " << endl;
	res.printPol();
	Polynom ress = mon1 * poly1;
	cout << "��������� �������� �� �����: " << endl;
	ress.printPol();
	Polynom resss = poly1 * poly2;
	cout << "��������� �������� �� �������: " << endl;
	resss.printPol();
}

//���� ����������� ���� �� ������� ����� �� ������