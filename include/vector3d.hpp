#pragma once

#include "vector.hpp"

typedef Vector<double, 3> Vector3;

template<>
Vector3 Vector3::operator * (const Matrix &tmp) const;

template<>
Vector3 Vector3::operator * (const Vector3 &tmp) const;

template<>
Vector3 Vector3::operator + (const Vector3 &tmp) const;

template<>
Vector3 Vector3::operator - (const Vector3 &tmp) const;

template<>
Vector3 Vector3::operator / (const Vector3 &tmp) const;

template<>

