//
// Created by ansaev on 21.09.15.
//
#include <cmath>
#include <string>
#include <iostream>
using namespace std;
class ComplexNumber{
private:
    double x;
    double i;
public:

    ComplexNumber(double x,double i = 0.0){
        this->x = x;
        this->i = i;
    }

    ~ComplexNumber(){
    }

    double getReal() const {
        return x;
    }

    void setReal(double x) {
        this->x = x;
    }

    double getIm() const {
        return i;
    }

    void setIm(double i) {
        this->i = i;
    }

    string toString() const{
        return to_string(this->x) + " + " + to_string(this->i) + " i" ;
    }

    ComplexNumber operator+(ComplexNumber &other ) {
        return ComplexNumber( x + other.getReal(), i + other.getIm() );
    }

    ComplexNumber operator-(ComplexNumber &other ) {
        return ComplexNumber( x - other.getReal(), i - other.getIm() );
    }

    ComplexNumber operator-=(ComplexNumber &other ) {
        this->x -= other.getReal();
        this->i -= other.getIm();
        return *this;
    }
    ComplexNumber operator+=(ComplexNumber &other ) {
        this->x += other.getReal();
        this->i += other.getIm();
        return *this;
    }

    ComplexNumber operator*=(ComplexNumber &other ) {
        this->x = x * other.getReal() - i * other.getIm();
        this->i = x * other.getIm() + i * other.getReal();
        return *this;
    }

    ComplexNumber operator/=(ComplexNumber &other ) {
        double del = (pow(other.getReal(),2) + pow(other.getIm(),2));
        this->x = (x* other.getReal() + i* other.getIm()) / del;
        this->i = (i * other.getReal() - x * other.getIm()) / del;
        return *this;
    }

    ComplexNumber operator-() {
        this->x = -this->x;
        this->i = -this->i;
        return *this;
    }

    ComplexNumber operator+() {
        return *this;
    }

    ComplexNumber operator*(ComplexNumber &other ) {
        return ComplexNumber( x * other.getReal() - i * other.getIm(), x * other.getIm() + i * other.getReal());
    }

    ComplexNumber operator/(ComplexNumber &other ) {
        double del = (pow(other.getReal(),2) + pow(other.getIm(),2));
        double a = (x* other.getReal() + i* other.getIm()) / del;
        double b = (i * other.getReal() - x * other.getIm()) / del;
        return ComplexNumber( a, b);
    }

    bool operator ==(ComplexNumber &other){
        return ((x == other.getReal()) and (i == other.getIm()));
    }

    bool operator !=(ComplexNumber &other){
        return ((x != other.getReal()) or (i != other.getIm()));
    }
    ComplexNumber operator--() {
        this->x--;
        return *this;
    }
    ComplexNumber operator++() {
        this->x++;
        return *this;
    }

   friend ostream& operator<<(ostream& os, const ComplexNumber& num){
       os<<num.toString();
       return os;
   }
    friend istream& operator>>(istream &is, ComplexNumber &num){
        is >> num.x >> num.i;
        return is;
    }

};

