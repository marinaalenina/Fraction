#include "Header.h"


void Fraction::reduction() {
    for (int i{ 100 }; i > 1; --i)
        if (m_num % i == 0 && m_den % i == 0) {
            m_num /= i;
            m_den /= i;
        }
    if (m_den < 0) {
        m_den = -(m_den);
        m_num = -(m_num);
    }
    if (m_num < 0 && m_den < 0) {
        m_den = -(m_den);
        m_num = -(m_num);
    }
}


Fraction::operator double() {
    return static_cast<double>(m_num) / m_den;
}
Fraction::operator float() {
    return static_cast<float>(m_num) / m_den;
}


Fraction operator++(const Fraction& a) {
    return a + 1;
}
Fraction operator--(const Fraction& a) {
    return a - 1;
}
Fraction operator-(const Fraction& a) {
    return Fraction(-a.m_num, a.m_den);
}


Fraction operator+(const Fraction& a, const int& b) {
    return Fraction(a.m_num + b * a.m_den, a.m_den);
}
Fraction operator+(const int& a, const Fraction& b) {
    return Fraction(a * b.m_den + b.m_num, b.m_den);
}


Fraction operator-(const Fraction& a, const int& b) {
    return Fraction(a.m_num - b * a.m_den, a.m_den);
}
Fraction operator-(const int& a, const Fraction& b) {
    return Fraction(a * b.m_den - b.m_num, b.m_den);
}


Fraction operator*(const int& a, const Fraction& b) {
    return Fraction(a * b.m_num, b.m_den);
}
Fraction operator*(const Fraction& a, const int& b) {
    return Fraction(b * a.m_num, a.m_den);
}


Fraction operator/(const int& a, const Fraction& b) {
    return Fraction(b.m_num, a * b.m_den);
}
Fraction operator/(const Fraction& a, const int& b) {
    return Fraction(a.m_num, b * a.m_den);
}


Fraction operator+(const Fraction& a, const Fraction& b) {
    return Fraction(a.m_num * b.m_den + b.m_num * a.m_den, a.m_den * b.m_den);
}
Fraction operator-(const Fraction& a, const Fraction& b) {
    return Fraction(a.m_num * b.m_den - b.m_num * a.m_den, a.m_den * b.m_den);
}
Fraction operator*(const Fraction& a, const Fraction& b) {
    return Fraction(a.m_num * b.m_num, a.m_den * b.m_den);
}
Fraction operator/(const Fraction& a, const Fraction& b) {
    return Fraction(a.m_num * b.m_den, a.m_den * b.m_num);
}


Fraction operator+=(const Fraction& a, const Fraction& b) {
    return Fraction((a.m_num * b.m_den) + (b.m_num * a.m_den), (a.m_den * b.m_den));
}
Fraction operator-=(const Fraction& a, const Fraction& b) {
    return Fraction((a.m_num * b.m_den) - (b.m_num * a.m_den), (a.m_den * b.m_den));
}
Fraction operator*=(const Fraction& a, const Fraction& b) {
    return Fraction(a.m_num * b.m_num, a.m_den * b.m_den);
}
Fraction operator/=(const Fraction& a, const Fraction& b) {
    return Fraction(a.m_num * b.m_den, a.m_den * b.m_num);
}


Fraction& Fraction::operator=(const Fraction& f) {
    m_num = f.m_num; m_den = f.m_den;
    return *this;
}


bool Fraction::operator<(const Fraction& f) {
    return ((static_cast<double>(m_num) / m_den) < (static_cast<double>(f.m_num) / f.m_den)) ? true : false;
}
bool Fraction::operator<=(const Fraction& f) {
    return ((static_cast<double>(m_num) / m_den) <= (static_cast<double>(f.m_num) / f.m_den)) ? true : false;
}
bool Fraction::operator>(const Fraction& f) {
    return ((static_cast<double>(m_num) / m_den) > (static_cast<double>(f.m_num) / f.m_den)) ? true : false;
}
bool Fraction::operator>=(const Fraction& f) {
    return ((static_cast<double>(m_num) / m_den) >= (static_cast<double>(f.m_num) / f.m_den)) ? true : false;
}
bool Fraction::operator==(const Fraction& f) {
    return ((static_cast<double>(m_num) / m_den) == (static_cast<double>(f.m_num) / f.m_den)) ? true : false;
}
bool Fraction::operator!=(const Fraction& f) {
    return ((static_cast<double>(m_num) / m_den) != (static_cast<double>(f.m_num) / f.m_den)) ? true : false;
}


std::istream& operator>>(std::istream& in, Fraction& f) {
    char ch{ '/' };
    in >> f.m_num >> ch >> f.m_den;
    return in;
}


std::ostream& operator<<(std::ostream& out, const Fraction& f) {
    (f.m_num == 0 || f.m_num % f.m_den == 0) ? out << f.m_num / f.m_den : out << f.m_num << '/' << f.m_den;
    return out;
}