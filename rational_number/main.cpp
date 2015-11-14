#include <iostream>
#include <stdexcept>
#include <sstream>

using namespace std;
class Rational {
public:
    Rational() noexcept: Rational{0, 1} {
    }

    Rational(const int num) noexcept: Rational{num, 1} {
    }

    Rational(const int num, const int den) : num_{num}, den_{den} {
        if (0 == den_) {
            throw domain_error("zero denominator in Rational");
        }
        normalize();
    }

    Rational(const Rational &rhs) noexcept = default;

    Rational &operator=
            (const Rational &rhs) = default;

    Rational &operator=
            (Rational &&rhs) = default;

    int num() const {
        return num_;
    }

    int den() const {
        return den_;
    }

    Rational operator-() const {
        return Rational{-num_, den_};
    }

    Rational &operator+=
            (const Rational &rhs) {
        num_ = num_ * rhs.den_ + den_ * rhs.num_;
        den_ *= rhs.den_;
        normalize();
        return *this;
    }

    Rational &operator-=
            (const Rational &rhs) {
        num_ = num_ * rhs.den_ - den_ * rhs.num_;
        den_ *= rhs.den_;
        normalize();
        return *this;
    }

    Rational &operator*=
            (const Rational &rhs) {
        num_ *= rhs.num_;
        den_ *= rhs.den_;
        normalize();
        return *this;
    }

    Rational &operator/=
            (const Rational &rhs) {
        num_ *= rhs.den_;
        den_ *= rhs.num_;
        normalize();
        return *this;
    }

    bool operator==
            (const Rational &rhs) const {
        return (num_ == rhs.num_) && (den_ == rhs.den_);
    }

    bool operator!=
            (const Rational &rhs) const {
        return !operator==(rhs);
    }

    bool operator<
            (const Rational &rhs) const {
        return (num_ * rhs.den_) < (rhs.num_ * den_);
    }

    bool operator<=
            (const Rational &rhs) const {
        return (num_ * rhs.den_) <= (rhs.num_ * den_);
    }

    bool operator>
            (const Rational &rhs) const {
        return !operator<=
                (rhs);
    }

    bool operator>=
            (const Rational &rhs) const {
        return !operator<
                (rhs);;
    }


    ostream &writeToTxt(std::ostream &ostrm) const {
        ostrm << num_ << '/' << den_;
        return ostrm;
    }

    istream &readFromTxt(std::istream &istrm) {
        char sep;
        int a,b;

        istrm>>a;
        if (istrm.fail() or istrm.bad()){
            cout<<"its fail now ";
            num_ = 1; den_ = 1;
            return istrm;
        }
        num_ = a;

        if (istrm.eof()){
            den_ = 1;
            cout<<"its end now after 1";
            return istrm;
        }
        istrm>>sep;
        if (istrm.fail() or istrm.bad() or sep !='/'){
            cout<<"its fail now on sep ";
            den_ = 1;
            istrm.clear(ios_base::badbit);
            return istrm;
        }

        if (istrm.eof()){
            den_ = 1;
            cout<<"its end now after 1";
            return istrm;
        }

        istrm>>b;
        if (istrm.fail() or istrm.bad()){
            cout<<"its fail now on b ";
            den_ = 1;
            return istrm;
        }

        den_ = b;
        normalize();
        return istrm;
    }

private:
    bool normalize() {
        if (0 == den_ ){
            return false;
        }
        if (0 == num_) {
            den_ = 1;
            return true;
        }
        if (den_ < 0) {
            num_ *= -1;
            den_ *= -1;
            // TODO: упрощение до несократимой дроби
        }
        int num_abs = abs(num_);
        int den_abs = abs(den_);
        for (int i = num_abs < den_abs ? num_abs : den_abs; i > 1; i--){
            if(num_abs%i == 0 and den_abs%i == 0){
                num_ /= i;
                den_ /= i;
                break;
            }
        }
        return true;
    }

private:
    int num_; ///< числитель, целое
    int den_; ///< знаменатель, натуральное
};

Rational operator+(const Rational &lhs, const Rational &rhs) {
    Rational summ{lhs};
    summ += rhs;
    return summ;
}

Rational operator-(const Rational &lhs, const Rational &rhs) {
    Rational summ{lhs};
    summ -= rhs;
    return summ;
}

Rational operator*(const Rational &lhs, const Rational &rhs) {
    Rational summ{lhs};
    summ *= rhs;
    return summ;
}

Rational operator/
        (const Rational &lhs, const Rational &rhs) {
    Rational summ{lhs};
    summ /= rhs;
    return summ;
}


std::ostream &operator<<(std::ostream &ostrm, const Rational &r) {
    return r.writeToTxt(ostrm);
}

