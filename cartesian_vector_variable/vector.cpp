#include "vector.hh"
#include "config.h"


Vector::Vector(size_t N) {
    coords_ = std::make_unique<value[]>(N);
    for (int i = 0; i < N; i++) {
        coords_[i] = 0;
    }
    size_ = N;
}

Vector::Vector(const Vector& v) {
    coords_ = std::make_unique<value[]>(v.size());
    for (size_t i = 0; i < v.size(); ++i)
    {
        coords_[i] = v[i];
    }
    size_ = v.size();
}

Vector& Vector::operator=(const Vector& v) {
    coords_ = std::make_unique<value[]>(v.size());
    for (size_t i = 0; i < v.size(); i++) {
        coords_[i] = v[i];
    }
    size_ = v.size();
    return *this;
}


Vector::Vector(std::initializer_list<value> l)
{
    size_ = l.size();
    coords_ = std::make_unique<value[]>(size_);
    size_t index = 0;
    std::initializer_list<value>::iterator it;
    for (it = l.begin(); it != l.end(); ++it)
    {
        coords_[index++] = *it;
    }
}

size_t Vector::size() const {
    return size_;
}

Vector& Vector::operator+=(const Vector& rhs)
{
    if (rhs.size() != size()) {
        throw std::runtime_error("Incompatible size");
    }
    for (size_t i = 0; i < rhs.size(); i++) {
        coords_[i] += rhs[i];
    }
    return *this;
}

Vector& Vector::operator-=(const Vector& rhs)
{
    if (rhs.size() != size()) {
        throw std::runtime_error("Incompatible size");
    }
    for (size_t i = 0; i < rhs.size(); i++) {
        coords_[i] -= rhs[i];
    }
    return *this;

}

Vector Vector::operator+(const Vector& rhs) const
{
    auto u = Vector(rhs.size());
    for (size_t i = 0; i < rhs.size(); i++) {
        u[i] = rhs[i] + (*this)[i];
    }
    return u;
}

Vector Vector::operator+(value v) const {
    for (int i = 0; i < size(); i++) {
        coords_[i] += v;
    }
    return *this;
}


Vector operator+(const value& s, const Vector& v) {
    Vector w = Vector(v.size());
    for (int i = 0; i < v.size(); i++) {
        w[i] = v[i] + s;
    }
    return w;
}

value Vector::operator*(const Vector& rhs) const
{
    if (size_ != rhs.size()) {
        throw std::runtime_error("Incompatible size");
    }
    value n = 0;
    for (size_t i = 0; i < rhs.size(); i++) {
        n += rhs[i] * (*this)[i];
    }
    return n;
}

Vector Vector::operator*(value v) const {
    for (int i = 0; i < size_; i++) {
        coords_[i] *= v;
    }
    return *this;
}


value Vector::operator[](size_t index) const
{
    if (index > size()) {
        throw std::runtime_error("Incompatible size");
    }
    return coords_[index];
}

value& Vector::operator[](size_t index)
{
    if (index > size()) {
        throw std::runtime_error("Incompatible size");
    }
    return coords_[index];
}

std::ostream& operator<<(std::ostream& os, const Vector& rhs)
{
    os << "{";

    for (size_t i = 0; i < rhs.size(); i++)
    {
        os << rhs[i] << (i < rhs.size() - 1 ? "," : "");
    }
    os << "}";
    return os;
}

Vector operator*(const value& s, const Vector&v)
{
    auto u = Vector(v.size());
    for (size_t i = 0; i < v.size(); i++) {
        u[i] = v[i] * s;
    }
    return u;
}

Vector& Vector::operator+=(value v)
{
    for (size_t i = 0; i < size_; i++) {
        this[i] += v; 
    }
    return *this;
}

Vector& Vector::operator*=(value v)
{
    for (size_t i = 0; i < size_; i++) {
        this[i] *= v; 
    }
    return *this;
}