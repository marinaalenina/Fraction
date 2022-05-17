#pragma once
#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>

class Fraction {
private:
    int m_num, m_den;
    void reduction();
public:

    Fraction(int num = 0, int den = 1) : m_num{ num }, m_den{ den } { reduction(); }      // Конструктор с параметрами по умолчанию
    Fraction(const Fraction& f) : m_num{ f.m_num }, m_den{ f.m_den } { reduction(); }     // Конструктор копирования

    operator double();
    operator float();

    //Прототипы арифметических операторов//

    friend Fraction operator++(const Fraction& a);
    friend Fraction operator--(const Fraction& a);
    friend Fraction operator-(const Fraction& a);

    friend Fraction operator+(const Fraction& a, const int& b);
    friend Fraction operator+(const int& a, const Fraction& b);

    friend Fraction operator-(const Fraction& a, const int& b);
    friend Fraction operator-(const int& a, const Fraction& b);

    friend Fraction operator*(const int& a, const Fraction& b);
    friend Fraction operator*(const Fraction& a, const int& b);

    friend Fraction operator/(const int& a, const Fraction& b);
    friend Fraction operator/(const Fraction& a, const int& b);

    friend Fraction operator+(const Fraction& a, const Fraction& b);
    friend Fraction operator-(const Fraction& a, const Fraction& b);
    friend Fraction operator*(const Fraction& a, const Fraction& b);
    friend Fraction operator/(const Fraction& a, const Fraction& b);

    friend Fraction operator+=(const Fraction& a, const Fraction& b);
    friend Fraction operator-=(const Fraction& a, const Fraction& b);
    friend Fraction operator*=(const Fraction& a, const Fraction& b);
    friend Fraction operator/=(const Fraction& a, const Fraction& b);

    Fraction& operator=(const Fraction& f); 

    //Прототипы операторов сравнения//

    bool operator<(const Fraction& f);
    bool operator<=(const Fraction& f);
    bool operator>(const Fraction& f);
    bool operator>=(const Fraction& f);
    bool operator==(const Fraction& f);
    bool operator!=(const Fraction& f);

    friend std::istream& operator>>(std::istream& in, Fraction& f);
    friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
};
#endif