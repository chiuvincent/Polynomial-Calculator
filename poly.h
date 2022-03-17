#ifndef POLY_H
#define POLY_H
#include "term.h"


class Poly
{
public:
    Poly();
    Poly(double* co, int exp);

    //big 3
    Poly(const Poly& other);
    Poly& operator =(const Poly& other);
    ~Poly();

    friend Poly operator -(Poly left);

    friend Poly operator +(Poly left, const Term& t);
    friend Poly operator *(Poly left, const Term& t);

    friend Poly operator +(const Poly& left, const Poly& right);
    friend Poly operator -(const Poly& left, const Poly& right);

    friend Poly operator *(const Poly& left, const Poly& right);
    friend Poly operator /(const Poly& left, const Poly& right);
    friend Poly operator %(const Poly& left, const Poly& right);

    Term operator [](int exp) const;
    friend ostream& operator <<(ostream& outs, const Poly& stuff);
    friend istream& operator >>(istream& ins, Poly& p);

    friend bool operator ==(const Poly& lhs, const Poly& rhs);
    friend bool operator !=(const Poly& lhs, const Poly& rhs);
    friend bool operator >(const Poly& lhs, const Poly& rhs);
    friend bool operator <(const Poly& lhs, const Poly& rhs);

    int getSize() const {return size;}

private:
    void fix_size();
    double* coefs;
    int size;
};

#endif // POLY_H