std::istream &operator>>(std::istream &istrm, Rational &r) {
    return r.readFromTxt(istrm);
}


void testRationalConstructor(const int num, const int den) {
    cout << "Rational{" << num << ',' << den << "} -> " << flush;
    cout << Rational{num, den} << endl;
}

void testRationalOpPlus(const Rational &lhs, const Rational &rhs) {
    cout << lhs << " + " << rhs << " -> " << (lhs + rhs) << endl;
}

void testRationalOpMinus(const Rational &lhs, const Rational &rhs) {
    cout << lhs << " - " << rhs << " -> " << (lhs - rhs) << endl;
}

void testRationalOpMult(const Rational &lhs, const Rational &rhs) {
    cout << lhs << " * " << rhs << " -> " << (lhs * rhs) << endl;
}

void testRationalOpDiv(const Rational &lhs, const Rational &rhs) {
    cout << lhs << " / " << rhs << " -> " << (lhs / rhs) << endl;
}

void testRationalOpCmpEq(const Rational &lhs, const Rational &rhs) {
    cout << lhs << " == " << rhs << " -> " << boolalpha << (lhs == rhs) << endl;
}

void testRationalOpCmpNotEq(const Rational &lhs, const Rational &rhs) {
    cout << lhs << " != " << rhs << " -> " << boolalpha << (lhs != rhs) << endl;
}

void testRationalOpCmpLess(const Rational &lhs, const Rational &rhs) {
    cout << lhs << " < " << rhs << " -> " << boolalpha << (lhs < rhs) << endl;
}

// TODO: test for operator<= operator> operator>=

void testReadFromStream(const string &s) {
    istringstream istrm(s);
    Rational r;
    istrm >> r;
    cout << "Read from text \"" << s << "\" -> " << r << ", stream state is " << boolalpha <<!!istrm << endl;
}

int main() {
    cout << "Rational{} -> " << Rational{} << endl;
    Rational *r02 = new Rational(2);
    cout << "Rational{} -> " << *r02 << endl;
    testRationalConstructor(1, 2);
    testRationalConstructor(-1, 2);
    testRationalConstructor(1, -2);
    testRationalConstructor(-1, -2);
    try {
        testRationalConstructor(5, 0);
    }
    catch (domain_error &e) {
        cout << "exception caught (" << e.what() << ')' << endl;
    }
    Rational *r03 = new Rational(-1, 5);
    Rational *r04 = new Rational(2, -3);

    cout << "\nTest Rational operator+" << endl;
    testRationalOpPlus(*r03, -*r03);
    testRationalOpPlus(*r03, *r04);

    cout << "\nTest Rational operator-" << endl;
    testRationalOpMinus(*r03, *r03);
    testRationalOpMinus(*r03, *r04);

    cout << "\nTest Rational operator*" << endl;
    testRationalOpMult(*r03, *r03);
    testRationalOpMult(*r03, *r04);

    cout << "\nTest Rational operator/" << endl;
    testRationalOpDiv(*r03, *r03);
    testRationalOpDiv(*r03, *r04);

    cout << "\nTest Rational operator==" << endl;
    testRationalOpCmpEq(*r03, *r03);
    testRationalOpCmpEq(*r03, -*r03);
    testRationalOpCmpEq(*r03, *r04);

    cout << "\nTest Rational operator!=" << endl;
    testRationalOpCmpNotEq(*r03, *r03);
    testRationalOpCmpNotEq(*r03, -*r03);
    testRationalOpCmpNotEq(*r03, *r04);

    cout << "\nTest Rational operator<" << endl;
    testRationalOpCmpLess(*r03, *r03);
    testRationalOpCmpLess(*r03, -*r03);
    testRationalOpCmpLess(*r03, *r04);

// TODO: test for operator<= operator> operator>=

    cout << "\nTest Rational read from stream" << endl;
    testReadFromStream("");
    testReadFromStream("a");
    testReadFromStream("sd");
    testReadFromStream("215");
    testReadFromStream("215/10");
    testReadFromStream("215/25");
    testReadFromStream("215/63");
    testReadFromStream("21/-56");
    testReadFromStream("1");
    testReadFromStream("1/2");
    testReadFromStream("-4/5");
    testReadFromStream("3/-5");
    testReadFromStream("-5/-2");
    testReadFromStream("-5.0/-2");

    Rational *k1 = new Rational(-20,10);
    cout << "\nTest -20,10 after normalize: " << *k1 <<endl;
    Rational *k2 = new Rational(3);
    Rational *k3 = new Rational(1);
    cout << "\nTest 3 : " << *k2 <<endl;

    delete(k1, k2, k3, r02, r03, r04);
    return 0;
}