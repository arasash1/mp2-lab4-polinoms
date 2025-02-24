#pragma once
#ifndef __Polynom__
#define __Polynom__

#include<iostream>
#include<string>
#include <cctype>
#include <sstream>
#include "monom.h"
#include "list.h"
using namespace std;

/*template <class T>
struct Node
{
    T value;
    Node* next;
    Node(T val1, Node* p) : value(val1), next(p) {}
};

template <class T>
class List {
    Node<T>* first; //first ��-�� �� ������ �����
    Node<T>* last;
public:
    List() : first(nullptr) {}
    ~List() {
        while (first != nullptr) {
            Node<T>* temp = first;
            first = first->next;
            delete temp;
        }
    }
    // ����������� �����������
    List(const List<T>& other) : first(nullptr), last(nullptr) {
        Node<T>* current = other.first;
        while (current != nullptr) {
            Insert(current->value);
            current = current->next;
        }
    }
    // �������� ������������
    List<T>& operator=(const List<T>& other) {
        if (this != &other) { // ��������� ����������������
            // ����������� ������� 
            while (first != nullptr) {
                Node<T>* temp = first;
                first = first->next;
                delete temp;
            }
            // �������������� ��������� ��� ������ ������
            first = nullptr;
            last = nullptr;
            // �������� �������� �� ������� ������
            Node<T>* current = other.first;
            while (current != nullptr) {
                Insert(current->value);
                current = current->next;
            }
        }
        return *this;
    }

    void InsertCurr(Node<T>* prev, Node<T>* curr, T value) {  // ���������� �������� ����� prev � curr
        Node<T>* p = new Node<T>(value, nullptr);
        if (first == nullptr) {  // ���� ������ ����
            first = p;
            last = p;
            return;
        }
        // ���� ����������� � ������
        if (prev == nullptr) {
            p->next = first;
            first = p;
            return;
        }
        // ���� ����������� � �����
        if (curr == nullptr) {
            p->next = nullptr;
            last->next = p;
            last = p;
            return;
        }
        // ��������� ������� - ����������� � ��������, ����� prev � curr
        prev->next = p;
        p->next = curr;
    }

    void DeleteCurr(Node<T>* prev, Node<T>* curr) {  // �������� curr
        Node<T>* p;
        if (first == last) {  // ���� ������ ����
            delete curr;
            first = last = nullptr;
            return;
        }
        // ���� ��������� ������
        if (prev == nullptr) {
            p = first;
            first = first->next;
            delete p;
            return;
        }
        // �������� ������ �������
        if (curr != nullptr) {
            p = curr;
            prev->next = curr->next;
            delete p;
            return;
        }
    }

    void Insert(T value) {  // ���������� �������� � ������������� �������
        Node<T>* p = new Node<T>(value, nullptr);
        if (first == nullptr) {  // ���� ������ ����
            first = p;
            last = p;
            return;
        }
        // ���� ����������� ������� ������ ������� ��������
        if (value < first->value) {
            p->next = first;
            first = p;
            return;
        }
        // ������ ������� ��� �������
        Node<T>* current = first;
        while (current->next != nullptr && current->next->value < value) {
            current = current->next;
        }
        p->next = current->next;
        current->next = p;
        // ��������� ��������� �� ��������� ����
        if (p->next == nullptr) {
            last = p;
        }
    }

    /*void Insert(T val) {  //������ ���������
        Node<T>* p = new Node<T>(val, nullptr);
        if (first == nullptr) { // ���� ������ ����
            first = p;
            last = p;
        }
        else { // ���� ������ �� ����
            last->next = p; // ���������, ��� ������� ��������� ������� ��������� �� �����
            last = p;       // ��������� ��������� �� ��������� �������
        }
    }

    void print() {
        Node<T>* p = first;
        while (p->next != nullptr) { //���� ������ �� ��������
            cout << p->value << " ";
            p = p->next;
        }
        cout << p->value; //������ ������.
    }

    Node<T>* getFirst() {
        return first;
    }
};*/

class Polynom
{
    List<Monom> p;

public:
    Polynom();
    Polynom(const string& s);
    void printPol();
    Polynom operator+(Polynom& other);
    Polynom operator*(Monom& m);
    Polynom operator*(Polynom& other);
    friend Polynom operator*(Monom& m, Polynom& oth);
    //Polynom operator*(Monom& m, Polynom& p);
};
#endif


