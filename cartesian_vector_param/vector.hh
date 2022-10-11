
#pragma once

#include <ostream>
#include <initializer_list>
#include <cassert>

#include "config.h"



class Vector
{
public:
// DO NOT CHANGE THIS
    Vector(const Vector&) = default;
    Vector& operator=(const Vector&) = default;
    ~Vector() = default;
//

// Add suitable constructors
    Vector();
    Vector(std::initializer_list<value> l);
    // possibly more

// Public Member functions here
    Vector& operator+=(const Vector& rhs);
    Vector& operator-=(const Vector& rhs);
    Vector operator+(const Vector& rhs);
    value operator*(const Vector& rhs);
    Vector operator-(const Vector& rhs);
    value operator[](size_t index) const;
    value& operator[](size_t index);
    // More to go
    size_t getSize() const;
private:
    value coords_[NDIM];
    size_t size_;
// Private Member functions here (if necessary)

// Member variables are ALWAYS private, and they go here

};

// Nonmember function operators go here

std::ostream& operator<<(std::ostream& os, const Vector& rhs);
Vector operator*(const Vector& rhs, value lambda);
Vector operator+=(Vector& rhs, value lambda);
Vector operator*=(Vector& rhs, value lambda);