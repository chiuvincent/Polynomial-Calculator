#include "term.h"
#include <iostream>
#include <cassert>

using namespace std;

Term operator +(const Term& left, const Term& right){
    assert(left._exp == right._exp);
    double coef = left._coef + right._coef;
    int exp = left._exp;
    Term sum = {coef, exp};
    return sum;
}

Term operator -(const Term& left, const Term& right){
    assert(left._exp == right._exp);
    double coef = left._coef - right._coef;
    int exp = left._exp;
    Term sum = {coef, exp};
    return sum;
}

Term operator *(const Term& left, const Term& right){
    double coef = left._coef * right._coef;
    int exp = left._exp + right._exp;
    Term sum = {coef, exp};
    return sum;
}

Term operator /(const Term& left, const Term& right){
    double coef = left._coef / right._coef;
    int exp = left._exp - right._exp;
    Term sum = {coef, exp};
    return sum;
}

Term operator -(Term t){
    t._coef = -t._coef;
    return t;
}

ostream& operator <<(ostream& outs, const Term& stuff){
    if(!(stuff._coef==1&&stuff._exp>0)){ //don't print 1x^2 for x^2
       outs<<stuff._coef;
    }
    if(stuff._exp!=0){ //doesn't print out 5x^0 for 5
        outs<<"x";
    }
    if(!(stuff._exp==1||stuff._exp==0)){
        outs<<"^"<<stuff._exp;
    }
    return outs;
}

istream& operator >>(istream& ins, Term& stuff){
    double coef;
    char x;
    char power;
    int exp;
    ins>>coef>>x>>power>>exp;
    assert(x=='x'&&power=='^');
    stuff._coef = coef;
    stuff._exp = exp;
    return ins;
}

bool operator ==(const Term& lhs, const Term& rhs){
    return (lhs._coef==rhs._coef)&&(lhs._exp==lhs._exp);
}

bool operator !=(const Term& lhs, const Term& rhs){
    return !(lhs==rhs);
}

bool operator >(const Term& lhs, const Term& rhs){
    if(lhs._exp>rhs._exp){
        return true;
    }
    else if(lhs._coef>rhs._coef){
        return true;
    }
    return false;
}

bool operator <(const Term& lhs, const Term& rhs){
    if(lhs._exp<rhs._exp){
        return true;
    }
    else if(lhs._coef<rhs._coef){
        return true;
    }
    return false;
}
