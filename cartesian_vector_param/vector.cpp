
#include <ostream>
#include <initializer_list>
#include <cassert>
#include <string>
#include <cstring>
#include <iterator>
#include <iostream>
#include <vector>
#include <initializer_list>
#include "vector.hh"

Vector::Vector()
{
    size_ = NDIM;
    for (size_t i = 0; i < NDIM; ++i)
    {
        coords_[i] = 0;
    }
}


Vector::Vector(std::initializer_list<value> l)
{
    size_ = l.size();
    size_t index = 0;
    std::initializer_list<value>::iterator it;
    for (it = l.begin(); it != l.end(); ++it)
    {
        coords_[index++] = *it;
    }
}

size_t Vector::getSize() const {
    return size_;
}

Vector &Vector::operator+=(const Vector &rhs)
{
    assert(rhs.getSize() <= this->getSize());
    for (size_t i = 0; i < rhs.getSize(); i++) {
        coords_[i] += rhs[i];
    }
    return *this;
}

Vector &Vector::operator-=(const Vector &rhs)
{
    assert(rhs.getSize() <= this->getSize());
    for (size_t i = 0; i < rhs.getSize(); i++) {
        coords_[i] -= rhs[i];
    }
    return *this;

}

Vector Vector::operator+(const Vector &rhs)
{
    auto u = Vector();
    for (size_t i = 0; i < rhs.getSize(); i++) {
        u[i] = rhs[i] + (*this)[i];
    }
    return u;
}

Vector Vector::operator-(const Vector &rhs)
{
    auto u = Vector();
    for (size_t i = 0; i < rhs.getSize(); i++) {
        u[i] = (*this)[i] - rhs[i]; // doute
    }
    return u;
}

value Vector::operator*(const Vector &rhs)
{
    value n = 0;
    for (size_t i = 0; i < rhs.getSize(); i++) {
        n += rhs[i] * (*this)[i];
    }
    return n;
}


value Vector::operator[](size_t index) const
{
    assert(index < this->getSize());
    return coords_[index];
}

value &Vector::operator[](size_t index)
{
    assert(index < this->getSize());
    return coords_[index];
}

std::ostream &operator<<(std::ostream &os, const Vector &rhs)
{
    os << "{";
    
    for (size_t i = 0; i < rhs.getSize(); i++)
    {
        os << rhs[i] << (i < rhs.getSize() - 1 ? "," : "");
    }
    os << "}";
    return os;
}

Vector operator*(const Vector &rhs, value lambda)
{
    auto u = Vector();
    for (size_t i = 0; i < rhs.getSize(); i++) {
        u[i] = rhs[i] * lambda;
    }
    return u;
}

Vector operator+=(Vector &rhs, value lambda)
{
    for (size_t i = 0; i < rhs.getSize(); i++) {
        rhs[i] += lambda; // doute
    }
    return rhs;
}

Vector operator*=(Vector &rhs, value lambda)
{
    for (size_t i = 0; i < rhs.getSize(); i++) {
        rhs[i] *= lambda; // doute
    }
    return rhs;
}