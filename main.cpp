/* Author: Vincent Chiu
 * Project: Polynomial calculator
 * Purpose: Able to add, subtract, multiply, and divide polynomials
 * and terms, also able to find remainder, and many other functions
 */
#include <iostream>
#include "term.h"
#include "poly.h"

using namespace std;

void test_add(const Poly& p, const Poly& q);
void test_minus(const Poly& p, const Poly& q);
void test_mult(const Poly& p, const Poly& q);
void test_div(const Poly& p, const Poly& q);

int main()
{
    Term a = {1, 1};
    cout<<a<<endl;
//    Poly p;
//    Poly q;
//    //input
//    cout<<"Enter polynomial:\n";
//    cin>>p;
//    cout<<"Enter polynomial:\n";
//    cin>>q;
//    //output
//    cout<<"P: "<<p<<endl;
//    cout<<"Q: "<<q<<endl;
//    //tests
//    cout<<"\n\tp + q\n";
//    test_add(p,q);
//    cout<<"\n\tq + p\n";
//    test_add(q,p);
//    cout<<"\n\tp - q\n";
//    test_minus(p,q);
//    cout<<"\n\tq - p\n";
//    test_minus(q,p);
//    cout<<"\n\tp * q\n";
//    test_mult(p,q);
//    cout<<"\n\tq * p\n";
//    test_mult(q,p);
//    cout<<"\n\tp / q\n";
//    test_div(p,q);
//    cout<<"\n\tq / p\n";
//    test_div(q,p);

//    cout<<"\n======================================\n";
    return 0;

}


void test_add(const Poly& p, const Poly& q){
    Poly r = p + q;
    cout<<p<<" + "<<q<<endl;
    cout<<"      = "<<r;
    if(r - q == p){
        cout<<"VERIFIED"<<endl;
    }
    else{
        cout<<endl<<"   ***VERIFICATION FAILED"<<endl;
    }
}

void test_minus(const Poly& p, const Poly& q){
    Poly r = p - q;
    cout<<p<<" - "<<q<<endl;
    cout<<"      = "<<r;
    if(r + q == p){
        cout<<"VERIFIED"<<endl;
    }
    else{
        cout<<endl<<"   ***VERIFICATION FAILED"<<endl;
    }
}

void test_mult(const Poly& p, const Poly& q){
    Poly r = p * q;
    cout<<p<<" * "<<q<<endl;
    cout<<"      = "<<r;
    if(r / q == p){
        cout<<"VERIFIED"<<endl;
    }
    else{
        cout<<endl<<"   ***VERIFICATION FAILED"<<endl;
    }
}

void test_div(const Poly& p, const Poly& q){
    Poly r = p / q;
    cout<<p<<" / "<<q<<endl;
    cout<<"      = "<<r;
    cout<<"  rem = "<<p % q<<"  ";
    //if r = p / q then r * q + p % q should be equal to p:
    if(r * q + p % q == p){
        cout<<"VERIFIED"<<endl;
    }
    else{
        cout<<endl<<"   ***VERIFICATION FAILED"<<endl;
        cout<<"   r * q: "<<r * q<<endl;
        cout<<"   p % q: "<<p % q<<endl;
        cout<<"   r * q + p % q: "<<r * q + p % q<<"=/="<<p<<endl;
    }
}
