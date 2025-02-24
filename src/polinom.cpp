
#include<iostream>
#include<string>
#include <cctype>
#include <sstream>
#include "polinom.h"
#include "monom.h"
#include "list.h"
using namespace std;




Polynom::Polynom() {}

Polynom::Polynom(const string& s) {  //3x1y2z1 + 2x2y2z1
    size_t i = 0;
    while (i < s.length()) {
        size_t start = i;
        while (i < s.length() && (isdigit(s[i]) || s[i] == 'x' || s[i] == 'y' || s[i] == 'z')) {
            i++;
        }
        if (start < i) {
            string monomStr = s.substr(start, i - start);
            Monom monom(monomStr);
            p.InsertToTail(monom);
        }
        if (i < s.length() && (s[i] == '+' || s[i] == ' ')) {
            i++; // ���������� ���� +
        }
    }
}

void Polynom::printPol()
{
    p.Print();
    cout << endl;
}

Polynom Polynom::operator+(Polynom& other) 
{
    Polynom res = other;
    Node<Monom>* currA = p.GetFirst();
    Node<Monom>* prevA = nullptr;
    Node<Monom>* currB = res.p.GetFirst();
    Node<Monom>* prevB = nullptr;

    while (currA != nullptr && currB != nullptr) {
        if (currA->data < currB->data) {
            res.p.InsertCurr(prevB, currB, currA->data);
            prevA = currA;
            currA = currA->next;
            if (prevB == nullptr) {
                prevB = res.p.GetFirst();
            }
            else {
                prevB = prevB->next;
            }
        }
        else if (currB->data < currA->data) {
            prevB = currB;
            currB = currB->next;
        }
        else { // ������� ���������, ����� ������� ��
            currB->data = currB->data + currA->data;
            if (currB == nullptr) {
                // ������� currB
                res.p.Delete(currB);
                if (prevB == nullptr) {
                    currB = res.p.GetFirst();
                }
                else {
                    currB = prevB->next;
                }
            }
            else {
                prevB = currB;
                currB = currB->next;
            }
            prevA = currA;
            currA = currA->next;
        }
    }

    // ��������� ���������� ������, ���� ��� ����
    while (currA != nullptr) {
        res.p.InsertCurr(prevB, currB, currA->data);
        prevA = currA;
        currA = currA->next;
        if (prevB == nullptr) {
            prevB = res.p.GetFirst();
        }
        else {
            prevB = prevB->next;
        }
    }

    return res;
}
//������ �������� ���������( ��� ���������������� ������)
/*Polynom operator+(Polynom& other) {  //  "3x1y2z1 + 2x2y2z1" + "3x1y2z1 + 2x2y2z3"
    Polynom res;
    Node<Monom>* currentA = p.getFirst();
    Node<Monom>* currentB = other.p.getFirst();
    // ��������� ��� ������ �� ������� �������� � ���������
    while (currentA != nullptr) {
        res.p.Insert(currentA->value);
        currentA = currentA->next;
    }
    while (currentB != nullptr) {
        int flag = 0;
        // ���������, ��� �� ����� � ������ �� ���������
        Node<Monom>* resCurrent = res.p.getFirst();
        while (resCurrent != nullptr) {
            if (resCurrent->value.getPowX() == currentB->value.getPowX() &&
                resCurrent->value.getPowY() == currentB->value.getPowY() &&
                resCurrent->value.getPowZ() == currentB->value.getPowZ()) {
                // ���� ������, ��������� ������������
                Monom newMonom = resCurrent->value + currentB->value;
                if (newMonom.getCoeff() != 0) {
                    resCurrent->value = newMonom; // ��������� ����� � ����������
                }
                else {
                    //���� ����� ���� 0 �� ������� ���� �����
                    //  ��������!!!!
                }
                flag = 1;
                break;
            }
            resCurrent = resCurrent->next;
        }
        // ���� ����� �� ��� ���������, ��� ��� � ���������
        if (flag!=1) {
            res.p.Insert(currentB->value);
        }
        currentB = currentB->next;
    }
    return res;
}*/
Polynom Polynom::operator*(Monom& m)
{
    Polynom res;
    Node<Monom>* currentA = p.GetFirst();
    while (currentA != nullptr) {
        Monom newMonom = currentA->data * m;
        res.p.InsertToTail(newMonom);
        currentA = currentA->next;
    }
    return res;
}

Polynom operator*(Monom& m, Polynom& oth) {
    return oth * m; 
}

Polynom Polynom::operator*(Polynom& other)
{
    Polynom res;
    Node<Monom>* currentA = p.GetFirst();
    while (currentA != nullptr)
    {
        Polynom newPoly = currentA->data * other;
        res = newPoly;
        
        currentA = currentA->next;
    }
    return res;
}
