#include <cstddef>
#include <iostream>
#include <iterator>
#include <stdexcept>

using namespace std;

class R3Vector {
public:
    R3Vector() noexcept = default;
    R3Vector(const R3Vector &) noexcept = default;
    R3Vector(const double rX, const double rY, const double rZ);
    ~R3Vector() noexcept = default;
    R3Vector &operator=(const R3Vector &) noexcept = default;
    std::ostream &print(std::ostream &ostrm) const;
    std::istream &read(std::istream &istrm);
    static constexpr ptrdiff_t dim() { return dimCount_; }
    double &operator[](const ptrdiff_t i);
    const double &operator[](const ptrdiff_t i) const;
    double x() const { return data_[0]; }
    double y() const { return data_[1]; }
    double z() const { return data_[2]; }
    double &rx() { return data_[0]; }
    double &ry() { return data_[1]; }
    double &rz() { return data_[2]; }
    R3Vector operator-();
    R3Vector operator+();
    R3Vector &operator+=(const R3Vector &rhs);
    R3Vector &operator+=(const double rhs);
    R3Vector &operator-=(const R3Vector &rhs);
    R3Vector &operator-=(const double rhs);
    R3Vector &operator*=(const double rhs);
    R3Vector &operator*=(const R3Vector &rhs);
    R3Vector &operator/=(const double rhs);
    double *begin() { return data_; }
    double *end() { return data_ + dimCount_; }
    const double *cbegin() { return data_; }
    const double *cend() { return data_ + dimCount_; }
private:
    static const ptrdiff_t dimCount_{3};
    double data_[dimCount_] = {0.0};
};

R3Vector::R3Vector(const double rX, const double rY, const double rZ)
        : data_{rX, rY, rZ} {
}


std::ostream &R3Vector::print(std::ostream &ostrm) const {
    return ostrm << '(' << x() << ',' << y() << ',' << z() << ')';
}

std::istream &R3Vector::read(std::istream &istrm){
    double a = 0.0;
    char sep;
    this->rx() = a; this->ry() = a; this->rz() = a;
    istrm>>a;
    if (istrm.fail() or istrm.bad()){
        cout<<"its fail now ";
        return istrm;
    }
    this->rx() = a;
    cout<<endl<<" set x with "<<a;
    if (istrm.eof()){
        cout<<"its end now after 1";
        return istrm;
    }
    istrm>>sep;
    if (istrm.fail() or istrm.bad() or sep != ','){
        cout<<"its fail now on sep ";
        istrm.clear(ios_base::badbit);
        return istrm;
    }
    if (istrm.eof()){
        cout<<"its end now after 1";
        return istrm;
    }
    istrm>>a;
    if (istrm.fail() or istrm.bad()){
        cout<<"its fail now ";
        return istrm;
    }
    this->ry() = a;
    cout<<endl<<" set y with "<<a;
    if (istrm.eof()){
        cout<<"its end now after 2";
        return istrm;
    }
    sep = ' ';
    istrm>>sep;
    if (istrm.fail() or istrm.bad() or sep != ','){
        cout<<"its fail now on sep 2 ";
        istrm.clear(ios_base::badbit);
        return istrm;
    }
    if (istrm.eof()){
        cout<<"its end now after 2 and sep";
        return istrm;
    }

    istrm>>a;
    if (istrm.fail() or istrm.bad()){
        cout<<"its fail now  on 3-d";
        return istrm;
    }
    this->rz() = a;
    cout<<endl<<" set z with "<<a;
    if (istrm.eof()){
        cout<<"its end now after 3";
        return istrm;
    }
    return istrm;
}

std::ostream &operator<<(std::ostream &ostrm, const R3Vector &v) {
    return v.print(ostrm);
}

std::istream &operator>>(std::istream &istrm, R3Vector &v) {
    return v.read(istrm);
}

R3Vector R3Vector::operator+() {
    return *this;
}

R3Vector operator+(const R3Vector &lhs, const double rhs) { return R3Vector(lhs) += rhs; }

R3Vector operator+(const double lhs, const R3Vector &rhs) { return R3Vector(rhs) += lhs; }

R3Vector operator+(const R3Vector &lhs, const R3Vector &rhs) { return R3Vector(lhs) += rhs; }

R3Vector &R3Vector::operator+=(const double rhs) {
    for (auto &v : *this) {
        v += rhs;
    }
    return *this;
}

R3Vector &R3Vector::operator+=(const R3Vector &rhs) {
    for (ptrdiff_t i{0}; i != dim(); i += 1) {
        data_[i] += rhs.data_[i];
    }
    return *this;
}


