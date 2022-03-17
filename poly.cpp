#include "poly.h"
#include "term.h"
#include "function.h"
#include <iostream>
#include <cassert>
using namespace std;

Poly::Poly(){
    //cout<<"CTOR fired\n";
    size = 1;
    coefs = allocate<double>(size); //creates array of size 1
    *coefs = 0; //stores only 0 into the polynomial
}

Poly::Poly(double *co, int exp){
    copy_list(coefs, co, exp+1);
    size = exp+1;
}

Poly::Poly(const Poly &other){
    coefs = new double[other.size];
    size = other.size;
    copy_list(coefs, other.coefs, other.size);
}

Poly& Poly::operator =(const Poly& other){
    coefs = new double[other.size];
    size = other.size;
    copy_list(coefs, other.coefs, other.size);
    return *this;
}

Poly::~Poly(){
    //cout<<"Destructor fired\n";
    delete[] coefs;
}

Poly operator -(Poly left){ //makes whole polynomial negative
    double* walker = left.coefs;
    for(int i=0; i<left.size; i++){
        *walker = -*walker;
        walker++;
    }
    return left;
}

Poly operator +(Poly left, const Term& t){
    if(left.size<(t._exp+1)){ //if array can't handle term's exponent
        left.coefs = reallocate<double>(left.coefs, left.size, t._exp+1);
    }
    double* walker = left.coefs + t._exp; //walker goes to the nth term
    *walker+=t._coef; //term added to the nth term
    left.fix_size();
    return left;
}

Poly operator *(Poly left, const Term& t){
    Poly result;
    double *walker = left.coefs;
    for(int i=0; i<left.size; i++){
        Term l = {*walker, i};
        result = result + (l*t);
        walker++;
    }
    return result;
}

Poly operator +(const Poly& left, const Poly& right){
    Poly result = left;
    double* walker = right.coefs;
    for(int i=0; i<right.size; i++){
        Term t = {*walker, i};
        result = result + t;
        walker++;
    }
    result.fix_size();
    return result;
}

Poly operator -(const Poly& left, const Poly& right){
    Poly result = -right;
    result = result + left;
    //result.fix_size();
    return result;
}

Poly operator *(const Poly& left, const Poly& right){
    Poly result;
    double* walker = right.coefs;
    for(int i=0; i<right.size; i++){
        if(*walker!=0){ //don't multiply zero terms
            Poly temp = left;
            Term t = {*walker, i};
            temp = temp*t;
            result = result + temp;
        }
        walker++;
    }
    result.fix_size();
    //cout<<endl<<"result"<<result<<endl;
    return result;
}

Poly operator /(const Poly& left, const Poly& right){
    Poly result;
    if((right.size)==1 && (right[0]._coef==0)){ //divide by zero
        return result;
    }
    if(right>left){
        return result;
    }
    if(right==left){
        *(result.coefs) = 1;
        return result;
    }

    Term div = right[right.size-1]; //highest right term
    Poly remainder = left;
    while((remainder>right)||(-remainder)>right){ //as long as remainder can still be divided
        Term last_remain_term = remainder[remainder.size-1]; //highest left/remainder term
        Term get = last_remain_term/div;
        remainder = remainder - (right*get);
        result = result + get;
    }
    return result;
}

Poly operator %(const Poly& left, const Poly& right){
    Poly div = left/right;
    return left - div * right;
}

Term Poly::operator [](int exp) const{
    assert(exp<size);
    double *walker = coefs + exp;
    Term w = {*walker, exp};
    return w;
}

ostream& operator <<(ostream& outs, const Poly& stuff){
    //print_array(stuff.coefs, stuff.size);
    int s = stuff.size-1;
    outs<<"[ ";
    for(int i=s; i>=0; i--){
        Term t = stuff[i];
        if(t._coef!=0){
            if(t._coef>0){
                outs<<"+"<<t<<" ";
            }
            else{
                outs<<t<<" ";
            }
        }
    }
    outs<<"]";
    return outs;
}

istream& operator >>(istream& ins, Poly& p){
    //cout<<"Enter term: ";
    char eq;
    cin>>eq;
    while(eq == '='){
        Term t;
        ins>>t;
        p = p+t;
        cin>>eq;
    }
    return ins;
}

bool operator ==(const Poly& lhs, const Poly& rhs){
    if(lhs.size!=rhs.size){
        return false;
    }
    int x = lhs.size-1;
    for(int i=x; i>=0; i--){
        if(lhs[i]!=rhs[i]){
            return false;
        }
    }
    return true;
}

bool operator !=(const Poly& lhs, const Poly& rhs){
    return !(lhs==rhs);
}

bool operator >(const Poly& lhs, const Poly& rhs){
    if(lhs.size>rhs.size){
        return true;
    }
    else if(lhs.size<rhs.size){
        return false;
    }
    if(lhs==rhs){
        return false;
    }
    int x = lhs.size-1;
    for(int i=x; i>=0; i--){
        if(lhs[i]>rhs[i]){
            return true;
        }
    }
    return false;
}

bool operator <(const Poly& lhs, const Poly& rhs){
    if(lhs.size<rhs.size){
        return true;
    }
    else if(lhs.size>rhs.size){
        return false;
    }
    if(lhs==rhs){
        return false;
    }
    int x = lhs.size-1;
    for(int i=x; i>=0; i--){
        if(lhs[i]<rhs[i]){
            return true;
        }
    }
    return false;
}

void Poly::fix_size(){
    double *walker = coefs + (size-1); //goes to last term
    while(*walker==0 && size>1){
        size--;
        walker--;
    }

}
