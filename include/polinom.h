#pragma once
#include<iostream>
#include<string>
#include <cctype>
#include <sstream>
#include "monom.h"
using namespace std;
template <class T>
struct Node
{
	T value;
	Node* next;
	Node (T val1, Node* p): value(val1),next(p){}
};

template <class T>
class List {
	Node<T> *first; //first ук-ль на первое звено
    Node<T> *last;
public:
    List() : first(nullptr) {}
    ~List() {
        while (first != nullptr) {
            Node<T>* temp = first;
            first = first->next;
            delete temp;
        }
    }
    // Конструктор копирования
    List(const List<T>& other) : first(nullptr), last(nullptr) {
        Node<T>* current = other.first; 
        while (current != nullptr) {
            Insert(current->value); 
            current = current->next;
        }
    }
    // Оператор присваивания
    List<T>& operator=(const List<T>& other) {
        if (this != &other) { // Проверяем самоприсваивание
            // Освобождаем текущие 
            while (first != nullptr) {
                Node<T>* temp = first;
                first = first->next;
                delete temp;
            }
            // Инициализируем указатели для нового списка
            first = nullptr;
            last = nullptr;
            // Копируем элементы из другого списка
            Node<T>* current = other.first; 
            while (current != nullptr) { 
                Insert(current->value); 
                current = current->next; 
            }
        }
        return *this; 
    }

    void Insert(T val) {
        Node<T>* p = new Node<T>(val, nullptr);
        if (first == nullptr) { // Если список пуст
            first = p;  
            last = p;   
        }
        else { // Если список не пуст
            last->next = p; // Указываем, что текущий последний элемент ссылается на новый
            last = p;       // Обновляем указатель на последний элемент
        }
    }

    void print() {
        Node<T>* p = first;
        while (p->next != nullptr) { //пока список не кончится
            cout << p->value << " ";
            p = p->next;
        }
        cout << p->value; //печать послед.
    }

    Node<T>* getFirst() { 
        return first; 
    }
};

class Polynom
{
	List <Monom> p;
public:
    Polynom() {}
     
    Polynom(const string& s) {  //3x1y2z1 + 3x1y2z1
        size_t i = 0;
        while (i < s.length()) {
            size_t start = i;
            while (i < s.length() && (isdigit(s[i]) || s[i] == 'x' || s[i] == 'y' || s[i] == 'z')) {
                i++;
            }
            if (start < i) {
                string monomStr = s.substr(start, i - start);
                Monom monom(monomStr);
                p.Insert(monom);
            }
            if (i < s.length() && (s[i] == '+' || s[i] == ' ')) {
                i++; // пропускаем знак +
            }
        }
    }

    void printPol() {
        p.print();
        cout << endl;
    }

    Polynom operator+(Polynom& other)  {  //  "3x1y2z1 + 2x2y2z1" + "3x1y2z1 + 2x2y2z3"
        Polynom res;
        Node<Monom>* currentA = p.getFirst();
        Node<Monom>* currentB = other.p.getFirst();
        // Добавляем все мономы из первого полинома в результат
        while (currentA != nullptr) {
            res.p.Insert(currentA->value);
            currentA = currentA->next;
        }
        while (currentB != nullptr) {
            int flag = 0;
            // Проверяем, сущ ли моном с такими же степенями
            Node<Monom>* resCurrent = res.p.getFirst();
            while (resCurrent != nullptr) {
                if (resCurrent->value.getPowX() == currentB->value.getPowX() &&
                    resCurrent->value.getPowY() == currentB->value.getPowY() &&
                    resCurrent->value.getPowZ() == currentB->value.getPowZ()) {
                    // Если найден, суммируем коэффициенты
                    Monom newMonom = resCurrent->value + currentB->value;
                    if (newMonom.getCoeff() != 0) {
                        resCurrent->value = newMonom; // Обновляем моном в результате
                    }
                    else {
                        //если коэфф стал 0 то удалить этот моном
                        //  ДОПИСАТЬ!!!!
                    }
                    flag = 1;
                    break;
                }
                resCurrent = resCurrent->next;
            }
            // Если моном не был объединен, доб его в результат
            if (flag!=1) {
                res.p.Insert(currentB->value);
            }
            currentB = currentB->next;
        }
        return res;
    }
    Polynom operator*(Monom& m) {
        Polynom res;
        Node<Monom>* currentA = p.getFirst();
        while (currentA != nullptr) {
            Monom newMonom = currentA->value * m;
            res.p.Insert(newMonom);
            currentA = currentA->next;
        }
        return res;
    }
    
    Polynom operator*(Polynom& other) {
        Polynom res;
        Node<Monom>* currentA = p.getFirst();
        while (currentA != nullptr) {
            Polynom newPoly = other * currentA->value;
            res = res + newPoly; // Добавляем результат в результирующий полином
            
            currentA = currentA->next;
            
        }
        return res;
    }
};












/*
    Polynom operator*(Polynom& other) {
        Polynom res;
        Node<Monom>* currentA = p.getFirst();
        Node<Monom>* currentB = other.p.getFirst();
        while (currentA != nullptr) {
            while (currentB != nullptr) {
                Monom newMonom = currentA->value * currentB->value;
                // Проверяем, есть ли уже моном с такими степенями в результирующем полиноме
                int flag = 0;
                Node<Monom>* resCurrent = res.p.getFirst();
                while (resCurrent != nullptr) {
                    if (resCurrent->value.getPowX() == newMonom.getPowX() &&
                        resCurrent->value.getPowY() == newMonom.getPowY() &&
                        resCurrent->value.getPowZ() == newMonom.getPowZ()) {
                        // Если найден, суммируем коэффициенты
                        Monom newMonom = resCurrent->value + currentB->value;
                        flag = 1;
                        break;
                    }
                    resCurrent = resCurrent->next;
                }
                // Если моном не найден, добавляем в результат
                if (flag != 1) {
                    res.p.Insert(newMonom);
                }
                currentB = currentB->next;
            }
        }
        return res;
    }*/