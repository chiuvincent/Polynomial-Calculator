#ifndef TERM_H
#define TERM_H
#include <iostream>

using namespace std;

struct Term{
    double _coef;
    int _exp;

    friend Term operator +(const Term& left, const Term& right);
    friend Term operator -(const Term& left, const Term& right);
    friend Term operator *(const Term& left, const Term& right);
    friend Term operator /(const Term& left, const Term& right);

    friend Term operator -(Term t); //negative sign

    friend ostream& operator <<(ostream& outs, const Term& stuff);
    friend istream& operator >>(istream& ins, Term& stuff);

    friend bool operator ==(const Term& lhs, const Term& rhs);
    friend bool operator !=(const Term& lhs, const Term& rhs);
    friend bool operator >(const Term& lhs, const Term& rhs);
    friend bool operator <(const Term& lhs, const Term& rhs);

};

#endif // TERM_H