R3Vector R3Vector::operator-() {
    return {-x(), -y(), -z()};
}

R3Vector operator-(const R3Vector &lhs, const double rhs) { return R3Vector(lhs) -= rhs; }

R3Vector operator-(const double lhs,  R3Vector &rhs) { return R3Vector(rhs) -= lhs; }

R3Vector operator-(const R3Vector &lhs, const R3Vector &rhs) { return R3Vector(lhs) -= rhs; }

R3Vector &R3Vector::operator-=(const double rhs) {
    rx() -= rhs;
    ry() -= rhs;
    rz() -= rhs;
    return *this;
}

R3Vector &R3Vector::operator-=(const R3Vector &rhs) {
    rx() -= rhs.x();
    ry() -= rhs.y();
    rz() -= rhs.z();
    return *this;
}


R3Vector operator*(const R3Vector &lhs, const double rhs) { return R3Vector(lhs) *= rhs; }

R3Vector operator*(const double lhs, const R3Vector &rhs) { return R3Vector(rhs) *= lhs; }

R3Vector operator*(const R3Vector &lhs, const R3Vector &rhs) { return R3Vector(lhs) *= lhs; }

R3Vector &R3Vector::operator*=(const R3Vector &rhs) {
    rx() = this->y()*rhs.z() - this->z()*rhs.y();
    ry() = this->z()*rhs.x() - this->x()*rhs.z();
    rz() = this->x()*rhs.y() - this->y()*rhs.x();
    return *this;
}

R3Vector &R3Vector::operator*=(const double rhs) {
    rx() *= rhs;
    ry() *= rhs;
    rz() *= rhs;
    return *this;
}


R3Vector operator/(const R3Vector &lhs, const double rhs) { return R3Vector(lhs) /= rhs; }

R3Vector operator/(const double lhs, const R3Vector &rhs) { return R3Vector(rhs) /= lhs; }

R3Vector &R3Vector::operator/=(const double rhs) {
    for (auto &coord : *this) {
        coord /= rhs;
    }
    return *this;
}



bool operator==(const R3Vector &lhs, const R3Vector &rhs);

bool operator!=(const R3Vector &lhs, const R3Vector &rhs);

std::ostream &operator<<(std::ostream &ostrm, const R3Vector &v);


void testVectorByIndexRead(const R3Vector &v, const ptrdiff_t i) {
    try {
        cout << "read v[" << i << "] -> ";
        cout << v[i];
    }
    catch (const out_of_range &ex) {
        cout << "exception caught " << ex.what();
    }
}

double &R3Vector::operator[](const ptrdiff_t i) {
    if ((i < 0) || (dim() <= i))
        throw out_of_range("Index out of range in R3Vector::operator[]().");
    return data_[i];
}

const double &R3Vector::operator[](const ptrdiff_t i) const {
    if ((i < 0) || (dim() <= i))
        throw out_of_range("Index out of range in R3Vector::operator[]() const.");
    return data_[i];
}



bool operator==(const R3Vector &lhs, const R3Vector &rhs) {
    return (lhs.x() == rhs.x()) and (lhs.y() == rhs.y()) and (lhs.z() == rhs.z());
}

bool operator!=(const R3Vector &lhs, const R3Vector &rhs) {
    return !(lhs==rhs);
}


int main() {
    constexpr ptrdiff_t nSize{R3Vector::dim()};
    cout <<nSize<<" this is dimm"<<endl;
    R3Vector v0;
    cout << "x=" << v0.x() << " y=" << v0.y() << " z=" << v0.z() << endl;
    R3Vector v1{0.2, 0.6, -5.8};
    cout << v1 << endl;
    R3Vector vz{2.4, 4.1, 2.8};
    cout << vz << endl;
    R3Vector vl = v1 + vz;
    cout << vl << endl;
    R3Vector *vec = new R3Vector(50.4,10.3,12.2);
    cout << *vec << endl;
    *vec += 2;
    cout << *vec << endl;
    cout << v1 << endl;
    R3Vector v2{v1};
    cout << v2 << endl;
    v2.rx() *= 2;
    v2.ry() *= 2;
    v2.rz() *= 2;
    cout << v2 << endl;

    for (ptrdiff_t i{-2}; i <= v2.dim(); i += 1) {
        testVectorByIndexRead(v2, i);
        cout << endl;
    }

    double scale{1.2};
    cout << v2 << " * " << scale << " -> " << flush;
    cout << (v2 * scale) << endl;
    cout<<to_string(v2==v1)<<to_string(v2!=v1);

    cout<<"input v2"<<endl;
    cin>>v2;
    cout<<"v2 is "<<v2<<endl;
    return 0;
}

